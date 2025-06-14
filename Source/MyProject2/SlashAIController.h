// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SlashAIController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ASlashAIController : public AAIController
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	bool IsDead() const;
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;	
};
