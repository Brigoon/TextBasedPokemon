#pragma once

enum class ExperienceGroups {
    mediumFast,
    erratic,
    flucuating,
    mediumSlow,
    fast,
    slow
};

class Experience 
{
public:
    Experience(ExperienceGroups group_in) : group(group_in) {}
    ~Experience() = default;

    int getEXPNeeded(int);
private:
    ExperienceGroups group;
};