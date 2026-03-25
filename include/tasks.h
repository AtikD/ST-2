// Copyright 2026 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolCosts {
  double concreteCost;
  double fenceCost;
  double totalCost;
};

double getEarthRopeGap(double earthRadiusKm = 6378.1,
                       double addedRopeLengthMeters = 1.0);

PoolCosts calculatePoolCosts(double poolRadius = 3.0,
                             double trackWidth = 1.0,
                             double concreteCostPerSqMeter = 1000.0,
                             double fenceCostPerMeter = 2000.0);

#endif  // INCLUDE_TASKS_H_
