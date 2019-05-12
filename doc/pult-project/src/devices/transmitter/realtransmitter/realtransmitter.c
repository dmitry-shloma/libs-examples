#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "transmitter.h"

#define EMISSION_LEVEL_MAX 200
#define EMISSION_LEVEL_MIN 100

void set_emission_level(int level)
{
    printf("pass %d to real device\n", level);
}

int get_emission_level()
{
    printf("get from real device\n");

    static bool isInit = false;
    if (!isInit) {
        srand(time(NULL));
        isInit = true;
    }
    int emission_level = EMISSION_LEVEL_MIN + rand() % (EMISSION_LEVEL_MAX - EMISSION_LEVEL_MIN + 1);
    return emission_level;
}

int get_version()
{
    return 1;
}
