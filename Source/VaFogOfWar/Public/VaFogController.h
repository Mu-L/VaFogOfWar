// Copyright 2019 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "VaFogTypes.h"

#include "Engine/Engine.h"

#include "VaFogController.generated.h"

class AVaFogBoundsVolume;
class UVaFogAgentComponent;
class UVaFogLayerComponent;

UCLASS()
class VAFOGOFWAR_API UVaFogController : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	/** Direct access to fog controller */
	static UVaFogController* Get(UObject* WorldContextObject, EGetWorldErrorMode ErrorMode = EGetWorldErrorMode::Assert);

	void OnFogBoundsAdded(AVaFogBoundsVolume* InFogVolume);
	void OnFogBoundsRemoved(AVaFogBoundsVolume* InFogVolume);

	void OnFogLayerAdded(UVaFogLayerComponent* InFogLayer);
	void OnFogLayerRemoved(UVaFogLayerComponent* InFogLayer);

	void OnFogAgentAdded(UVaFogAgentComponent* InFogAgent);
	void OnFogAgentRemoved(UVaFogAgentComponent* InFogAgent);

	AVaFogBoundsVolume* GetFogVolume() const;

	/** Get fog layer by its channel */
	UVaFogLayerComponent* GetFogLayer(EVaFogLayerChannel LayerChannel) const;

private:
	/** Currently only one fog volume at time is supported */
	UPROPERTY()
	AVaFogBoundsVolume* FogVolume;

	/** Registered fog layers */
	UPROPERTY()
	TArray<UVaFogLayerComponent*> FogLayers;
};
