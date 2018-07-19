
#include <stddef.h>
#include "chaos.h"

// Global static pointer to ensure single instance
chaos* chaos::_instance = NULL;

chaos* chaos::instance()
{
    if (!_instance)
        _instance = new chaos();

    return _instance;
}


float chaos::uniform()
{
    return dist(source);
}


vec3 chaos::random_in_unit_sphere()
{
    vec3 p;
    do
    {
        p = 2.0 * vec3(dist(source), dist(source), dist(source)) - vec3(1, 1, 1);
    } while (p.squared_length() > 1.0);

    return p;
}
