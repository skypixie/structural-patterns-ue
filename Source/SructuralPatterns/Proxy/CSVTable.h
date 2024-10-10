// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CSVTable.generated.h"

/**
 * 
 */
UCLASS()
class SRUCTURALPATTERNS_API UCSVTable : public UObject
{
	GENERATED_BODY()

public:

    bool OpenFile(FString FileName);

    FString ReadString(int Id);

    void WriteString(int Id, FString Data);
	
};
