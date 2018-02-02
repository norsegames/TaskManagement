// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TaskManagementEditorStyle.h"
#include "Styling/SlateTypes.h"
#include "Engine/GameEngine.h"
#include "Styling/SlateStyleRegistry.h"

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( FTaskManagementEditorStyle::PluginsContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( FTaskManagementEditorStyle::PluginsContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( FTaskManagementEditorStyle::PluginsContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( FTaskManagementEditorStyle::PluginsContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( FTaskManagementEditorStyle::PluginsContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )

FString FTaskManagementEditorStyle::PluginsContentDir(const ANSICHAR* RelativePath, const TCHAR* Extension)
{
	return ( FPaths::ProjectContentDir() / RelativePath ) + Extension;
}

FString FTaskManagementEditorStyle::PluginsContentDir(const WIDECHAR* RelativePath, const TCHAR* Extension)
{
	return ( FPaths::ProjectContentDir() / RelativePath ) + Extension;
}

FString FTaskManagementEditorStyle::PluginsContentDir(const FString& RelativePath, const TCHAR* Extension)
{
	return ( FPaths::ProjectContentDir() / RelativePath ) + Extension;
}

FString FTaskManagementEditorStyle::PluginsContentDir(const ANSICHAR* RelativePath)
{
	return ( FPaths::ProjectContentDir() / RelativePath );
}

FString FTaskManagementEditorStyle::PluginsContentDir(const WIDECHAR* RelativePath)
{
	return ( FPaths::ProjectContentDir() / RelativePath );
}

FString FTaskManagementEditorStyle::PluginsContentDir(const FString& RelativePath)
{
	return ( FPaths::ProjectContentDir() / RelativePath );
}

TSharedPtr< FTaskManagementEditorStyle::FStyle > FTaskManagementEditorStyle::StyleInstance;

FTaskManagementEditorStyle::FStyle::FStyle()
	: FSlateStyleSet("TaskManagementStyle")
{

}

void FTaskManagementEditorStyle::FStyle::Initialize()
{


	StyleInstance->SetContentRoot(FPaths::EngineContentDir() / TEXT("Editor/Slate"));
	StyleInstance->SetCoreContentRoot(FPaths::EngineContentDir() / TEXT("Slate"));

	const FLinearColor SelectionColor(0.728f, 0.364f, 0.003f);
	const FLinearColor SelectionColor_Pressed(0.701f, 0.225f, 0.003f);

	const FCheckBoxStyle ToggleButtonStyle = FCheckBoxStyle()
		.SetCheckBoxType(ESlateCheckBoxType::ToggleButton)
		.SetUncheckedImage(BOX_BRUSH("Common/RoundedSelection_16x", 4.0f / 16.0f, FLinearColor(1, 1, 1, 0.1f)))
		.SetUncheckedHoveredImage(BOX_BRUSH("Common/RoundedSelection_16x", 4.0f / 16.0f, SelectionColor))
		.SetUncheckedPressedImage(BOX_BRUSH("Common/RoundedSelection_16x", 4.0f / 16.0f, SelectionColor_Pressed))
		.SetCheckedImage(BOX_BRUSH("Common/RoundedSelection_16x", 4.0f / 16.0f, SelectionColor_Pressed))
		.SetCheckedHoveredImage(BOX_BRUSH("Common/RoundedSelection_16x", 4.0f / 16.0f, SelectionColor))
		.SetCheckedPressedImage(BOX_BRUSH("Common/RoundedSelection_16x", 4.0f / 16.0f, SelectionColor_Pressed));
	StyleInstance->Set("ToggleButtonCheckbox", ToggleButtonStyle);

	const FVector2D Icon16x16(16.0f, 16.0f);
	const FVector2D Icon24x24(24.0f, 24.0f);

	const FButtonStyle CommonButtonStyle = FButtonStyle()
		.SetNormal(BOX_BRUSH("Common/RoundedSelection_16x", 4.0f / 16.0f, FLinearColor(1, 1, 1, 0.1f)))
		.SetHovered(BOX_BRUSH("Common/RoundedSelection_16x", 4.0f / 16.0f, SelectionColor))
		.SetPressed(BOX_BRUSH("Common/RoundedSelection_16x", 4.0f / 16.0f, SelectionColor_Pressed));
	StyleInstance->Set("CommonButton", CommonButtonStyle);

	StyleInstance->Set("ToolBar.Background", new BOX_BRUSH("Common/GroupBorder", FMargin(4.0f / 16.0f)));
	StyleInstance->Set("CollisionAnalyzer.TabIcon", new IMAGE_BRUSH("Icons/icon_tab_CollisionAnalyser_16x", Icon16x16));
	StyleInstance->Set("CollisionAnalyzer.Record", new IMAGE_BRUSH("Icons/CA_Record", Icon24x24));
	StyleInstance->Set("CollisionAnalyzer.Stop", new IMAGE_BRUSH("Icons/CA_Stop", Icon24x24));
	StyleInstance->Set("CollisionAnalyzer.ShowRecent", new IMAGE_BRUSH("Icons/CA_ShowRecent", Icon24x24));
	StyleInstance->Set("CollisionAnalyzer.Group", new IMAGE_BRUSH("Icons/CA_Group", FVector2D(10, 18)));
	StyleInstance->Set("CollisionAnalyzer.GroupBackground", new BOX_BRUSH("Icons/CA_GroupBackground", FMargin(4.f / 16.f)));
	StyleInstance->Set("CollisionAnalyzer.Save", new IMAGE_BRUSH("Icons/icon_file_save_40x", Icon24x24));
	StyleInstance->Set("CollisionAnalyzer.Load", new IMAGE_BRUSH("Icons/icon_file_open_40x", Icon24x24));
	StyleInstance->Set("Menu.Background", new BOX_BRUSH("Old/Menu_Background", FMargin(8.0f / 64.0f)));
	StyleInstance->Set("BoldFont", TTF_FONT("Fonts/Roboto-Bold", 9));
	StyleInstance->Set("BoldFont", OTF_FONT("Fonts/Roboto-Bold", 9));

	FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance.Get());
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

void FTaskManagementEditorStyle::Initialize()
{
	StyleInstance = MakeShareable(new FTaskManagementEditorStyle::FStyle);
	StyleInstance->Initialize();
}

void FTaskManagementEditorStyle::Shutdown()
{
	if (StyleInstance.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance.Get());
		ensure(StyleInstance.IsUnique());
		StyleInstance.Reset();
	}
}

TSharedPtr< ISlateStyle > FTaskManagementEditorStyle::Get()
{
	return StyleInstance;
}
