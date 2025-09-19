
#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class vec3{
    private:
        double v[3];

    public:
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

};

// Utility Functions

inline vec3 operator+(const vec3& a, const vec3& b){
    return vec3( a[0] + b[0], a[1] + b[1], a[2] + b[2] );
}
inline vec3 operator-(const vec3& a, const vec3& b){
    return vec3( a[0] - b[0], a[1] - b[1], a[2] - b[2] );
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

using point3 = vec3;


#endif