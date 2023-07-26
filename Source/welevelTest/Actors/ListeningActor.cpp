#include "ListeningActor.h"

void AListeningActor::BeginPlay()
{
    Super::BeginPlay();

    if (TargetActor)
    {
        TargetActor->OnBoolChanged.AddDynamic(this, &AListeningActor::OnTargetBoolChanged);

        // Print message to console for debugging
        UE_LOG(LogTemp, Warning, TEXT("ListeningActor: Event bound to target"));
    }
 
}

void AListeningActor::ServerDestroyActor_Implementation()
{
    // This code will be run on the server
    Destroy();
}

void AListeningActor::OnTargetBoolChanged()
{
    UE_LOG(LogTemp, Warning, TEXT("ListeningActor: Actor being destroyed due to boolean change in target"));

    if (HasAuthority())
    {
        // If this code is running on the server, destroy the actor directly
        Destroy();
    }
    else
    {
        // If this code is running on a client, request the server to destroy the actor
        ServerDestroyActor();
    }
}