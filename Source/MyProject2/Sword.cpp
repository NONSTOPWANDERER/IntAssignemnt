// Fill out your copyright notice in the Description page of Project Settings.


#include "Sword.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DamageEvents.h"
// Sets default values
ASword::ASword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root=CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	Mesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ASword::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASword::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASword::Attack()
{
	UGameplayStatics::SpawnSoundAttached(HitSound,Mesh,TEXT("hand_rSocket"));
	FHitResult HR;
	FVector HitDirection;
	if(SwordTrace(HR,HitDirection))
	{
		
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactEffect,HR.Location,HitDirection.Rotation());
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(),ImpactSound,HR.Location,HitDirection.Rotation());
		if(!HR.GetActor()) return;
		FPointDamageEvent DamageEvent(Damage,HR,HitDirection,nullptr);			
		AController* OwnerController=GetOwnerController();
		HR.GetActor()->TakeDamage(Damage,DamageEvent,OwnerController,this); 
	}
}

bool ASword::SwordTrace(FHitResult& HR,FVector& HitDirection)
{
	AController* OwnerController=GetOwnerController();
	if(!OwnerController) return false;
	FVector Location=OwnerController->GetPawn()->GetActorLocation();
	FRotator Rotation=OwnerController->GetPawn()->GetActorRotation();
	HitDirection=-Rotation.Vector();
	FVector End=Location+Rotation.Vector()*MaxRange;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	return GetWorld()->SweepSingleByChannel(HR,Location,End,FQuat::Identity,ECC_GameTraceChannel11,FCollisionShape::MakeSphere(TraceRadius),Params);
}

AController* ASword::GetOwnerController() const
{
	APawn* OwnerPawn=Cast<APawn>(GetOwner());
	if(!OwnerPawn) return nullptr;
	return OwnerPawn->GetController();
}