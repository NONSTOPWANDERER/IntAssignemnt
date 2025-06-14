// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "MyProject2Character.h"
#include "AIController.h"
UBTTask_Attack::UBTTask_Attack()
{
    NodeName="Attack";
}
EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp,NodeMemory);
    if(!OwnerComp.GetAIOwner()) return EBTNodeResult::Failed;
    AMyProject2Character* Character=Cast<AMyProject2Character>(OwnerComp.GetAIOwner()->GetPawn());
    if(!Character) return EBTNodeResult::Failed;
    Character->Attack();
    return EBTNodeResult::Succeeded;
}