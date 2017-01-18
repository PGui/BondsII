// Fill out your copyright notice in the Description page of Project Settings.

#include "BondsII.h"
#include "Hand.h"


// Sets default values for this component's properties
UHand::UHand()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	
	
	static const FName InputComponentName(TEXT("HandInputComponent"));
	HandInputComponent = NewObject<UInputComponent>(this, InputComponentName);
	

	Endurance = 10;
	// ...
}


// Called when the game starts
void UHand::BeginPlay()
{
	Super::BeginPlay();
	
	check(HandInputComponent);

	
	HandInputComponent->BindAction("UseHandLeft", IE_Pressed, this, &UHand::StartUse);
	HandInputComponent->BindAction("UseHandRight", IE_Pressed, this, &UHand::StartUse);
	HandInputComponent->BindAction("UseHandLeft", IE_Released, this, &UHand::EndUse);
	HandInputComponent->BindAction("UseHandRight", IE_Released, this, &UHand::EndUse);
	
	// ...
	
}


// Called every frame
void UHand::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UHand::SetCurrentState(EHandState NewState)
{

	CurrentState = NewState;

}

void UHand::StartUse()
{

	switch (CurrentState)
	{
		case EHandState::Idle:
			CurrentState = EHandState::Open;
			UE_LOG(BondsLog, Warning, TEXT("Now used"));
			break;

		case EHandState::Grab:
		case EHandState::Busy:
		case EHandState::Open:
		default:
			break;
	}
	
}

void UHand::EndUse()
{

	switch (CurrentState)
	{
	case EHandState::Idle:
		break;

	case EHandState::Grab:
	case EHandState::Busy:
	case EHandState::Open:
	default:
		CurrentState = EHandState::Idle;
		UE_LOG(BondsLog, Warning, TEXT("Now unused"));
		break;
	}
	

}