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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeaponPricing")
	bool isPurchased;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="WeaponPricing")
	float fBaseDamagePrice;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="WeaponPricing")
	float fBaseSpeedPrice;

	float fBaseDamagePriceFactor;
	float fBaseSpeedPriceFactor;

	UFUNCTION(BlueprintCallable, Category="WeaponPricing")
	virtual void PurchaseSpeed();
	UFUNCTION(BlueprintCallable, Category="WeaponPricing")
	virtual void PurchaseDamage();

	UFUNCTION(BlueprintCallable, Category = "WeaponPricing")
	virtual float GetPriceForLevel(int level, float priceFactor, float basePrice);

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Weapon")
	TSubclassOf<AProjectile_Base> Projectile;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Weapon")
	USoundBase* ProjectileSound;

	float fBaseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	float fDamage;
	int iDamageLevel;

	float fBaseSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	float fSpeed;
	int iSpeedLevel;
	
	virtual void DoSpeedUpgrade();
	virtual void DoDamageUpgrade();
	UFUNCTION(BlueprintCallable, Category="Weapon")
	virtual void Fire(FTransform transform, AActor* instigator);
};
