// note: for now, just do integer math

#include "experience.h"
int mediumFastFunction(int n) { return n * n * n; }

int fastFunction(int n) { return 4 * n * n * n / 5; }

int slowFunction(int n) { return 5 * n * n * n / 4; }

int mediumSlowFunction(int n) {
  int term1 = 6 / 5 * n * n * n;
  int term2 = 15 * n * n;
  int term3 = 100 * n;
  return term1 - term2 + term3 - 140;
}

int erraticFunction(int n) {
  if (n < 50) {
    return (n * n * n * (100 - n)) / 50;
  } else if (n < 68) {
    return (n * n * n * (150 - n)) / 100;
  } else if (n < 98) {
    return (n * n * n * ((1911 - (10 * n)) / 3)) / 500;
  } else {
    return ((n * n * n * (160 - n)) / 100);
  }
}

int flucuatingFunction(int n) {
  if (n < 15) {
    return (n * n * n * (((n + 1) / 3) + 24)) / 50;
  } else if (n < 36) {
    return (n * n * n * (n + 14)) / 50;
  } else {
    return (n * n * n * ((n / 2) + 32)) / 50;
  }
}

int Experience::getEXPNeeded(int level) {
  switch (group) {
  case ExperienceGroups::mediumFast:
    return mediumFastFunction(level);

  case ExperienceGroups::erratic:
    return erraticFunction(level);

  case ExperienceGroups::flucuating:
    return flucuatingFunction(level);

  case ExperienceGroups::mediumSlow:
    return mediumSlowFunction(level);

  case ExperienceGroups::slow:
    return slowFunction(level);

  case ExperienceGroups::fast:
    return fastFunction(level);
  }
}