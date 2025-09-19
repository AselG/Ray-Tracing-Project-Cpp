#ifndef INTERVAL_H
#define INTERVAL_H

#include "ray_tracing_project.h"

class interval{
    public:
        double min,max;

        interval() : min(infinity), max(-infinity) {} // Default constructor makes empty interval

        interval(double min, double max) : min(min), max(max) {}

        double size() const {
            return max - min;
        }

        bool contains(double a) const {
            return (a >= min) && (a <= max);
        }

        bool surrounds(double a) const {
            return (a > min) && (a < max);
        }

        double clamp(double a) const {
            if(a < min) return min;
            if(a > max) return max;
            return a;
        }

        static const interval empty, universe;
};

const interval interval::empty = interval(infinity, -infinity);
const interval interval::universe = interval(-infinity, infinity);

#endif