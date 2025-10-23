// File to store code used to previously generated images

// ------------------- SCENE 1 ----------------------

/* 

    auto material_ground = std::make_shared<lambertian>(colour(0.8, 0.8, 0.0));
    auto material_center = std::make_shared<lambertian>(colour(0.1, 0.2, 0.5));
    auto material_left   = std::make_shared<metal>(colour(0.8, 0.8, 0.8), 0.05);
    auto material_right  = std::make_shared<metal>(colour(0.6, 0.6, 0.9), 0.99);

    world.add(std::make_shared<sphere>(point3( 0.0, -100.5, -2.0), 100.0, material_ground));
    world.add(std::make_shared<sphere>(point3( 0.0,    0.0, -2.2),   0.5, material_center));
    world.add(std::make_shared<sphere>(point3(-1.0,    0.0, -2.0),   0.5, material_left));
    world.add(std::make_shared<sphere>(point3( 1.0,    0.0, -2.0),   0.5, material_right));

*/

// ------------------- SCENE 2 ----------------------

/*

    auto material_ground = std::make_shared<lambertian>(colour(0.8, 0.8, 0.0));
    auto material_center = std::make_shared<lambertian>(colour(0.1, 0.2, 0.5));
    auto material_left   = std::make_shared<metal>(colour(0.8, 0.8, 0.8), 0.05);
    auto material_right  = std::make_shared<metal>(colour(0.6, 0.6, 0.9), 0.99);

    world.add(std::make_shared<sphere>(point3( 0.0, -100.5, -2.0), 100.0, material_ground));
    world.add(std::make_shared<sphere>(point3( 0.0,    0.0, -2.2),   0.5, material_center));
    world.add(std::make_shared<sphere>(point3(-1.0,    0.0, -2.0),   0.5, material_left));
    world.add(std::make_shared<sphere>(point3( 1.0,    0.0, -2.0),   0.5, material_right));

    // Camera
    camera cam;

    cam.aspect_ratio = 16.0/9.0;
    cam.image_width = 1720;
    cam.samples_per_pixel = 250;
    cam.max_recursion_depth = 100;

    cam.render(world);
}

*/



// ------------------- SCENE 3 ----------------------

