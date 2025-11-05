// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicSheet.h"

// Sets default values
AMusicSheet::AMusicSheet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMusicSheet::BeginPlay()
{
	Super::BeginPlay();
	Sheet();
}

// Called every frame
void AMusicSheet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AMusicSheet::CallFireNode(int32 NodeNum)
{
	return NodeNum;
}

void AMusicSheet::Sheet()
{
	for (const FNode& node : SimpleDrumSheet){
		for (const int& i : node.NodeNums)
		{
			CallFireNode(i);
		}
		// 2. 노드 기다려야 하는 시간만큼 대기
		FPlatformProcess::Sleep(node.Time); // (테스트용, 슬립은 실제 게임에선 사용 권장X)
	}
}

