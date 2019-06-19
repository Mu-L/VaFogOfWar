// Copyright 2019 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"

#include "VaFogBoundsVolume.generated.h"

UCLASS()
class VAFOGOFWAR_API AVaFogBoundsVolume : public AVolume
{
	GENERATED_UCLASS_BODY()

	//~ Begin AActor Interface
	virtual void PostRegisterAllComponents() override;
	virtual void PostUnregisterAllComponents() override;
	//~ End AActor Interface

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	/** Convert world location of vector to layer one */
	FIntPoint
	TransformWorldToLayer(const FVector& AgentLocation) const;

private:
	int32 CachedFogLayerResolution;

	/** World to layer transform */
	FTransform VolumeTransform;
};
