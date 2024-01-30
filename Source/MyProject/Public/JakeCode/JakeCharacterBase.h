#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "MyProject/MyProjectCharacter.h"
#include "JakeCharacterBase.generated.h"

UCLASS()
class MYPROJECT_API AJakeCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AJakeCharacterBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Jake Character/Camera")
	UCameraComponent* FirstPersonCamera;

protected:
	virtual void BeginPlay() override;

// PLAYER INPUT
public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Jake Character/Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* MappingContextBase;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Jake Character/Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Jake Character/Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Jake Character/Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

private:
	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

};
