#include "MyProject/Public/JakeCode/JakeCharacterBase.h"

#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CapsuleComponent.h"
#include "MyProject/Public/JakeCode/JakePlayerControllerBase.h"

AJakeCharacterBase::AJakeCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.f);
	RootComponent = GetCapsuleComponent();

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(RootComponent);
	FirstPersonCamera->SetRelativeLocation(FVector(-10.f, 0.f, 60.f));
	FirstPersonCamera->bUsePawnControlRotation = true;
}

void AJakeCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	// Player Input
	if (AJakePlayerControllerBase* PlayerController = Cast<AJakePlayerControllerBase>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContextBase, 0);
		}
	}
}

void AJakeCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Walking
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AJakeCharacterBase::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AJakeCharacterBase::Look);

		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	}
}

void AJakeCharacterBase::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller == nullptr) return;

	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	AddMovementInput(GetActorRightVector(), MovementVector.X);
}

void AJakeCharacterBase::Look(const FInputActionValue& Value)
{
	const FVector2D LookVector = Value.Get<FVector2D>();

	if (Controller == nullptr) return;

	AddControllerYawInput(LookVector.X);
	AddControllerPitchInput(LookVector.Y);
}

