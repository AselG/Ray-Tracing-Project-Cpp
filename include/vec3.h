
#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

#include "ray_tracing_project.h"

class vec3{
    public:
        double v[3];

        vec3(): v{0,0,0} {}
        vec3(double x, double y, double z): v{x,y,z} {}

        double x() const {return v[0];}
        double y() const {return v[1];}
        double z() const {return v[2];}

        vec3 operator-() const {
            return vec3(-v[0], -v[1], -v[2]);
        }
        double operator[](int i) const {
            return v[i];
        }
        double& operator[](int i) {
            return v[i];
        }
        vec3 operator+=(const vec3& vec){
            v[0] += vec.v[0];
            v[1] += vec.v[1];
            v[2] += vec.v[2];
            return *this;
        }
        vec3 operator*=(const double& a){
            v[0] *= a;
            v[1] *= a;
            v[2] *= a;
            return *this;
        }
        vec3 operator/=(const double& a){
            v[0] /= a;
            v[1] /= a;
            v[2] /= a;
            return *this;
        }

        double length() const {
            double l = sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] );
            return l;
        }

        double length_squared() const {
            double ls = v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
            return ls;
        }

        static vec3 random() {
            return vec3(random_double(), random_double(), random_double());
        }

        static vec3 random(double min, double max) {
            return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
        }

        bool near_zero() {
            double eps = 1e-8;
            return (std::fabs(v[0]) < eps) && (std::fabs(v[1]) < eps) && (std::fabs(v[2]) < eps);
        }
};

// Utility Functions

inline vec3 operator+(const vec3& a, const vec3& b){
    return vec3( a[0] + b[0], a[1] + b[1], a[2] + b[2] );
}
inline vec3 operator-(const vec3& a, const vec3& b){
    return vec3( a[0] - b[0], a[1] - b[1], a[2] - b[2] );
}
inline vec3 operator*(const vec3& a, const vec3& b) {
    return vec3(a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2]);
}
inline vec3 operator*(const vec3& a, const double b){
    return vec3( a[0] * b, a[1] * b, a[2] * b );
}
inline vec3 operator*(const double b, const vec3& a){
    return vec3( a[0] * b, a[1] * b, a[2] * b );
}
inline vec3 operator/(const vec3& a, double b){
    return vec3( a[0] / b, a[1] / b, a[2] / b );
}
inline double dot(const vec3& a, const vec3& b){
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}
inline vec3 cross(const vec3& a, const vec3& b){
    return vec3( a[1]*b[2] - a[2]*b[1], a[2]*b[0] - a[0]*b[2], a[0]*b[1] - a[1]*b[0]);
}
inline vec3 unit_vector(const vec3& a){
    return a / a.length();
}

inline std::ostream& operator<<(std::ostream& cout, const vec3& a){
    return cout << a[0] << ' ' << a[1] << ' ' << a[2];
}

inline vec3 random_unit_vector() {
    while(true) {
        vec3 rand_vec = vec3::random(-1,1);
        double len_sq = rand_vec.length_squared();
        if( len_sq < 1 && len_sq > 0.00000000001) {
            return rand_vec / sqrt(len_sq);
        }
    }
}

inline vec3 random_on_hemisphere(const vec3& norm) {
    vec3 rand_on_unit_sphere = random_unit_vector();
    if(dot(rand_on_unit_sphere, norm) > 0.0) {
        return rand_on_unit_sphere;
    }
    else {
        return -rand_on_unit_sphere;
    }
}

inline vec3 reflection(const vec3& incident, const vec3& normal) {
    // Assume normal to be normalized
    vec3 b = normal * dot(incident, normal);
    return incident - 2*b;
}

using point3 = vec3;


#endif