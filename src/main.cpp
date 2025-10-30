#include "ray_tracing_project.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "triangle.h"
#include "material.h"
#include "model.h"
#include "mesh.h"

int main() {
    hittable_list world;

    auto material_default = std::make_shared<lambertian>(colour(0.5, 0.2, 0.5));

    auto material_ground = std::make_shared<lambertian>(colour(0.8, 0.8, 0.0));
    auto material_center = std::make_shared<lambertian>(colour(0.1, 0.2, 0.5));
    auto material_left   = std::make_shared<metal>(colour(0.8, 0.8, 0.8), 0.05);
    auto material_right  = std::make_shared<metal>(colour(0.6, 0.6, 0.9), 0.99);

    auto tetrahedron_mesh = std::make_shared<mesh>();
    tetrahedron_mesh->load_from_obj("/Users/aselgamage/Workspace/Ray_Tracing_Project/Ray-Tracing-Project-Cpp/objects/tetrahedron.obj");
    world.add(std::make_shared<model>(tetrahedron_mesh, material_left));

    world.add(std::make_shared<sphere>(point3( 0.0, -100.5, -2.0), 100.0, material_ground));
    //world.add(std::make_shared<sphere>(point3( 0.0,    0.0, -2.2),   0.5, material_center));
    //world.add(std::make_shared<sphere>(point3(-1.0,    0.0, -2.0),   0.5, material_left));
    //world.add(std::make_shared<sphere>(point3( 1.0,    0.0, -2.0),   0.5, material_right));

    // --- Camera ---
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 1720;
    cam.samples_per_pixel = 10;
    cam.max_recursion_depth = 5;

    cam.render(world);
}
