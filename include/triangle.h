#ifndef TRIANGLE_H
#define SPHERE_H

#include "ray_tracing_project.h"
#include "hittable.h"
#include "vec3.h"
#include "ray.h"
#include "array"

class triangle : public hittable {
    public:
        triangle( const std::array<point3, 3> vertices, std::shared_ptr<material> mat )
            : vertices(vertices), mat(mat) {}

        bool hit( const ray& r, interval ray_t, hit_record& rec ) const override {
            vec3 e1 = vec3(vertices[1] - vertices[0]); // edge from vertex 1 to vertex 2
            vec3 e2 = vec3(vertices[2] - vertices[0]); // edge from vertex 1 to 3
            vec3 r_cross_e2 = cross(r.direction(), e2); // vector normal to plane triangle exists on

            double det = dot(e1, r_cross_e2);
            if( fabs(det) < epsilon ) {
                return false;   // ray parallel to triangle
            }

            double inv_det = 1.0 / det;
            vec3 s = r.origin() - vertices[0];
            double u = inv_det * dot(s, r_cross_e2);
            if( (u < 0 && abs(u) > epsilon) || (u > 1 && abs(u-1) > epsilon) ){
                return false;
            }

            vec3 s_cross_e1 = cross(s, e1);
            double v = inv_det * dot(r.direction(), s_cross_e1);
            if( u < 0 || u > 1 || v < 0 || u + v > 1 ){
                return false;
            }

            // Can now compute t for intersection
            double t = inv_det * dot(e2, s_cross_e1);

            if( !ray_t.surrounds(t) ) {
                return false;
            }

            // Store hit info in rec
            rec.t = t;
            rec.p = r.at(t);
            rec.mat = mat;
            vec3 outward_normal = unit_vector(cross(e1, e2));
            rec.set_face_normal(r, outward_normal);

            return true;

        }

    private:
        std::array<point3, 3> vertices;
        std::shared_ptr<material> mat;
};

#endif