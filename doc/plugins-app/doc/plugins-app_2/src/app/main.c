#include <stdio.h>
#include <stdlib.h>

#include "mockdevice/mockdevice.h"
#include "realdevice/realdevice.h"

#include <dlfcn.h>

#define EMISSION_LEVEL 123

int main(void)
{
    void *handle = dlopen("librealdevice.so.0.1.0", RTLD_NOW);
    if (!handle) {
        printf("dlopen error\n");
        return EXIT_FAILURE;
    }

    void (*ptr_set_emission_level)(int) = NULL;
    if (!(ptr_set_emission_level = dlsym(handle, "set_emission_level"))) {
        printf("dlsym set_emission_level");
        return EXIT_FAILURE;
    }

    int (*ptr_get_emission_level)() = NULL;
    if (!(ptr_get_emission_level = dlsym(handle, "get_emission_level"))) {
        printf("dlsym get_emission_level");
        return EXIT_FAILURE;
    }

//    set_emission_level(EMISSION_LEVEL);
    ptr_set_emission_level(EMISSION_LEVEL);

//    level = get_emission_level();
    int level = ptr_get_emission_level();
    printf("emission level: %d\n", level);

    dlclose(handle);

    return 0;
}
