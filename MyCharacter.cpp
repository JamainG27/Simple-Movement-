// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::LookUpCallback);
	PlayerInputComponent->BindAxis("LookRight", this, &AMyCharacter::LookRightCallback);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForwardCallback);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRightCallback);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::JumpCallback);
}

void AMyCharacter::LookUpCallback(float AxisValue)
{
	AddControllerPitchInput(MouseSpeed * AxisValue);
}

void AMyCharacter::LookRightCallback(float AxisValue)
{
	AddControllerYawInput(MouseSpeed * AxisValue);
}

void AMyCharacter::MoveForwardCallback(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), WalkSpeed * AxisValue);
}

void AMyCharacter::MoveRightCallback(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), WalkSpeed * AxisValue);

}

void AMyCharacter::JumpCallback()
{
	Jump();
}

