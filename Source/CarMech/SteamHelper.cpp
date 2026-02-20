#include "SteamHelper.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"

FString USteamHelper::UniqueNetIdToString(FUniqueNetIdRepl UniqueNetId)
{
    if (UniqueNetId.IsValid())
    {
        TSharedPtr<const FUniqueNetId> RawId = UniqueNetId.GetUniqueNetId();
        if (RawId.IsValid())
        {
            return RawId->ToString();
        }
    }
    return FString(TEXT("Invalid ID"));
}