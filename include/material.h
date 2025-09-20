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
        metal( const colour& albedo ) : albedo(albedo) {}

        bool scatter( const ray& r_in, const hit_record& rec, colour& attenuation, ray& scattered ) const {
            scattered = ray(rec.p, reflection(r_in.direction(), rec.normal));
            attenuation = albedo;
            return true;
        }

    private:
        colour albedo; 
};

#endif