#pragma once

#include <string>
#include <typeinfo>

class Monster;

namespace Statuses {
    class BaseStatus
    {
    public:
        BaseStatus(std::string initial = "", std::string recurring = "", std::string repeat = "") : 
        initialMsg(std::move(initial)), recurringMsg(std::move(recurring)), repeatMsg(std::move(repeat)) {}
        virtual ~BaseStatus() = default;
        virtual void handleEffect(Monster *, bool, bool) const;

    protected:
        const std::string initialMsg;
        const std::string recurringMsg;
        const std::string repeatMsg;
    };

    class NoStatus : public BaseStatus
    {
    public:
        NoStatus() : BaseStatus("","","") {}
        void handleEffect(Monster *, bool, bool) const override {}
    };

    class Sleep : public BaseStatus
    {
    public:
        Sleep() : BaseStatus(" has fallen asleep!\n", " is sound asleep!\n", " is already asleep!\n") {}
    };

    class Burn : public BaseStatus
    {
    public:
        Burn() : BaseStatus(" has become burned!\n", " is hurt by its burn!\n", " is already burned!\n") {}
    };

    class Freeze : public BaseStatus
    {
    public:
        Freeze() : BaseStatus(" has become frozen solid!\n", " is frozen solid!\n", " is already frozen solid!\nks") {}
    };

    class Paralyze : public BaseStatus
    {
    public:
        Paralyze() : BaseStatus(" has become paralyzed! It may be unable to move!\n", 
                                " is paralyzed! It can't move!\n", 
                                " is already paralyzed!\n") {}
    };

    class Flinch : public BaseStatus
    {
    public:
        Flinch() : BaseStatus(" flinched!", "", "") {}
    };

    extern NoStatus None;
    extern Sleep Sleeping;
    extern Burn Burnt;
    extern Freeze Frozen;
    extern Paralyze Paralyzed;
    extern Flinch Flinched;

}