#include <stdio.h>

#include "mockdevice.h"

int emission_level = 0;

void set_emission_level(int level)
{
    emission_level = level;
}

int get_emission_level()
{
    return emission_level;
}
