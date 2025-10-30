#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "mesh.h"
#include "hittable.h"
#include "ray.h"

class model : public hittable {
    public:
        model(std::shared_ptr<mesh> m, std::shared_ptr<material> mat) : m(m), mat(mat) {}

        bool hit(const ray& r, interval ray_t, hit_record& rec ) const override {
            if(m->ray_intersection(r, ray_t, rec)) {
                rec.mat = mat;
                return true;
            }

            return false;
        }

    private:
        std::shared_ptr<mesh> m;
        std::shared_ptr<material> mat;
};

#endif