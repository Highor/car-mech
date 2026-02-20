#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OnlineSubsystemUtils.h" // Voeg deze include toe
#include "SteamHelper.generated.h"

UCLASS()
class CARMECH_API USteamHelper : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, meta = (DisplayName = "UniqueNetId to String"), Category = "Steam")
    static FString UniqueNetIdToString(FUniqueNetIdRepl UniqueNetId);
};