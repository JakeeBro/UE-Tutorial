#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "InputHelper.generated.h"

UCLASS(Abstract)
class MYPROJECT_API UInputHelper : public UObject
{
	GENERATED_BODY()

public:
	static void SetInputMappingContext(AController* Controller, const UInputMappingContext* Context);
};
