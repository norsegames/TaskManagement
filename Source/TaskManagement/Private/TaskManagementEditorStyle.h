// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/ISlateStyle.h"
#include "Styling/SlateStyle.h"

class FTaskManagementEditorStyle
{
	public:

		// Declares the visual style set and registers it with the Slate Style Registry.
		class FStyle : public FSlateStyleSet
		{
			public:
				FStyle();

				void Initialize();
		};

		// Initializes the value of MenuStyleInstance and registers it with the Slate Style Registry.
		static void Initialize();
 
		// Unregisters the Slate Style Set and then resets the MenuStyleInstance pointer.
		static void Shutdown();
 
	private:

		static TSharedPtr<class ISlateStyle> Get();

		static TSharedPtr< FTaskManagementEditorStyle::FStyle > StyleInstance;

		// virtual
		static FString PluginsContentDir(const ANSICHAR* RelativePath, const TCHAR* Extension);
		static FString PluginsContentDir(const WIDECHAR* RelativePath, const TCHAR* Extension);
		static FString PluginsContentDir(const FString& RelativePath, const TCHAR* Extension);
		static FString PluginsContentDir(const ANSICHAR* RelativePath);
		static FString PluginsContentDir(const WIDECHAR* RelativePath);
		static FString PluginsContentDir(const FString& RelativePath);

};