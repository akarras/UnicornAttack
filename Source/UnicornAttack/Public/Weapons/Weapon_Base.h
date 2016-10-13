// colorfulchew 2016

#pragma once

#include "Object.h"
#include "UnicornAttack.h"
#include "Weapons/Projectiles/Projectile_Base.h"
#include "Weapon_Base.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UNICORNATTACK_API UWeapon_Base : public UObject
{
	GENERATED_BODY()
public:
	UWeapon_Base();

	UPROPERTY(EditAnywhere, Category="Weapon|Pricing")
	bool isPurchasedConfig;

	UPROPERTY(BlueprintReadWrite, Category="Weapon|Pricing")
	bool isPurchased;

	// PRICING
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon|Pricing")
	float fPurchasePrice;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Weapon|Pricing")
	float fBaseDamagePrice;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Weapon|Pricing")
	float fBaseSpeedPrice;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Weapon|Pricing")
	float fBaseDamagePriceFactor;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Weapon|Pricing")
	float fBaseSpeedPriceFactor;

	UFUNCTION(BlueprintCallable, Category="Weapon|Pricing")
	virtual void PurchaseSpeed();
	UFUNCTION(BlueprintCallable, Category="Weapon|Pricing")
	virtual void PurchaseDamage();
	
	UFUNCTION(BlueprintCallable, Category="Weapon|Pricing")
	virtual float GetDamagePrice();
	UFUNCTION(BlueprintCallable, Category="Weapon|Pricing")
	virtual float GetSpeedPrice();

	UFUNCTION(BlueprintCallable, Category = "Weapon|Pricing")
	virtual float GetPriceForLevel(int level, float priceFactor, float basePrice);

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Weapon|Assets")
	TSubclassOf<AProjectile_Base> Projectile;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Weapon|Assets")
	USoundBase* ProjectileSound;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Weapon|Information")
	FText weaponName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon|Damage")
	float fBaseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Weapon|Damage")
	float fDamageFactor;
	UPROPERTY(BlueprintReadOnly, Category="Weapon|Damage")
	float fDamage;
	UPROPERTY(BlueprintReadOnly, Category="Weapon|Damage")
	int iDamageLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Weapon|Damage")
	float fBaseSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon|Damage")
	float fSpeedFactor;
	UPROPERTY(BlueprintReadOnly, Category ="Weapon|Damage")
	float fSpeed;
	UPROPERTY(BlueprintReadOnly, Category ="Weapon|Damage")
	int iSpeedLevel;

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation, Category="Weapon")
	virtual void Fire(FTransform transform, APawn* instigator);
	UFUNCTION(BlueprintCallable, Category="Weapon")
	virtual void Reset();

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable, Category="Weapon")
	virtual void PlayWeaponSound(FVector location);
};
