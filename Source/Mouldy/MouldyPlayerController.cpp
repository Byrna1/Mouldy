// Copyright Epic Games, Inc. All Rights Reserved.


#include "MouldyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "Mouldy.h"
#include "Widgets/Input/SVirtualJoystick.h"

void AMouldyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		}
		else {

			UE_LOG(LogMouldy, Error, TEXT("Could not spawn mobile controls widget."));
		}
	}
	bShowMouseCursor = true;
	PrimaryActorTick.bCanEverTick = true;
}

void AMouldyPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	LookRotate(DeltaSeconds);
}

void AMouldyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}

void AMouldyPlayerController::LookRotate(float DeltaSeconds)
{
	FVector MousePosition, MouseDirection;

	const bool bSuccess = DeprojectMousePositionToWorld(MousePosition, MouseDirection);

	if (bSuccess == true)
	{
		const FVector ActorLoc = GetPawn()->GetActorLocation();

		FVector MouseDirectionAdjusted = ActorLoc + (MouseDirection * 1000.f);
		MouseDirectionAdjusted.Z = ActorLoc.Z;
		FVector EndLocation = FMath::LinePlaneIntersection(
			MousePosition,
			MousePosition + (MouseDirection * 10000.f),
			ActorLoc,
			FVector{ 0.f, 0.f, 1.f }
		);
		EndLocation.Z = ActorLoc.Z;
		FVector EndDirection = EndLocation - ActorLoc;

		SetControlRotation(EndDirection.Rotation());
	}
}
