// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All);

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	FString Name = "John Conor";

	// printTypes();
	UE_LOG(LogBaseGeometry, Display, TEXT("name: %s"), *Name);

	int WeaponsNum = 4;
	float Health = 35.323;
	bool IsWeapon = false;

	FString WeaponsNumStr = "Weapons Num - " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsWeaponStr = "Is Weapon = " + FString(IsWeapon ? "true" : "false");

	FString Stat = FString::Printf(TEXT("\n All stat \n %s \n %s \n %s"), *WeaponsNumStr, *HealthStr, *IsWeaponStr);

	UE_LOG(LogBaseGeometry, Display, TEXT("%s"), *Stat);
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGeometryActor::printTypes()
{
	int WeaponsNum = 4;
	int KillsNum = 0;
	float Health = 35.323;
	bool isDead = false;
	bool IsWeapon = false;

	UE_LOG(LogTemp, Display, TEXT("Weapons Num: %d, Kills Num: %i"), WeaponsNum, KillsNum);
	UE_LOG(LogTemp, Display, TEXT("Health: %f"), Health);
	UE_LOG(LogTemp, Display, TEXT("isDead: %d"), isDead);
	UE_LOG(LogTemp, Display, TEXT("IsWeapon: %d"), IsWeapon);
}

