#ifndef COLOUR_H
#define COLOUR_H

#include <iostream>

#include "vec3.h"
#include "interval.h"

using colour = vec3;

void write_colour(std::ostream& out, const colour& col){
    auto r = col.x();
    auto g = col.y();
    auto b = col.z();

    // Pixel colour values stored in range [0,1], need to scale this to [0,255]
    static const interval intensity(0.000, 0.999);
    int ir = int(intensity.clamp(r) * 256);
    int ig = int(intensity.clamp(g) * 256);
    int ib = int(intensity.clamp(b) * 256);

    out << ir << ' ' << ig << ' ' << ib << "\n";
}

#endif