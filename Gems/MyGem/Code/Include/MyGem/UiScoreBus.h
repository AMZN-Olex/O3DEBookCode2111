#pragma once

#include <AzCore/Component/ComponentBus.h>
#include <AzCore/RTTI/BehaviorContext.h>

namespace MyGem
{
    class UiScoreNotifications
        : public AZ::ComponentBus
    {
    public:
        virtual void OnTeamScoreChanged(int team, int score) = 0;
    };

    using UiScoreNotificationBus = AZ::EBus<UiScoreNotifications>;

    class ScoreNotificationHandler
        : public UiScoreNotificationBus::Handler
        , public AZ::BehaviorEBusHandler
    {
    public:
        AZ_EBUS_BEHAVIOR_BINDER(ScoreNotificationHandler,
            "{33B5BC25-622B-4DF0-92CF-987CC6108C31}",
            AZ::SystemAllocator, OnTeamScored);

        void OnTeamScoreChanged(int team, int score) override
        {
            Call(FN_OnTeamScoreChanged, team, score);
        }
    };
}
