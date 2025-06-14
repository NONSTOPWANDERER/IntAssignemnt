// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sword.generated.h"

UCLASS()
class MYPROJECT2_API ASword : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASword();
	void Attack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere)
	USoundBase* HitSound;
	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactEffect;
	UPROPERTY(EditAnywhere)
	USoundBase* ImpactSound;
	UPROPERTY(EditAnywhere)
	float MaxRange=500;
	UPROPERTY(EditAnywhere)
	float TraceRadius = 30.0f;
	UPROPERTY(EditAnywhere)
	float Damage=10;
	bool SwordTrace(FHitResult& HR,FVector& ShotDirection);
	AController* GetOwnerController() const;
};
