// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "UObject/NoExportTypes.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>((TEXT("StaticMesh")));
	StaticMeshComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	StaticMeshComponent->SetStaticMesh(MeshAsset.Object);

	BoxCollisionComponent = CreateDefaultSubobject<UBoxComponent>((TEXT("box")));
	BoxCollisionComponent->SetupAttachment(StaticMeshComponent);

	BoxCollisionComponent->SetBoxExtent(FVector(50.f, 50.f, 50.f));
	BoxCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyActor::OnBoxOverlapBegin);

	
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	//MyObjectInstance = NewObject<UPrintLog>(this, UPrintLog::StaticClass());
	//TestActorWithAddReference = NewObject<UPrintLog>(this, UPrintLog::StaticClass());
	TestActorWithSetRoot = NewObject<UPrintLog>(this, UPrintLog::StaticClass());
	TestActorWithSetRoot->AddToRoot();

	TestActorWithStrongPtr = NewObject<UPrintLog>(this, UPrintLog::StaticClass());
	StrongTestPtr = TStrongObjectPtr<UPrintLog>(TestActorWithStrongPtr);

	//gctest = new FGcTest;
}

void AMyActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	//一定要加,否则会崩溃
	TestActorWithSetRoot->RemoveFromRoot();
	StrongTestPtr.Reset();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}



void AMyActor::OnBoxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Collision Detected!"));

}

/*
void AMyActor::AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector)
{
	AMyActor* This = CastChecked<AMyActor>(InThis);
	Collector.AddReferencedObject(This->TestActorWithAddReference);
}
*/


UPrintLog::UPrintLog()
{
	UE_LOG(LogTemp, Warning, TEXT("UPrintLog  create 1111111111111111"));
}

UPrintLog::~UPrintLog()
{
	UE_LOG(LogTemp, Warning, TEXT("UPrintLog  destory 2222222222222222222"));
}

FGcTest::FGcTest()
{
	UE_LOG(LogTemp, Warning, TEXT("UPrintLog  create 333333333333333333333"));
}




FGcTest::~FGcTest()
{
	UE_LOG(LogTemp, Warning, TEXT("UPrintLog  destory 444444444444444444444444444"));
}
