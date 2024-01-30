#include "MyProject/Public/InputHelper.h"
#include "EnhancedInputSubsystems.h"

void UInputHelper::SetInputMappingContext(AController* Controller, const UInputMappingContext* Context)
{
	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(Context, 0);

			UE_LOG(LogTemp, Warning, TEXT("Mapping Context Set"));
		}
	}
}
