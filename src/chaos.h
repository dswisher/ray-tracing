#ifndef CHAOS_H
#define CHAOS_H

#include <random>
#include "vec3.h"


class chaos
{
public:
    static chaos* instance();

    float uniform();
    vec3 random_in_unit_sphere();

private:
    // private, so it cannot be called
    chaos() : source(316), dist(0.0, 1.0) {};

    // ditto for copy constructor
    chaos(chaos const&) {};

    static chaos* _instance;

    std::mt19937 source;    // use a set seed to be deterministic
    std::uniform_real_distribution<> dist;
};

#endif
