#pragma once

#include <string>
#include <typeinfo>

class Monster;

namespace Statuses {
    class BaseStatus
    {
    public:
        BaseStatus(std::string initial = "", std::string recurring = "") : initialMsg(std::move(initial)), recurringMsg(std::move(recurring)) {}
        virtual ~BaseStatus() = default;
        virtual void handleEffect(Monster *, bool) const;

    protected:
        const std::string initialMsg;
        const std::string recurringMsg;
    };

    class NoStatus : public BaseStatus
    {
    public:
        NoStatus() : BaseStatus("","") {}
        void handleEffect(Monster *, bool) const override {}
    };

    class Sleep : public BaseStatus
    {
    public:
        Sleep() : BaseStatus(" has fallen asleep!\n", " is sound asleep!\n") {}
        void handleEffect(Monster *, bool);
    };

    class Burn : public BaseStatus
    {
    public:
        Burn() : BaseStatus(" has become burned!\n", " is hurt by its burn!\n") {}
    };

    class Freeze : public BaseStatus
    {
    public:
        Freeze() : BaseStatus(" has become frozen solid!\n", " is frozen solid!\n") {}
    };

    class Paralyze : public BaseStatus
    {
    public:
        Paralyze() : BaseStatus(" has become paralyzed! It may be unable to move!\n", " is paralyzed!\n") {}
    };

    class Flinch : public BaseStatus
    {
    public:
        Flinch() : BaseStatus(" flinched!", "") {}
    };

    extern NoStatus None;
    extern Sleep Sleeping;
    extern Burn Burnt;
    extern Freeze Frozen;
    extern Paralyze Paralyzed;
    extern Flinch Flinched;

}