// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MusicSheet.generated.h"

USTRUCT(BlueprintType)
struct FNode
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> NodeNums; // 동시에 누를 노드들
};
UCLASS()
class VREPROJECT_API AMusicSheet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMusicSheet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//UFUNCTION(BlueprintCallable)
	//virtual int32 CallFireNode(int32 NodeNum);

    UFUNCTION(BlueprintImplementableEvent)
    int32 CallFireNode(int32 NodeNum);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<int32> DrumNode;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FNode> SimpleDrumSheet = {
        // ===== 1마디 =====
      {{2}},  {},  {{3}},  {},     // 1(베이스), 2(쉬), 3(스네어), 4(쉬)
      {},     {{2}}, {{3}},  {},   // 5(쉬), 6(베이스), 7(스네어), 8(쉬)

      // ===== 2마디 (같은 패턴) =====
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},

      // ===== 3마디 =====
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},

      // ===== 4마디 =====
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},
      {{2}},  {},  {{3}},  {},     // 1(베이스), 2(쉬), 3(스네어), 4(쉬)
      {},     {{2}}, {{3}},  {},   // 5(쉬), 6(베이스), 7(스네어), 8(쉬)

      // ===== 2마디 (같은 패턴) =====
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},

      // ===== 3마디 =====
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},

      // ===== 4마디 =====
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},

      {{2}},  {},  {{3}},  {},     // 1(베이스), 2(쉬), 3(스네어), 4(쉬)
      {},     {{2}}, {{3}},  {},   // 5(쉬), 6(베이스), 7(스네어), 8(쉬)

      // ===== 2마디 (같은 패턴) =====
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},

      // ===== 3마디 =====
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},

      // ===== 4마디 =====
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},
      {{2}},  {},  {{3}},  {},     // 1(베이스), 2(쉬), 3(스네어), 4(쉬)
      {},     {{2}}, {{3}},  {},   // 5(쉬), 6(베이스), 7(스네어), 8(쉬)

      // ===== 2마디 (같은 패턴) =====
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},

      // ===== 3마디 =====
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},

      // ===== 4마디 ===== 뜻으로~
      {{2}},  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},
   
      // ===== 왼쪽: 탐 연타 (2마디) =====
        {{2}}, {}, {{3,4}}, {{3,4}}, {{3,4}}, {{3,4}}, {{3,4}}, {{3,4}},
     {{3,4}}, {{3,4}}, {{3,4}}, {{3,4}}, {{3,4}},{{3}}, {{3}},
     // ===== 3마디 =====
      { { 2 } },  {},  {{3}},  {},
      {},     {{2}}, {{3}},  {},
      // ===== 4마디 ===== cong~
     {{2}},  {},  {{3}},  {},
     {},     {{2}}, {{3}},  {},
      {{2}},  {},  {{3}},  {},     // 1(베이스), 2(쉬), 3(스네어), 4(쉬)
      {},     {{2}}, {{3}},  {},   // 5(쉬), 6(베이스), 7(스네어), 8(쉬)

    };
};
