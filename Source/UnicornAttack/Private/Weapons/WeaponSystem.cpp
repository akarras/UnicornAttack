// colorfulchew 2016

#include "UnicornAttack.h"
#include "WeaponSystem.h"


// Sets default values for this component's properties
UWeaponSystem::UWeaponSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UWeaponSystem::BeginPlay()
{
	Super::BeginPlay();
	for (auto Weapon : AvailableWeapons)
	{
		Weapons.Add(Weapon.GetDefaultObject());
	}

	for (auto Weapon : Weapons)
	{
		// Reset our weapons back to the default stats when the game starts.
		Weapon->Reset();
	}
	// ...
	
}


// Called every frame
void UWeaponSystem::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

UWeapon_Base* UWeaponSystem::GetCurrentWeapon()
{
	if (Weapons.IsValidIndex(0)) 
	{
		return Weapons[0];
	}
	return nullptr;
}

