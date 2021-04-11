// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleThread.h"
#include "HAL/RunnableThread.h"
#include "OPWrapper.h"

template <typename T>
void ClearT(std::queue<T>& q)
{
	std::queue<T> empty;
	swap(empty, q);
}

SimpleThread* SimpleThread::Runnable = NULL;

SimpleThread::SimpleThread() : StopTaskCounter(0)
{
	UE_LOG(LogTemp, Warning, TEXT("SimpleThread first constructor"));
	RunnableThread = FRunnableThread::Create(this, TEXT("SimpleRunnableThread"));
}

SimpleThread::SimpleThread(std::queue<OPDatum>& dataBuffer, OPDatum & currentData, OPState& opState) : StopTaskCounter(0)
{
	UE_LOG(LogTemp, Warning, TEXT("SimpleThread second constructor"));
	RunnableThread = FRunnableThread::Create(this, TEXT("SimpleRunnableThread"));
	// Thread end, clean up
	//Clear(dataBuffer);
	OPDatum newCurrentData;
	currentData = newCurrentData;

	// Change state
	opState = OPState::Ready;
}

SimpleThread::~SimpleThread()
{
	delete RunnableThread;
	RunnableThread = NULL;
}

SimpleThread * SimpleThread::JoyInit()
{
	UE_LOG(LogTemp, Warning, TEXT("JoyInit"));
	if (!Runnable && FPlatformProcess::SupportsMultithreading())
	{
		Runnable = new SimpleThread();
	}
	return Runnable;
}

SimpleThread * SimpleThread::JoyInit(std::queue<OPDatum>& dataBuffer, OPDatum & currentData, OPState& opState)
{
	UE_LOG(LogTemp, Warning, TEXT("JoyInit parameter"));
	if (!Runnable && FPlatformProcess::SupportsMultithreading())
	{
		Runnable = new SimpleThread(dataBuffer, currentData, opState);
	}
	return Runnable;
}

void SimpleThread::Shutdown()
{
	if (Runnable)
	{
		Runnable->EnsureCompletion();
		delete Runnable;
		Runnable = NULL;
	}
}

bool SimpleThread::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("SimpleThread Init"));
	return true;
}

uint32 SimpleThread::Run()
{
	UE_LOG(LogTemp, Warning, TEXT("SimpleThread Run"));
 	while (StopTaskCounter.GetValue() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("ULoadDLLBPLibrary::M_OPRun() success"));
		ULoadDLLBPLibrary::M_OPRun();

		ClearT(OPWrapper::dataBuffer);
		OPDatum newCurrentData;
		OPWrapper::currentData = newCurrentData;
		OPWrapper::opState = OPState::Ready;
	}
	return 0;
	//return uint32();
}

void SimpleThread::Stop()
{
	UE_LOG(LogTemp, Warning, TEXT("SimpleThread Stop"));
	StopTaskCounter.Increment();
}

void SimpleThread::Exit()
{
	UE_LOG(LogTemp, Warning, TEXT("SimpleThread Exit"));
}

void SimpleThread::EnsureCompletion()
{
	Stop();
	RunnableThread->WaitForCompletion();
}
