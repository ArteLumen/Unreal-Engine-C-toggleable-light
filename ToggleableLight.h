#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ToggleableLight.generated.h"

class UPointLightComponent;
class USphereComponent;

UCLASS()
class MYPROJECT_API AToggleableLight : public AActor
{
    GENERATED_BODY()
    
public:    
    AToggleableLight();

protected:
    virtual void BeginPlay() override;

public:    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Light")
    UPointLightComponent* PointLightComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Light")
    USphereComponent* TriggerZone;

    UFUNCTION(BlueprintCallable, Category = "Light")
    void ToggleLight();

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
                        bool bFromSweep, const FHitResult& SweepResult);
};
