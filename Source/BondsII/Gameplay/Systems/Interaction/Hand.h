// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "Hand.generated.h"

UENUM(BlueprintType)		
enum class EHandState : uint8
{
	Idle,//the hand is unused and free
	Open,//the hand is open, waiting to grab something (in general, when the player is pressing the button to use it)
	Busy,//the hand is locked by a transition/a process/an action, for instance the transition between open and grab
	Grab//the hand is holding something or is gripping something
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BONDSII_API UHand : public USceneComponent
{
	GENERATED_BODY()
	
	EHandState CurrentState;
	class UInputComponent* HandInputComponent;

	
public:	
	// Sets default values for this component's properties
	UHand();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hand, meta = (AllowPrivateAccess = "true"))
	int Endurance;


	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//The state of the hand
	UFUNCTION(BlueprintPure, Category=Hand)
	FORCEINLINE EHandState GetCurrentState() { return CurrentState; }

	UFUNCTION(BlueprintCallable, Category = Hand)
	void SetCurrentState(EHandState NewState);

	UFUNCTION(BlueprintCallable, Category = Hand)
	void StartUse();

	UFUNCTION(BlueprintCallable, Category = Hand)
	void EndUse();
};
