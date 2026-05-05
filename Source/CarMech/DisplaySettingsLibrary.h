#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DisplaySettingsLibrary.generated.h"

USTRUCT(BlueprintType)
struct FMonitorInfoBP
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    FString Name;

    UPROPERTY(BlueprintReadOnly)
    int32 X;

    UPROPERTY(BlueprintReadOnly)
    int32 Y;

    UPROPERTY(BlueprintReadOnly)
    int32 Width;

    UPROPERTY(BlueprintReadOnly)
    int32 Height;
};

UCLASS()
class CARMECH_API UDisplaySettingsLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "Display")
    static TArray<FMonitorInfoBP> GetAvailableMonitors();

    UFUNCTION(BlueprintCallable, Category = "Display")
    static void MoveWindowToMonitor(int32 MonitorIndex);
};