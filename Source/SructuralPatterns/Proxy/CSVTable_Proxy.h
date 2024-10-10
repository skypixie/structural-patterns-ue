// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CSVTable_Proxy.generated.h"

class UCSVTable;

/**
 * 
 */
UCLASS()
class SRUCTURALPATTERNS_API UCSVTable_Proxy : public UObject
{
	GENERATED_BODY()

public:

    bool OpenFile(FString FileName);

    FString ReadString(int Id);

    bool WriteString(int Id, FString Data);

    UCSVTable* Table = nullptr;
	
};
