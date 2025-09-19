#ifndef CAMERA_H
#define CAMERA_H

#include "hittable.h"

class camera{
    public:
        double aspect_ratio = 1.0;
        int image_width = 100;
        int samples_per_pixel = 10;
        int max_recursion_depth = 10;

        void render(const hittable& world) {
            initialize();

            // PPM Format:
            // First line indicates colour formatting (P3 for ASCII format)
            // Second line indicates number of rows and columns
            // Fourth line indicates max colour value (typically 255)
            // Each following line represents one row of image, each pixel described by RGB triplet

            // Render:

            std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

            for(int i=0;i<image_height;i++){
                std::clog << "\rPixel rows remaining: " << (image_height - i) << ' ' << std::flush;
                for(int j=0;j<image_width;j++){
                    colour pixel_col = colour(0,0,0);
                    for(int sample=0; sample<samples_per_pixel; sample++){
                        ray r = get_ray(i,j);
                        pixel_col += ray_colour(r, max_recursion_depth, world);
                    }
                    // Write colour to cout stream
                    write_colour(std::cout, pixel_samples_scale * pixel_col);
                }
            }

            std::clog << "\rDone.\n";
        }

    private:
        int image_height;
        double pixel_samples_scale;
        point3 centre;
        point3 pixel_top_left_pos;
        vec3 pixel_delta_u;
        vec3 pixel_delta_v;

        void initialize() {
            image_height = int(image_width / aspect_ratio);
            image_height = (image_height < 1) ? 1 : image_height;

            pixel_samples_scale = 1.0 / samples_per_pixel;
            
            centre = point3(0, 0, 0);

            double focal_length = 1.0;
            double viewport_height = 2.0;
            double viewport_width = viewport_height * (double(image_width) / image_height);

            vec3 viewport_u = vec3(viewport_width, 0, 0);
            vec3 viewport_v = vec3(0, -viewport_height, 0);

            pixel_delta_u = viewport_u / image_width;
            pixel_delta_v = viewport_v / image_height;

            point3 viewport_top_left = centre - viewport_u/2 - viewport_v/2 - vec3(0, 0, focal_length);
            pixel_top_left_pos = viewport_top_left + pixel_delta_u/2 + pixel_delta_v/2;
        }

        colour ray_colour( const ray& r, int depth, const hittable& world ) const {

            if(depth <= 0) {
                return colour(0,0,0);
            }

            hit_record rec;
            if( world.hit(r, interval(0.001, infinity), rec) ) {
                vec3 direction = rec.normal + random_unit_vector();
                return 0.5 * ray_colour( ray(rec.p, direction), depth-1, world );
            }

            vec3 unit_direction = unit_vector(r.direction());
            auto a = 0.5*(unit_direction.y() + 1.0);
            return (1.0-a)*colour(1.0, 1.0, 1.0) + a*colour(0.5, 0.7, 1.0);
        }

        ray get_ray(int i, int j) const {
            // Generate random point in unit square
            point3 offset = sample_square();
            
            point3 pixel_sample_pos = pixel_top_left_pos + (pixel_delta_u*(j+offset.x())) + (pixel_delta_v*(i+offset.y()));
            vec3 ray_dir = pixel_sample_pos - centre;
            
            return ray(centre, ray_dir);
        }

        vec3 sample_square() const {
            // Returns vector to random point in unit square centered at (0,0)
            return vec3(random_double()-0.5, random_double()-0.5, 0);
        }
};

#endif