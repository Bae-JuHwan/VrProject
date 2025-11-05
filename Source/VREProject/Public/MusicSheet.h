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
	float Time;

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

	UFUNCTION(BlueprintCallable)
	virtual void Sheet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNode> Anode;

    TArray<FNode> SimpleDrumSheet = {
        // 1마디
        {0.0f,    {0}},          // 킥
        {1.0f,    {1}},          // 스네어
        {2.0f,    {0}},          // 킥
        {3.0f,    {1}},          // 스네어

        // 2마디
        {4.0f,    {0}},
        {5.0f,    {1}},
        {6.0f,    {0}},
        {7.0f,    {1}},

        // 3마디 (마찬가지 패턴 반복)
        {8.0f,    {0}},
        {9.0f,    {1}},
        {10.0f,   {0}},
        {11.0f,   {1}},

        // 중간의 하이햇+스네어(동시 타격, 아래쪽 박자)
        {12.0f,   {0,2}},        // 킥+하이햇
        {12.5f,   {2}},          // 하이햇
        {13.0f,   {1,2}},        // 스네어+하이햇
        {13.5f,   {2}},          // 하이햇
        {14.0f,   {0,2}},        // 킥+하이햇
        {14.5f,   {2}},          // 하이햇
        {15.0f,   {1,2}},        // 스네어+하이햇
        {15.5f,   {2}},          // 하이햇

        // 마지막 박자 등등
    };
};
