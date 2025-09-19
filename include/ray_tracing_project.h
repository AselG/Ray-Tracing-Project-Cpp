#ifndef PROJECT_5_H
#define PROJECT_5_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

// CONSTANTS

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// UTILITY FUNCTIONS

inline double deg_to_rad( double deg ) {
    return deg / 180 * pi;
}

inline double random_double() {
    return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    return min + (max-min)*random_double();
}

// COMMON HEADERS

#include "colour.h"
#include "ray.h"
#include "vec3.h"
#include "limits"

#endif