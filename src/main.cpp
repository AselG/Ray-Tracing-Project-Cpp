#include "ray_tracing_project.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "triangle.h"
#include "material.h"

int main() {
    hittable_list world;

    auto material_default = std::make_shared<lambertian>(colour(0.5, 0.2, 0.5));

    std::array<point3, 3> t1_verts = { 
        point3( 0.0, 0.9, -2.2), 
        point3(-1.0, 0.0, -2.0), 
        point3( 1.0, 0.0, -2.0) 
    };
    world.add(std::make_shared<triangle>(t1_verts, material_default));

    // --- Camera ---
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 1720;
    cam.samples_per_pixel = 200;
    cam.max_recursion_depth = 20;

    cam.render(world);
}
