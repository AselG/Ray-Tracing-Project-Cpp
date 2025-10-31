#ifndef MAT4_H
#define MAT4_H

#include <initializer_list>
#include <cmath>

#include "ray_tracing_project.h"

class mat4{
    public:
        double m[4][4];

        mat4();
        explicit mat4(double diag);
        mat4(std::initializer_list<double> values);

        mat4 transpose() const;
        mat4 inverse() const;

        static mat4 identity();
        static mat4 translation(const vec3& t);
        static mat4 scale(double sx, double sy, double sz);
        static mat4 rotation_x(double rad);
        static mat4 rotation_y(double rad);
        static mat4 rotation_z(double rad);

};

// Zero matrix constructor
mat4::mat4() {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            m[i][j] = 0.0;
        }
    }
}

// Diagonal matrix constructor
mat4::mat4(double diag) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            m[i][j] = (i==j) ? diag : 0.0;
        }
    }
}

// From initializer list
mat4::mat4(std::initializer_list<double> values) {
    int i=0;
    for(double val : values) {
        m[i/4][i%4] = val;
        i++;
    }
}

// Matrix operations
inline vec4 operator*(const mat4& m, const vec4& v) {
    return vec4(
        m.m[0][0] * v.x() + m.m[0][1] * v.y() + m.m[0][2] * v.z() + m.m[0][3] + v.w(),
        m.m[1][0] * v.x() + m.m[1][1] * v.y() + m.m[1][2] * v.z() + m.m[1][3] + v.w(),
        m.m[2][0] * v.x() + m.m[2][1] * v.y() + m.m[2][2] * v.z() + m.m[2][3] + v.w(),
        m.m[3][0] * v.x() + m.m[3][1] * v.y() + m.m[3][2] * v.z() + m.m[3][3] + v.w()
    );
}
inline mat4 operator*(const mat4& lhs, const mat4& rhs) {
    mat4 ret_mat;
    for(size_t r=0; r<4; r++) {
        for(size_t c=0; c<4; c++) {
            for(size_t k=0; k<4; k++) {
                ret_mat.m[r][c] += lhs.m[r][k] * rhs.m[k][c];
            }
        }
    }
    return ret_mat;
}

mat4 mat4::transpose() const {
    mat4 ret_mat;
    for(size_t r=0; r<4; r++) {
        for(size_t c=0; c<4; c++) {
            ret_mat.m[r][c] = m[c][r];
        }
    }
    return ret_mat;
}
mat4 mat4::inverse() const {
    mat4 ret_mat;
    
}

// Common matrices and transformations
mat4 mat4::identity() {
    return mat4(1.0);
}

mat4 mat4::translation(const vec3& t) {
    mat4 ret_mat = identity();
    ret_mat.m[0][3] = t.x();
    ret_mat.m[1][3] = t.y();
    ret_mat.m[2][3] = t.z();
    return ret_mat;
}

mat4 mat4::scale(double sx, double sy, double sz) {
    mat4 ret_mat = mat4();
    ret_mat.m[0][0] = sx;
    ret_mat.m[1][1] = sy;
    ret_mat.m[2][2] = sz;
    ret_mat.m[3][3] = 1.0;
    return ret_mat;
}

mat4 mat4::rotation_x(double rad) {
    double c = std::cos(rad);
    double s = std::sin(rad);
    mat4 ret_mat = identity();
    ret_mat.m[1][1] = c;
    ret_mat.m[1][2] = s;
    ret_mat.m[2][2] = c;
    ret_mat.m[2][1] = -s;
    return ret_mat;
}

mat4 mat4::rotation_y(double rad) {
    double c = std::cos(rad);
    double s = std::sin(rad);
    mat4 ret_mat = identity();
    ret_mat.m[1][1] = c;
    ret_mat.m[1][2] = s;
    ret_mat.m[2][2] = c;
    ret_mat.m[2][1] = -s;
    return ret_mat;
}

mat4 mat4::rotation_z(double rad) {
    double c = std::cos(rad);
    double s = std::sin(rad);
    mat4 ret_mat = identity();
    ret_mat.m[0][0] = c;
    ret_mat.m[0][1] = -s;
    ret_mat.m[1][1] = c;
    ret_mat.m[1][0] = s;
    return ret_mat;
}

#endif