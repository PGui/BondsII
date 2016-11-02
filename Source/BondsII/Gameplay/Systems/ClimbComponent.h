// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "ClimbComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BONDSII_API UClimbComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	class PhysicConstraint* PhysicConstraintLeft, *PhysicConstraintRight;

		
	
	// Sets default values for this component's properties
	UClimbComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:


	void Release();
	

		
	
};
