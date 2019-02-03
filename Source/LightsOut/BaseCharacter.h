// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class LIGHTSOUT_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()


public:

	//Make a health property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
		float Health = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
		float Money = 1000;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
		bool hasFullHealth = true;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
		float maxHealth = 100;

	//Make an isDeadProperty
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
		bool isDead = false;

	//CalculateDeathFunction (helper)
	virtual void CalculateDead();

	virtual void CalculateFullHealth();

	//Calculate health function
	UFUNCTION(BlueprintCallable, Category = "Base Character")
		virtual void CalculateHealth(float delta);

	UFUNCTION(BlueprintCallable, Category = "Base Character")
		virtual bool CalculateMoney(float delta);

#if WITH_EDITOR
	//Editor-centric for changing properties
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
		override;
#endif

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
