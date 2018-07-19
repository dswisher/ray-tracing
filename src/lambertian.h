#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "chaos.h"
#include "material.h"


class lambertian : public material
{
public:
    lambertian(const vec3& a) : albedo(a) {}

    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const
    {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        scattered = ray(rec.p, target - rec.p);
        attenuation = albedo;
        return true;
    }

private:
    vec3 albedo;

    vec3 random_in_unit_sphere() const
    {
        vec3 p;
        do
        {
            p = 2.0 * vec3(chaos::instance()->uniform(), chaos::instance()->uniform(), chaos::instance()->uniform()) - vec3(1, 1, 1);
        } while (p.squared_length() > 1.0);

        return p;
    }
};

#endif
