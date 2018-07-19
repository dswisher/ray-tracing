
#include <iostream>
#include <random>
#include "camera.h"
#include "sphere.h"
#include "hitable_list.h"
#include "float.h"

// TODO - figure out a better way to make randomness available - globals are icky
std::mt19937 chaos(316);    // use a set seed to be deterministic
std::uniform_real_distribution<> dist(0.0, 1.0);


vec3 random_in_unit_sphere()
{
    vec3 p;
    do
    {
        p = 2.0 * vec3(dist(chaos), dist(chaos), dist(chaos)) - vec3(1, 1, 1);
    } while (p.squared_length() > 1.0);

    return p;
}


vec3 color(const ray& r, hitable *world)
{
    hit_record rec;
    if (world->hit(r, 0.001, MAXFLOAT, rec))
    {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5 * color(ray(rec.p, target - rec.p), world);
    }

    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}


int main() {

    int nx = 200;
    int ny = 100;
    int ns = 100;
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    hitable *list[2];
    list[0] = new sphere(vec3(0, 0, -1), 0.5);
    list[1] = new sphere(vec3(0, -100.5, -1), 100);
    hitable *world = new hitable_list(list, 2);

    camera cam;

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = nx - 1; i >= 0; i--) {
            vec3 col(0, 0, 0);
            for (int s = 0; s < ns; s++)
            {
                float u = float(i + dist(chaos)) / float(nx);
                float v = float(j + dist(chaos)) / float(ny);

                ray r = cam.get_ray(u, v);
                // vec3 p = r.point_at_parameter(2.0);
                col += color(r, world);
            }

            col /= float(ns);
            col = vec3(sqrt(col.r()), sqrt(col.g()), sqrt(col.b()));

            int ir = int(255.99 * col.r());
            int ig = int(255.99 * col.g());
            int ib = int(255.99 * col.b());

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}

