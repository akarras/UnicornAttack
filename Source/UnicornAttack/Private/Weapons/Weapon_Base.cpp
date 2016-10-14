// colorfulchew 2016

#include "UnicornAttack.h"
#include "Weapon_Base.h"

UWeapon_Base::UWeapon_Base() 
{
	isPurchased = isPurchasedConfig;
	fPurchasePrice = 200.0f;

	// Damage stats
	fBaseDamage = 1.0f;
	fDamageFactor = 2.0f;
	fBaseDamagePrice = 1.0f;
	fBaseDamagePriceFactor = 2.0f;
	
	// Speed stats
	fBaseSpeed = 1.0f;
	fSpeedFactor = 2.0f;
	fBaseSpeedPrice = 1.0f;
	fBaseSpeedPriceFactor = 2.0f;
	
	fDamage = fBaseDamage;
	fSpeed = fBaseSpeed;

	// Current levels
	iDamageLevel = 1;
	iSpeedLevel = 1;


}

float UWeapon_Base::GetPriceForLevel(int level, float priceFactor, float basePrice)
{
	// Returns an exponential pricing based on the price
	float price = basePrice * FMath::Pow(priceFactor, level - 1);
	return price;
}

void UWeapon_Base::PurchaseDamage() 
{
	iDamageLevel++;
	fDamage = GetPriceForLevel(iDamageLevel, fDamageFactor, fBaseDamage);
}


void UWeapon_Base::PurchaseSpeed() 
{
	iSpeedLevel++;
	fSpeed = GetPriceForLevel(iSpeedLevel, fSpeedFactor, fBaseSpeed);
}

float UWeapon_Base::GetDamagePrice()
{
	return GetPriceForLevel(iDamageLevel, fBaseDamagePriceFactor, fBaseDamagePrice);
}

float UWeapon_Base::GetSpeedPrice()
{
	return GetPriceForLevel(iSpeedLevel, fBaseSpeedPriceFactor, fBaseSpeedPrice);
}

void UWeapon_Base::Fire_Implementation(FTransform transform, APawn* instigator)
{
	// Start spawning the projectile, then assign the damage value and finish spawning
	AActor* actor = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, Projectile, transform);
	PlayWeaponSound(transform.GetLocation());
	AProjectile_Base* projectile = Cast<AProjectile_Base>(actor);
	projectile->fDamage = fDamage;
	projectile->Instigator = instigator;
	projectile->SetReplicates(true);
	UGameplayStatics::FinishSpawningActor(actor, transform);
}

bool UWeapon_Base::Fire_Validate(FTransform transform, APawn* instigator)
{
	return true;
}

void UWeapon_Base::Reset()
{
	isPurchased = isPurchasedConfig;
	fDamage = fBaseDamage;
	fSpeed = fBaseSpeed;

	iSpeedLevel = 1;
	iDamageLevel = 1;
}

void UWeapon_Base::PlayWeaponSound_Implementation(FVector location)
{
	UGameplayStatics::PlaySoundAtLocation(this, ProjectileSound, location, 1.0f);
}