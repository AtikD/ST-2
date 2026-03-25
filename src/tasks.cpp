// Copyright 2026 UNN-CS
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

double getEarthRopeGap(double earthRadiusKm, double addedRopeLengthMeters) {
  if (earthRadiusKm <= 0.0) {
    throw std::invalid_argument("Earth radius must be positive");
  }
  if (addedRopeLengthMeters <= 0.0) {
    throw std::invalid_argument("Added rope length must be positive");
  }

  const double earthRadiusMeters = earthRadiusKm * 1000.0;
  Circle earth(earthRadiusMeters);
  const double initialFerence = earth.getFerence();

  earth.setFerence(initialFerence + addedRopeLengthMeters);
  return earth.getRadius() - earthRadiusMeters;
}

PoolCosts calculatePoolCosts(double poolRadius,
                             double trackWidth,
                             double concreteCostPerSqMeter,
                             double fenceCostPerMeter) {
  if (poolRadius <= 0.0) {
    throw std::invalid_argument("Pool radius must be positive");
  }
  if (trackWidth <= 0.0) {
    throw std::invalid_argument("Track width must be positive");
  }
  if (concreteCostPerSqMeter < 0.0) {
    throw std::invalid_argument("Concrete cost cannot be negative");
  }
  if (fenceCostPerMeter < 0.0) {
    throw std::invalid_argument("Fence cost cannot be negative");
  }

  Circle pool(poolRadius);
  Circle outer(poolRadius + trackWidth);

  const double walkwayArea = outer.getArea() - pool.getArea();
  const double concreteCost = walkwayArea * concreteCostPerSqMeter;
  const double fenceCost = outer.getFerence() * fenceCostPerMeter;

  return {concreteCost, fenceCost, concreteCost + fenceCost};
}
