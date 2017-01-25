// © 2016 - 2017 Daniel Bortfeld

#include "ExampleProject.h"
#include "MyClass.h"
#include "Item.h"

// Sets default values
AMyClass::AMyClass()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyClass::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AMyClass::GetRange()
{
	return myRange;
}

//void AMyClass::GetData(float out rng, FString out name, int32 out lvl)
//{
//	rng = myRange;
//	//name = GetName();
//	lvl = level;
//}
//
//// For the declaration of your native body, add _Implementation to 
//// the function name
//void AMyClass::BPEvent_OnDestroy_Implementation(AActor* destroyedActor)
//{
//	UE_LOG(LogTemp, Warning, TEXT("Call to native body of OnDestroy"));
//}
//
//void AMyClass::MyOwnBranch(bool in condition, EBranch out Branch)
//{
//	condition ? Branch = EBranch::IsTrue : Branch = EBranch::IsFalse;
//}
//
//bool AMyClass::DoesPlayerHaveItem(AItem* item, EHasItem out Has)
//{
//	for (auto& slot : Inventory)
//	{
//		if (slot == item)
//		{
//			Has = EHasItem::Has;
//			return true;
//		}
//	}
//	Has = EHasItem::HasNot;
//	return false;
//}
