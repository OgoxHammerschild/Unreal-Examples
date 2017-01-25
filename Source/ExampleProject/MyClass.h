// © 2016 - 2017 Daniel Bortfeld

#pragma once

#include "InOut.h"
#include "GameFramework/Actor.h"
#include "MyClass.generated.h"

// First you need your enums
UENUM(BlueprintType)
enum class EBranch : uint8
{
	IsTrue,
	IsFalse
};

UENUM(BlueprintType)
enum class EHasItem : uint8
{
	Has,
	HasNot
};

UCLASS()
class EXAMPLEPROJECT_API AMyClass : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY()
		TArray<class AItem*> Inventory;

private:

	UPROPERTY()
		float myRange = 7;

	UPROPERTY()
		int32 level = 2;

public:	
	// Sets default values for this actor's properties
	AMyClass();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Specify a return value to return a single property
	UFUNCTION(BlueprintPure, Category = "Range")
		float GetRange();
	
	// Use the &-operator to return multiple properties
	//
	// Use UPARAM and the DisplayName specifier in case 
	// you have shortcuts or unclear names for your parameters

	//UFUNCTION(BlueprintPure, Category = "Data")
	//	void GetData(
	//		/*UPARAM(DisplayName = "Range")        */        float out rng,
	//		/*UPARAM(DisplayName = "Actor Name")   */        FString out name,
	//		/*UPARAM(DisplayName = "Level")        */        int32 out lvl);


	// I always use the prefix BPEvent_ to indicate that
	// the body of the function will be defined within the Blueprint Editor,
	// but I don'twant the prefix to show up inside the Blueprint. That's 
	// why I use the DisplayName meta-specifier.
	
	// The body for this function will be declared inside the Blueprint Editor
	UFUNCTION(BlueprintImplementableEvent, Category = "Event", meta = (DisplayName = "OnShoot"))
		void BPEvent_OnShoot(float in range);

	// The native body for this function can(!) be called inside the 
	// Blueprint Editor
	// Otherwise it has no body like a BlueprintImplementableEvent
	//UFUNCTION(BlueprintNativeEvent, Category = "Event", meta = (DisplayName = "OnShoot"))
	//	void BPEvent_OnDestroy(AActor* destroyedActor);



	// The meta specifier ExpandEnumAsExecs lets the execution pins show up in
	// the Blueprint Editor
	//UFUNCTION(BlueprintCallable, Category = FlowControl, meta = (Keyword = "if", ExpandEnumAsExecs = "Branch"))
	//	void MyOwnBranch(bool in condition, EBranch out Branch);

	//UFUNCTION(BlueprintCallable, Category = Inventory, meta = (Keyword = "has", ExpandEnumAsExecs = "Has"))
	//	bool DoesPlayerHaveItem(AItem* item, EHasItem out Has);
};
