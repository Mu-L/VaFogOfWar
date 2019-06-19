// Copyright 2019 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "VaFogTypes.h"

#include "Components/ActorComponent.h"

#include "VaFogAgentComponent.generated.h"

UCLASS(ClassGroup = (VAFogOfWar), editinlinenew, meta = (BlueprintSpawnableComponent))
class VAFOGOFWAR_API UVaFogAgentComponent : public UActorComponent
{
	GENERATED_UCLASS_BODY()

public:
	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;

public:
	/** Fog layer we're scouting by the agent */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EVaFogLayerChannel TargetChannel;

	/** Agent vision radius in cm */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 VisionRadius;
};
