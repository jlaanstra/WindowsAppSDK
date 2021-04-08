﻿#pragma once

#include "pch.h"

#include "PushNotificationBackgroundTask.h"

#include <winrt/base.h>
#include <winrt/windows.networking.pushnotifications.h>

#include "PushNotificationReceivedEventArgs.h"
#include "externs.h"

using namespace winrt::Windows::ApplicationModel::Background;
using namespace winrt::Windows::Networking::PushNotifications;

wil::unique_handle g_waitHandleForArgs;
winrt::Microsoft::ProjectReunion::PushNotificationReceivedEventArgs g_activatedEventArgs{ nullptr };

void PushNotificationBackgroundTask::Run(IBackgroundTaskInstance taskInstance)
{
    g_activatedEventArgs = winrt::Microsoft::ProjectReunion::PushNotificationReceivedEventArgs::CreateFromBackgroundTaskInstance(taskInstance);
    SetEvent(g_waitHandleForArgs.get());
}
