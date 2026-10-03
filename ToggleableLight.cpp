#include "ToggleableLight.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"

AToggleableLight::AToggleableLight()
{
    PrimaryActorTick.bCanEverTick = false;

    PointLightComp = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComp"));
    RootComponent = PointLightComp;
    PointLightComp->SetIntensity(3000.0f); 
    PointLightComp->SetLightColor(FLinearColor::Yellow); 
  
    TriggerZone = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerZone"));
    TriggerZone->SetupAttachment(RootComponent);
    TriggerZone->InitSphereRadius(250.0f); 

    TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &AToggleableLight::OnOverlapBegin);
}

void AToggleableLight::BeginPlay()
{
    Super::BeginPlay();
}

void AToggleableLight::ToggleLight()
{
    if (PointLightComp)
    {
        bool bIsVisible = PointLightComp->IsVisible();
        PointLightComp->SetVisibility(!bIsVisible);
    }
}

void AToggleableLight::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
                                    bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->IsA(ACharacter::StaticClass()))
    {
        ToggleLight(); 
    }
}
