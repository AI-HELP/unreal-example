// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "GenericAIHelp.h"

typedef TSharedPtr<FGenericAIHelp> FAIHelpPtr;

class FAIHelpForUEModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static FAIHelpForUEModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FAIHelpForUEModule>("AIHelpForUE");
	}

	static bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("AIHelpForUE");
	}

	FAIHelpPtr GetAIHelp();

private:
	FAIHelpPtr AIHelp;
};
