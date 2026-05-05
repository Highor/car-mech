#include "DisplaySettingsLibrary.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"
#include "Framework/Application/SlateApplication.h"
#include "GenericPlatform/GenericApplication.h"
#include "GenericPlatform/GenericWindow.h"

TArray<FMonitorInfoBP> UDisplaySettingsLibrary::GetAvailableMonitors()
{
    TArray<FMonitorInfoBP> Result;

    FDisplayMetrics Metrics;
    FDisplayMetrics::RebuildDisplayMetrics(Metrics);

    for (int32 i = 0; i < Metrics.MonitorInfo.Num(); i++)
    {
        const FMonitorInfo& Monitor = Metrics.MonitorInfo[i];

        FMonitorInfoBP Info;
        Info.Name = Monitor.Name;
        Info.X = Monitor.DisplayRect.Left;
        Info.Y = Monitor.DisplayRect.Top;
        Info.Width = Monitor.DisplayRect.Right - Monitor.DisplayRect.Left;
        Info.Height = Monitor.DisplayRect.Bottom - Monitor.DisplayRect.Top;

        Result.Add(Info);
    }

    return Result;
}

void UDisplaySettingsLibrary::MoveWindowToMonitor(int32 MonitorIndex)
{
    if (!GEngine || !GEngine->GameViewport) return;

    FDisplayMetrics Metrics;
    FDisplayMetrics::RebuildDisplayMetrics(Metrics);

    if (!Metrics.MonitorInfo.IsValidIndex(MonitorIndex)) return;

    const FMonitorInfo& Monitor = Metrics.MonitorInfo[MonitorIndex];

    TSharedPtr<SWindow> Window = GEngine->GameViewport->GetWindow();
    if (Window.IsValid())
    {
        FVector2D NewPosition(Monitor.DisplayRect.Left, Monitor.DisplayRect.Top);
        Window->MoveWindowTo(NewPosition);
    }
}