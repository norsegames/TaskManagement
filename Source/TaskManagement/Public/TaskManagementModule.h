// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

//General Log
#include "TaskManagementLog.h"

/**
 * Task Management Mode Module Interface
 */
class ITaskManagementModule : public IModuleInterface
{
public:

#if WITH_EDITOR
	/** IModuleInterface implementation */
	//virtual void StartupModule() override;
	//virtual void ShutdownModule() override;
#endif
};