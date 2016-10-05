// colorfulchew 2016

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile_Base.generated.h"

UCLASS(Blueprintable)
class UNICORNATTACK_API AProjectile_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile_Base();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(BlueprintReadWrite, Category=Weapon)
	float fDamage;
	
};
