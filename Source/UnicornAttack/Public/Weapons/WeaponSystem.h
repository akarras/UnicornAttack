// colorfulchew 2016

#pragma once

#include "Components/ActorComponent.h"
#include "Net/UnrealNetwork.h"
#include "Weapons/Weapon_Base.h"
#include "WeaponSystem.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNICORNATTACK_API UWeaponSystem : public UActorComponent
{
	GENERATED_BODY()
public:	
	// Sets default values for this component's properties
	UWeaponSystem();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
	UFUNCTION(BlueprintCallable, Category="Weapon")
	virtual UWeapon_Base* GetCurrentWeapon();

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UWeapon_Base>> AvailableWeapons;
	UPROPERTY(EditAnywhere, Replicated, BlueprintReadWrite)
	TArray<UWeapon_Base*> Weapons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Weapon")
	int SelectedWeapon;
	
	UFUNCTION(Server, Reliable, WithValidation, Category = "Weapon")
	virtual void updateServerWeapon(int weapon);

	UFUNCTION(BlueprintCallable, Category="Weapon")
	virtual void switchNextWeapon();
	UFUNCTION(BlueprintCallable, Category="Weapon")
	virtual void switchPreviousWeapon();
};
