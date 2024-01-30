#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CarGameInputData.generated.h"

UCLASS()
class MYPROJECT_API UCarGameInputData : public UDataAsset
{
	GENERATED_BODY()

public:
	// Movement and Camera
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Enhanced Input")
	class UInputAction* MoveForwardAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Enhanced Input")
	UInputAction* MoveRightAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Enhanced Input")
	UInputAction* TurnAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Enhanced Input")
	UInputAction* LookUpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Enhanced Input")
	UInputAction* TurnAtRateAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Enhanced Input")
	UInputAction* LookUpAtRateAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Enhanced Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Enhanced Input")
	UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Enhanced Input")
	UInputAction* CrouchAction;
	
};
