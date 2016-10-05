// colorfulchew 2016

#include "UnicornAttack.h"
#include "Weapon_Base.h"

UWeapon_Base::UWeapon_Base() 
{
	// Damage stats
	fBaseDamage = 1.0f;
	fBaseDamagePrice = 1.0f;
	fBaseDamagePriceFactor = 2.0f;
	
	// Speed stats
	fBaseSpeed = 1.0f;
	fBaseSpeedPrice = 1.0f;
	fBaseSpeedPriceFactor = 2.0f;
	
	fDamage = 1.0f;
	fSpeed = 1.0f;

	// Current levels
	iDamageLevel = 1;
	iSpeedLevel = 1;


}

void UWeapon_Base::PurchaseSpeed()
{
	float price = GetPriceForLevel(iSpeedLevel, fBaseSpeedPriceFactor, fBaseSpeedPrice);
	

}

void UWeapon_Base::PurchaseDamage()
{

}

float UWeapon_Base::GetPriceForLevel(int level, float priceFactor, float basePrice)
{
	// Returns an exponential pricing based on the price
	float price = basePrice * FMath::Pow(priceFactor, level - 1);
	return price;
}

void UWeapon_Base::DoDamageUpgrade() 
{

}


void UWeapon_Base::DoSpeedUpgrade() 
{

}

void UWeapon_Base::Fire(FTransform transform, AActor* instigator)
{
	// Start spawning the projectile, then assign the damage value and finish spawning
	
	AActor* actor = UGameplayStatics::BeginSpawningActorFromClass(this, Projectile, transform);
	UGameplayStatics::PlaySoundAtLocation(this, ProjectileSound, transform.GetLocation(), 1.0f);
	AProjectile_Base* projectile = Cast<AProjectile_Base>(actor);
	projectile->fDamage = fDamage;
	UGameplayStatics::FinishSpawningActor(actor, transform);
}