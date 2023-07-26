#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.h"
#include "ListeningActor.generated.h"

UCLASS()
class WELEVELTEST_API AListeningActor : public AActor
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target", meta = (ExposeOnSpawn = true))
        ATargetActor* TargetActor;


    virtual void BeginPlay() override;

    UFUNCTION(Server, Reliable)
    void ServerDestroyActor();
    UFUNCTION()
    void OnTargetBoolChanged();
};
