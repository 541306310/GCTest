// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MyActor.generated.h"


class FGcTest : public FGCObject
{
public:
	FGcTest();


	~FGcTest();
};

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when the game starts or when spawned
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	//static void AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector) ;


	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollisionComponent;

	// Collision handling function
	UFUNCTION()
	void OnBoxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
	//UPROPERTY() UPrintLog *MyObjectInstance;
	//UPrintLog* TestActorWithAddReference;//方式2
	UPrintLog* TestActorWithSetRoot;//方式3
	//UPrintLog* TestActorWithSpawnAPI;//方式4
	UPrintLog* TestActorWithStrongPtr;//方式5
	TStrongObjectPtr<UObject> StrongTestPtr;
	FGcTest *gctest;

};


UCLASS()
class MYPROJECT_API UPrintLog : public UObject
{
	GENERATED_BODY()
public:
	UPrintLog();
	~UPrintLog();

};


