#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.generated.h"

UCLASS()
class WELEVELTEST_API ATargetActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ATargetActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boolean")
        bool bMyBoolean;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBoolChanged);
    UPROPERTY(BlueprintAssignable, Category = "Event")
    FOnBoolChanged OnBoolChanged;

    UFUNCTION(BlueprintCallable, Category = "Boolean")
    void ChangeBool(bool NewValue);
};
