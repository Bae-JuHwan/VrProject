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
        // 1마디
        { {0}},          // 킥
        {   {1}},          // 스네어
        {   {0}},          // 킥
        {    {1}},          // 스네어

        // 2마디
        {  {0}},
        {   {1}},
        {   {0}},
        {  {1}},

        // 3마디 (마찬가지 패턴 반복)
        {   {0}},
        {   {1}},
        {   {0}},
        {   {1}},

        // 중간의 하이햇+스네어(동시 타격, 아래쪽 박자)
        {   {0,2}},        // 킥+하이햇
        {   {2}},          // 하이햇
        {  {1,2}},        // 스네어+하이햇
        {  {2}},          // 하이햇
        {   {0,2}},        // 킥+하이햇
        {  {2}},          // 하이햇
        {  {1,2}},        // 스네어+하이햇
        {  {2}},          // 하이햇

        // 마지막 박자 등등
    };
};
