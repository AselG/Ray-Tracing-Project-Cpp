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
    //
    // Inversion by Cramer's rule.  Code taken from an Intel publication
    //
    double Result[4][4];
    double tmp[12]; /* temp array for pairs */
    double src[16]; /* array of transpose source matrix */
    double det; /* determinant */
    /* transpose matrix */
    for (size_t i = 0; i < 4; i++) {
        src[i + 0 ] = m[i][0];
        src[i + 4 ] = m[i][1];
        src[i + 8 ] = m[i][2];
        src[i + 12] = m[i][3];
    }
    /* calculate pairs for first 8 elements (cofactors) */
    tmp[0] = src[10] * src[15];
    tmp[1] = src[11] * src[14];
    tmp[2] = src[9] * src[15];
    tmp[3] = src[11] * src[13];
    tmp[4] = src[9] * src[14];
    tmp[5] = src[10] * src[13];
    tmp[6] = src[8] * src[15];
    tmp[7] = src[11] * src[12];
    tmp[8] = src[8] * src[14];
    tmp[9] = src[10] * src[12];
    tmp[10] = src[8] * src[13];
    tmp[11] = src[9] * src[12];
    /* calculate first 8 elements (cofactors) */
    Result[0][0] = tmp[0]*src[5] + tmp[3]*src[6] + tmp[4]*src[7];
    Result[0][0] -= tmp[1]*src[5] + tmp[2]*src[6] + tmp[5]*src[7];
    Result[0][1] = tmp[1]*src[4] + tmp[6]*src[6] + tmp[9]*src[7];
    Result[0][1] -= tmp[0]*src[4] + tmp[7]*src[6] + tmp[8]*src[7];
    Result[0][2] = tmp[2]*src[4] + tmp[7]*src[5] + tmp[10]*src[7];
    Result[0][2] -= tmp[3]*src[4] + tmp[6]*src[5] + tmp[11]*src[7];
    Result[0][3] = tmp[5]*src[4] + tmp[8]*src[5] + tmp[11]*src[6];
    Result[0][3] -= tmp[4]*src[4] + tmp[9]*src[5] + tmp[10]*src[6];
    Result[1][0] = tmp[1]*src[1] + tmp[2]*src[2] + tmp[5]*src[3];
    Result[1][0] -= tmp[0]*src[1] + tmp[3]*src[2] + tmp[4]*src[3];
    Result[1][1] = tmp[0]*src[0] + tmp[7]*src[2] + tmp[8]*src[3];
    Result[1][1] -= tmp[1]*src[0] + tmp[6]*src[2] + tmp[9]*src[3];
    Result[1][2] = tmp[3]*src[0] + tmp[6]*src[1] + tmp[11]*src[3];
    Result[1][2] -= tmp[2]*src[0] + tmp[7]*src[1] + tmp[10]*src[3];
    Result[1][3] = tmp[4]*src[0] + tmp[9]*src[1] + tmp[10]*src[2];
    Result[1][3] -= tmp[5]*src[0] + tmp[8]*src[1] + tmp[11]*src[2];
    /* calculate pairs for second 8 elements (cofactors) */
    tmp[0] = src[2]*src[7];
    tmp[1] = src[3]*src[6];
    tmp[2] = src[1]*src[7];
    tmp[3] = src[3]*src[5];
    tmp[4] = src[1]*src[6];
    tmp[5] = src[2]*src[5];

    tmp[6] = src[0]*src[7];
    tmp[7] = src[3]*src[4];
    tmp[8] = src[0]*src[6];
    tmp[9] = src[2]*src[4];
    tmp[10] = src[0]*src[5];
    tmp[11] = src[1]*src[4];
    /* calculate second 8 elements (cofactors) */
    Result[2][0] = tmp[0]*src[13] + tmp[3]*src[14] + tmp[4]*src[15];
    Result[2][0] -= tmp[1]*src[13] + tmp[2]*src[14] + tmp[5]*src[15];
    Result[2][1] = tmp[1]*src[12] + tmp[6]*src[14] + tmp[9]*src[15];
    Result[2][1] -= tmp[0]*src[12] + tmp[7]*src[14] + tmp[8]*src[15];
    Result[2][2] = tmp[2]*src[12] + tmp[7]*src[13] + tmp[10]*src[15];
    Result[2][2] -= tmp[3]*src[12] + tmp[6]*src[13] + tmp[11]*src[15];
    Result[2][3] = tmp[5]*src[12] + tmp[8]*src[13] + tmp[11]*src[14];
    Result[2][3] -= tmp[4]*src[12] + tmp[9]*src[13] + tmp[10]*src[14];
    Result[3][0] = tmp[2]*src[10] + tmp[5]*src[11] + tmp[1]*src[9];
    Result[3][0] -= tmp[4]*src[11] + tmp[0]*src[9] + tmp[3]*src[10];
    Result[3][1] = tmp[8]*src[11] + tmp[0]*src[8] + tmp[7]*src[10];
    Result[3][1] -= tmp[6]*src[10] + tmp[9]*src[11] + tmp[1]*src[8];
    Result[3][2] = tmp[6]*src[9] + tmp[11]*src[11] + tmp[3]*src[8];
    Result[3][2] -= tmp[10]*src[11] + tmp[2]*src[8] + tmp[7]*src[9];
    Result[3][3] = tmp[10]*src[10] + tmp[4]*src[8] + tmp[9]*src[9];
    Result[3][3] -= tmp[8]*src[9] + tmp[11]*src[10] + tmp[5]*src[8];
    /* calculate determinant */
    det=src[0]*Result[0][0]+src[1]*Result[0][1]+src[2]*Result[0][2]+src[3]*Result[0][3];
    /* calculate matrix inverse */
    det = 1.0f / det;

    mat4 ret_mat;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            ret_mat.m[i][j] = float(Result[i][j] * det);
        }
    }
    return ret_mat;

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