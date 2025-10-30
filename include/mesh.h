#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "triangle.h"
#include "ray.h"

class mesh {
    public:
        mesh() {}
        ~mesh() = default;

        void load_from_obj(std::string file) {
            // Define bounding box
            bounds_min = point3(infinity, infinity, infinity);
            bounds_max = point3(-infinity, -infinity, -infinity);

            std::ifstream fin(file);
            if( !fin.is_open() ) {
                std::clog << "Unable to open obj file." << std::endl;
                return;
            }

            std::string line;
            std::vector<point3> vertices;
            while (std::getline(fin, line)) {
                std::istringstream iss(line);
                std::string prefix;
                iss >> prefix;

                // Vertex
                if (prefix == "v") {
                    double x,y,z;
                    iss >> x >> y >> z;
                    vertices.emplace_back(x,y,z);
                    bounds_min = point3( std::min(bounds_min.x(), x), std::min(bounds_min.y(), y), std::min(bounds_min.z(), z) );
                    bounds_max = point3( std::max(bounds_max.x(), x), std::max(bounds_max.y(), y), std::max(bounds_max.z(), z) );
                }

                // Face
                if (prefix == "f") {
                    // prefix followed by list of vertices 
                    // f 1 2 3 4 ...
                    std::vector<int> indices;
                    std::string vertex_token;

                    // Loop through every vertex listed
                    while (iss >> vertex_token) {
                        // each vertex in form 1, 1/1, 1//1, 1/1/1
                        std::istringstream vss(vertex_token);
                        std::string index_str;
                        std::getline(vss, index_str, '/');
                        int vertex_index = std::stoi(index_str) - 1;
                        indices.push_back(vertex_index);
                    }

                    // Create triangle objects using list of vertices and indices
                    if ( indices.size() <= 1 ) {
                        continue;
                    }
                    for(size_t i=1; i<indices.size()-1; i++) {
                        // Turn polygon face into set of triangles and add to vector
                        point3 v1 = vertices[indices[0]];
                        point3 v2 = vertices[indices[i]];
                        point3 v3 = vertices[indices[i+1]];
                        triangles.emplace_back(std::make_shared<triangle>(v1, v2, v3));

                    }
                }

            }

        }

        bool ray_intersection(const ray& r, interval ray_t, hit_record& rec) {
            hit_record temp_rec;
            bool hit_anything = false;
            double closest_hit = ray_t.max;

            // TODO: Check if ray passes through bounded box first

            for(const auto& triangle : triangles) {
                if(triangle->ray_intersection(r, interval( ray_t.min, closest_hit) , temp_rec)) {
                    hit_anything = true;
                    closest_hit = temp_rec.t;
                    rec = temp_rec;
                }
            }

            return hit_anything;

        }

    private:
        std::vector<std::shared_ptr<triangle>> triangles;
        int num_triangles;
        point3 bounds_min;
        point3 bounds_max;

};

#endif