/*

// --- Materials ---
    auto ground_mat = std::make_shared<lambertian>(colour(0.6, 0.6, 0.55));
    auto mirror     = std::make_shared<metal>(colour(0.95, 0.95, 0.95), 0.0);
    auto bronze     = std::make_shared<metal>(colour(0.8, 0.6, 0.4), 0.1);
    auto steel      = std::make_shared<metal>(colour(0.7, 0.7, 0.8), 0.05);
    auto blue_steel = std::make_shared<metal>(colour(0.6, 0.6, 0.9), 0.15);
    auto rose_metal = std::make_shared<metal>(colour(0.9, 0.6, 0.7), 0.25);
    auto copper     = std::make_shared<metal>(colour(0.9, 0.55, 0.35), 0.12);

    auto red_mat    = std::make_shared<lambertian>(colour(0.8, 0.2, 0.2));
    auto blue_mat   = std::make_shared<lambertian>(colour(0.2, 0.2, 0.8));
    auto green_mat  = std::make_shared<lambertian>(colour(0.2, 0.8, 0.2));
    auto purple_mat = std::make_shared<lambertian>(colour(0.6, 0.2, 0.8));
    auto cyan_mat   = std::make_shared<lambertian>(colour(0.2, 0.8, 0.8));

    // --- Ground ---
    world.add(std::make_shared<sphere>(point3(0.0, -10001.5, -10.0), 10000.0, ground_mat));

    double base_y = -1.5;

    // --- Central reflective sphere ---
    world.add(std::make_shared<sphere>(point3(0.0, base_y + 1.0, -4.0), 1.0, mirror));

    // --- Slightly dispersed center cluster (|x| ≤ 4, z = -2.5 to -5.5) ---
    world.add(std::make_shared<sphere>(point3(-1.5, base_y + 0.2, -3.3), 0.2, steel));
    world.add(std::make_shared<sphere>(point3(1.5, base_y + 0.18, -4.3), 0.18, copper));
    world.add(std::make_shared<sphere>(point3(-2.4, base_y + 0.15, -3.8), 0.15, bronze));
    world.add(std::make_shared<sphere>(point3(2.3, base_y + 0.2, -4.8), 0.2, blue_mat));
    world.add(std::make_shared<sphere>(point3(-3.2, base_y + 0.12, -3.2), 0.12, red_mat));
    world.add(std::make_shared<sphere>(point3(3.1, base_y + 0.25, -5.0), 0.25, rose_metal));
    world.add(std::make_shared<sphere>(point3(-2.8, base_y + 0.1, -4.5), 0.1, purple_mat));
    world.add(std::make_shared<sphere>(point3(2.5, base_y + 0.2, -3.5), 0.2, green_mat));
    world.add(std::make_shared<sphere>(point3(-1.8, base_y + 0.14, -4.6), 0.14, blue_steel));
    world.add(std::make_shared<sphere>(point3(1.8, base_y + 0.18, -3.6), 0.18, cyan_mat));
    world.add(std::make_shared<sphere>(point3(-0.8, base_y + 0.2, -5.2), 0.2, copper));
    world.add(std::make_shared<sphere>(point3(0.8, base_y + 0.15, -3.3), 0.15, bronze));
    world.add(std::make_shared<sphere>(point3(-3.6, base_y + 0.22, -4.4), 0.22, steel));
    world.add(std::make_shared<sphere>(point3(3.6, base_y + 0.12, -4.2), 0.12, red_mat));
    world.add(std::make_shared<sphere>(point3(-2.1, base_y + 0.18, -3.1), 0.18, rose_metal));
    world.add(std::make_shared<sphere>(point3(2.1, base_y + 0.2, -5.1), 0.2, green_mat));
    world.add(std::make_shared<sphere>(point3(-1.1, base_y + 0.15, -4.1), 0.15, blue_steel));
    world.add(std::make_shared<sphere>(point3(1.1, base_y + 0.1, -5.3), 0.1, cyan_mat));
    //world.add(std::make_shared<sphere>(point3(-0.4, base_y + 0.16, -3.7), 0.16, purple_mat));
    world.add(std::make_shared<sphere>(point3(0.4, base_y + 0.18, -4.4), 0.18, steel));

    // --- More spheres *in front* of the central sphere (z = -1.2 to -2.5) ---
    world.add(std::make_shared<sphere>(point3(-2.0, base_y + 0.12, -1.8), 0.12, copper));
    world.add(std::make_shared<sphere>(point3(1.8, base_y + 0.2, -2.0), 0.2, rose_metal));
    world.add(std::make_shared<sphere>(point3(-1.0, base_y + 0.18, -2.3), 0.18, blue_mat));
    world.add(std::make_shared<sphere>(point3(1.0, base_y + 0.15, -2.5), 0.15, green_mat));
    world.add(std::make_shared<sphere>(point3(-3.0, base_y + 0.1, -2.0), 0.1, red_mat));
    world.add(std::make_shared<sphere>(point3(3.0, base_y + 0.22, -1.6), 0.22, cyan_mat));
    world.add(std::make_shared<sphere>(point3(-4.0, base_y + 0.2, -1.8), 0.2, purple_mat));
    world.add(std::make_shared<sphere>(point3(4.0, base_y + 0.18, -2.0), 0.18, bronze));
    world.add(std::make_shared<sphere>(point3(-1.5, base_y + 0.12, -1.3), 0.12, blue_steel));
    world.add(std::make_shared<sphere>(point3(1.5, base_y + 0.1, -1.4), 0.1, steel));
    world.add(std::make_shared<sphere>(point3(0.0, base_y + 0.2, -1.5), 0.2, green_mat));
    world.add(std::make_shared<sphere>(point3(-0.6, base_y + 0.16, -2.2), 0.16, rose_metal));
    world.add(std::make_shared<sphere>(point3(0.6, base_y + 0.18, -1.7), 0.18, copper));

    // --- Mid-distance fillers (z = -5.5 to -6.5) ---
    world.add(std::make_shared<sphere>(point3(-6.5, base_y + 0.15, -6.0), 0.15, steel));
    world.add(std::make_shared<sphere>(point3(6.5, base_y + 0.18, -6.3), 0.18, green_mat));
    world.add(std::make_shared<sphere>(point3(-5.5, base_y + 0.12, -6.2), 0.12, blue_mat));
    world.add(std::make_shared<sphere>(point3(5.5, base_y + 0.1, -5.9), 0.1, rose_metal));
    world.add(std::make_shared<sphere>(point3(-4.5, base_y + 0.18, -6.4), 0.18, bronze));
    world.add(std::make_shared<sphere>(point3(4.5, base_y + 0.2, -6.0), 0.2, copper));
    world.add(std::make_shared<sphere>(point3(-3.5, base_y + 0.16, -5.8), 0.16, red_mat));
    world.add(std::make_shared<sphere>(point3(3.5, base_y + 0.12, -6.2), 0.12, cyan_mat));

    // --- Removed rear corners; density smoothly decreases beyond |x| > 6 or z < -6.5 ---
    // (previous back-left/back-right spheres omitted)

    // ~90–100 total spheres.
    // Densest zone around (x,z) ≈ (0, -3.5), dispersed slightly outward.
    // Higher sphere count in front region (z = -1.5 to -2.5) to fill visual foreground.

*/