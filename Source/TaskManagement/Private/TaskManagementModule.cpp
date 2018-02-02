// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TaskManagementModule.h"
#include "Modules/ModuleManager.h"
#include "Textures/SlateIcon.h"
#include "EditorStyleSet.h"
#include "Editor/UnrealEdEngine.h"
#include "TaskManagerEdMode.h"
#include "TaskManagementEditorStyle.h"

/**
 * Task Management Mode module
 */
class FTaskManagementModule : public ITaskManagementModule
{
public:

	/**
	 * Called right after the module DLL has been loaded and the module object has been created
	 */
	virtual void StartupModule() override
	{
		// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
		FEditorModeRegistry::Get().RegisterMode<FTaskManagerEdMode>(
			FTaskManagerEdMode::EM_TaskManager,
			NSLOCTEXT("EditorModes", "TaskManagerMode", "TaskManager"),
			//LOCTEXT("TaskManagerEdModeName", "TaskManagerEdMode Test"),
			FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.TaskManagerMode", "LevelEditor.TaskManagerMode.Small"),
			true/*, 400 */
		);
	}


	/**
	 * Called before the module is unloaded, right before the module object is destroyed.
	 */
	virtual void ShutdownModule() override
	{
		// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
		// we call this function before unloading the module.
		FEditorModeRegistry::Get().UnregisterMode(FTaskManagerEdMode::EM_TaskManager);
	}
};

IMPLEMENT_MODULE(FTaskManagementModule, TaskManagement);
DEFINE_LOG_CATEGORY(TaskManagementLogger);