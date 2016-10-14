// colorfulchew 2016

#include "UnicornAttack.h"
#include "Net/UnrealNetwork.h"
#include "WeaponSystem.h"


// Sets default values for this component's properties
UWeaponSystem::UWeaponSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	bReplicates = true;
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

void UWeaponSystem::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	DOREPLIFETIME(UWeaponSystem, SelectedWeapon);
}

// Called every frame
void UWeaponSystem::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

UWeapon_Base* UWeaponSystem::GetCurrentWeapon()
{
	if (Weapons.IsValidIndex(SelectedWeapon)) 
	{
		return Weapons[SelectedWeapon];
	}
	return nullptr;
}

void UWeaponSystem::switchNextWeapon()
{
	// Go to the next index
	//    If the index is out of the bounds, reset back to 0
	//    If the weapon isn't purchased, switch to the next index
	bool selectedValidWeapon = false;
	int initialWeapon = SelectedWeapon;
	while (!selectedValidWeapon)
	{
		SelectedWeapon++;
		if (Weapons.IsValidIndex(SelectedWeapon))
		{
			if (auto weapon = Weapons[SelectedWeapon])
			{
				if (weapon->isPurchased)
				{
					updateServerWeapon(SelectedWeapon);
					selectedValidWeapon = true;
				}
			}
		}
		else {
			SelectedWeapon = -1;
		}
	}
}

void UWeaponSystem::switchPreviousWeapon()
{
	bool selectedValidWeapon = false;
	int initialWeapon = SelectedWeapon;
	while (!selectedValidWeapon)
	{
		SelectedWeapon--;
		if (Weapons.IsValidIndex(SelectedWeapon))
		{
			if (auto weapon = Weapons[SelectedWeapon])
			{
				if (weapon->isPurchased)
				{
					updateServerWeapon(SelectedWeapon);
					selectedValidWeapon = true;
				}
			}
		}
		else {
			SelectedWeapon = Weapons.Num();
		}
	}
}

void UWeaponSystem::updateServerWeapon_Implementation(int weapon)
{
	SelectedWeapon = weapon;
}

bool UWeaponSystem::updateServerWeapon_Validate(int weapon)
{
	return true;
}