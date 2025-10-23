#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.h"

class material {
    public:
        virtual ~material() = default;

        virtual bool scatter( const ray& r_in, const hit_record& rec, colour& attenuation, ray& scattered ) const {
            return false;
        }
};

class lambertian : public material {
    public:
        lambertian( const colour& albedo ) : albedo(albedo) {}

        bool scatter( const ray& r_in, const hit_record& rec, colour& attenuation, ray& scattered ) const {
            vec3 scatter_direction = rec.normal + random_unit_vector();

            // Check to make sure vector magnitude isnt too close to zero
            if( scatter_direction.near_zero() ) {
                scatter_direction = rec.normal;
            }

            scattered = ray(rec.p, scatter_direction);
            attenuation = albedo;
            return true;
        }

    private:
        colour albedo;

};

class metal : public material {
    public:
        metal( const colour& albedo, double fuzz ) : albedo(albedo), fuzz( fuzz < 1 ? fuzz : 1 ) {}

        bool scatter( const ray& r_in, const hit_record& rec, colour& attenuation, ray& scattered ) const {
            vec3 refl_vec = reflection(r_in.direction(), rec.normal);
            refl_vec = unit_vector(refl_vec) + random_unit_vector() * fuzz;
            scattered = ray(rec.p, refl_vec);
            attenuation = albedo;
            return true;
        }

    private:
        colour albedo; 
        double fuzz;
};

#endif