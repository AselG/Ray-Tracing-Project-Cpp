#ifndef VEC4_H
#define VEC4_H

#include <cmath>

#include "ray_tracing_project.h"

class vec4{
    public:
        double v[4];

        vec4(): v{0,0,0,0} {}
        vec4(double x, double y, double z, double w): v{x,y,z,w} {}
        vec4(vec3 v3, double w): v{v3.x(), v3.y(), v3.z(), w} {}

        double x() const {return v[0];}
        double y() const {return v[1];}
        double z() const {return v[2];}
        double w() const {return v[3];}

        vec4 operator-() const {
            return vec4(-v[0], -v[1], -v[2], -v[3]);
        }
        double operator[](int i) const {
            return v[i];
        }
        double operator[](int i) {
            return v[i];
        }

        vec4 operator+=(const vec3& vec) {
            v[0] += vec.v[0];
            v[1] += vec.v[1];
            v[2] += vec.v[2];
            v[3] += vec.v[3];
            return *this;
        }
        vec4 operator*=(const double& a) {
            v[0] *= a;
            v[1] *= a;
            v[2] *= a;
            v[3] *= a;
            return *this;
        }
        vec4 operator/=(const double& a){
            v[0] /= a;
            v[1] /= a;
            v[2] /= a;
            v[3] /= a;
            return *this;
        }
};

// Utility functions

inline vec4 operator+(const vec4& a, const vec4& b){
    return vec4( a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3] );
}
inline vec4 operator-(const vec4& a, const vec4& b){
    return vec4( a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3] );
}
inline vec4 operator*(const vec4& a, const double b){
    return vec4( a[0] * b, a[1] * b, a[2] * b, a[3] * b );
}
inline vec4 operator*(const double b, const vec4& a){
    return vec4( a[0] * b, a[1] * b, a[2] * b, a[3] * b );
}
inline vec4 operator/(const vec4& a, double b){
    return vec4( a[0] / b, a[1] / b, a[2] / b, a[3] / b );
}
inline double dot(const vec4& a, const vec4& b){
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
}

inline std::ostream& operator<<(std::ostream& cout, const vec4& a) {
    return cout << a[0] << ' ' << a[1] << ' ' << a[2];
}

#endif