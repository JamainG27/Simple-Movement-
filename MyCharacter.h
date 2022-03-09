// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class JMAIN_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float MouseSpeed = 2.5f;

	float WalkSpeed = 10.0f;

protected:
	void LookUpCallback(float AxisValue);

	void LookRightCallback(float AxisValue);

	void MoveForwardCallback(float AxisValue);

	void MoveRightCallback(float AxisValue);

	void JumpCallback();

};
