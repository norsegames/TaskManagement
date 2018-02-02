// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TaskManagerEdMode.h"
#include "TaskManagerEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"

//Slate Dependencies

// Classes

// VR Editor

const FEditorModeID FTaskManagerEdMode::EM_TaskManager = TEXT("EM_TaskManagerEdMode");

FTaskManagerEdMode::FTaskManagerEdMode()
{

}

FTaskManagerEdMode::~FTaskManagerEdMode()
{

}

void FTaskManagerEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FTaskManagerEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FTaskManagerEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FTaskManagerEdMode::UsesToolkits() const
{
	return true;
}