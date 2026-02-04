#pragma once

#include <string>
class Monster;

namespace Statuses {
    class BaseStatus
    {
    public:
        BaseStatus(std::string initial = "", std::string recurring = "") : initialMsg(std::move(initial)), recurringMsg(std::move(recurring)) {}
        virtual ~BaseStatus() = default;
        virtual void handleEffect(bool);

    protected:
        const std::string initialMsg;
        const std::string recurringMsg;
    };

    class NoStatus : public BaseStatus
    {
    public:
        NoStatus() : BaseStatus("","") {}
        void handleEffect(bool) override {}
    };

    class Sleep : public BaseStatus
    {
    public:
        Sleep() : BaseStatus(" has fallen asleep!", " is sound asleep!") {}
        void handleEffect(Monster *, bool);
    };

    class Burn : public BaseStatus
    {
    public:
        Burn() : BaseStatus(" has become burned!", " is hurt by its burn!") {}
    };

    class Freeze : public BaseStatus
    {
    public:
        Freeze() : BaseStatus(" has become frozen solid!", " is frozen solid!") {}
    };

    class Paralyze : public BaseStatus
    {
    public:
        Paralyze() : BaseStatus(" has become paralyzed! It may be unable to move!", " is paralyzed!") {}
    };

    class Flinched : public BaseStatus
    {
    public:
        Flinched() : BaseStatus(" flinched!", "") {}
    };
}