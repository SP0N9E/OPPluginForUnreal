// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "LoadDLLBPLibrary.h"
#include "queue"

/**
 * 
 */
class LOADDLL_API SimpleThread : public FRunnable
{
public:
	// Constuctor & Destructor
	SimpleThread();
	SimpleThread(std::queue<OPDatum>& dataBuffer, OPDatum& currentData, OPState& opState);
	~SimpleThread();
	// Singleton实例，可通过StaticAccessor在任何时候访问该线程，如果是Active的
	static SimpleThread* Runnable;
	static SimpleThread* JoyInit();
	static SimpleThread* JoyInit(std::queue<OPDatum>& dataBuffer, OPDatum& currentData, OPState& opState);

	static void Shutdown();

private:
	

	// Begin FRunnable interface
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override;

	// End FRunnable interface
	class FRunnableThread* RunnableThread;
	// Stop the thread? Uses Thread Safe Counter
	FThreadSafeCounter StopTaskCounter;
	void EnsureCompletion();
	
};
