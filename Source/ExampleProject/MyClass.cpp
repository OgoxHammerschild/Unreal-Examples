// © 2016 - 2017 Daniel Bortfeld

#include "ExampleProject.h"
#include "MyClass.h"
#include "Item.h"

// Sets default values
AMyClass::AMyClass()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

float AMyClass::GetRange()
{
	return myRange;
}

void AMyClass::GetData(float & rng, FString & name, int32 & lvl)
{
	rng = myRange;
	name = GetName();
	lvl = level;
}

// For the declaration of your native body, add _Implementation to 
// the function name
void AMyClass::BPEvent_OnDestroy_Implementation(AActor* destroyedActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Call to native body of OnDestroy"));
}

void AMyClass::MyOwnBranch(bool const& condition, EBranch & Branch)
{
	condition ? Branch = EBranch::IsTrue : Branch = EBranch::IsFalse;
}

bool AMyClass::DoesPlayerHaveItem(AItem* item, EHasItem & Has)
{
	Has = EHasItem::HasNot;

	for (auto& slot : Inventory)
	{
		if (slot == item)
		{
			Has = EHasItem::Has;
			return true;
		}
	}

	return false;
}
