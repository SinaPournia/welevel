#include "TargetActor.h"

// Sets default values
ATargetActor::ATargetActor()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATargetActor::BeginPlay()
{
	Super::BeginPlay();
}


void ATargetActor::ChangeBool(bool NewValue)
{
    if (bMyBoolean != NewValue)
    {
        bMyBoolean = NewValue;

        // Print message to console for debugging
        UE_LOG(LogTemp, Warning, TEXT("TargetActor: Boolean value changed to %s"), bMyBoolean ? TEXT("true") : TEXT("false"));

        if (OnBoolChanged.IsBound())
        {
            OnBoolChanged.Broadcast();
        }
        else
        {
            // Print error message to console if no listeners are bound
            UE_LOG(LogTemp, Error, TEXT("TargetActor: No listeners bound to event"));
        }
    }
}