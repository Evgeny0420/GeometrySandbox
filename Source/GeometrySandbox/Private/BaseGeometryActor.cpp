// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All);

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();

	// printTypes();
	// printTransform();
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (GeometryData.MoveType)
	{
	case EMovementType::Sin:
	{
		FVector CurrentLocation = GetActorLocation();
		float time = GetWorld()->GetTimeSeconds();
		CurrentLocation.Z = InitialLocation.Z + GeometryData.Amplitude * FMath::Sin(GeometryData.Frequency * time);

		SetActorLocation(CurrentLocation);
	}
		break;
	case EMovementType::Static:
		break;
	default:
		break;
	}

}

void ABaseGeometryActor::printTypes()
{
	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor Name %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Weapons Num: %d, Kills Num: %i"), WeaponsNum, KillsNum);
	UE_LOG(LogBaseGeometry, Warning, TEXT("Health: %f"), Health);
	UE_LOG(LogBaseGeometry, Warning, TEXT("isDead: %d"), isDead);
	UE_LOG(LogBaseGeometry, Warning, TEXT("IsWeapon: %d"), IsWeapon);
}

void ABaseGeometryActor::printTransform()
{
	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();

	UE_LOG(LogBaseGeometry, Warning, TEXT("Transform %s"), *Transform.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Location %s"), *Location.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Rotation %s"), *Rotation.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Scale %s"), *Scale.ToString());

	UE_LOG(LogBaseGeometry, Error, TEXT("Human transform %s"), *Transform.ToHumanReadableString());
}

