// Fill out your copyright notice in the Description page of Project Settings.

#include "BondsII.h"
#include "BondsAIController.h"


#include "BondsAIController.h"
#include "BondsAICharacter.h"

/* AI Specific includes */
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


ABondsAIController::ABondsAIController(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	/* Match with the AI/ZombieBlackboard */
	PatrolLocationKeyName = "PatrolLocation";
	CurrentWaypointKeyName = "CurrentWaypoint";
	BotTypeKeyName = "BotType";
	TargetEnemyKeyName = "TargetEnemy";

	/* Initializes PlayerState so we can assign a team index to AI */
	bWantsPlayerState = true;
}


void ABondsAIController::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);

	//ABondsAICharacter* Bot = Cast<ABondsAICharacter>(InPawn);
	//if (Bot)
	//{
	//	if (Bot->BehaviorTree->BlackboardAsset)
	//	{
	//		BlackboardComp->InitializeBlackboard(*ZombieBot->BehaviorTree->BlackboardAsset);

	//		/* Make sure the Blackboard has the type of bot we possessed */
	//		//SetBlackboardBotType(ZombieBot->BotType);
	//	}

	//	BehaviorComp->StartTree(*Bot->BehaviorTree);
	//}
}


void ABondsAIController::UnPossess()
{
	Super::UnPossess();

	/* Stop any behavior running as we no longer have a pawn to control */
	BehaviorComp->StopTree();
}


//void ABondsAIController::SetWaypoint(ASBotWaypoint* NewWaypoint)
//{
//	if (BlackboardComp)
//	{
//		BlackboardComp->SetValueAsObject(CurrentWaypointKeyName, NewWaypoint);
//	}
//}


//void ABondsAIController::SetTargetEnemy(APawn* NewTarget)
//{
//	if (BlackboardComp)
//	{
//		BlackboardComp->SetValueAsObject(TargetEnemyKeyName, NewTarget);
//	}
//}


//ASBotWaypoint* ABondsAIController::GetWaypoint()
//{
//	if (BlackboardComp)
//	{
//		return Cast<ASBotWaypoint>(BlackboardComp->GetValueAsObject(CurrentWaypointKeyName));
//	}
//
//	return nullptr;
//}


//ASBaseCharacter* ABondsAIController::GetTargetEnemy()
//{
//	if (BlackboardComp)
//	{
//		return Cast<ASBaseCharacter>(BlackboardComp->GetValueAsObject(TargetEnemyKeyName));
//	}
//
//	return nullptr;
//}


//void ABondsAIController::SetBlackboardBotType(EBotBehaviorType NewType)
//{
//	if (BlackboardComp)
//	{
//		BlackboardComp->SetValueAsEnum(BotTypeKeyName, (uint8)NewType);
//	}
//}