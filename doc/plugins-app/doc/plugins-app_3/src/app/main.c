#include <stdio.h>
#include <stdlib.h>

#include "mockdevice/mockdevice.h"
#include "realdevice/realdevice.h"

#include <dlfcn.h>

#define EMISSION_LEVEL 123

#define DLOPEN_ERROR    2
#define DLSYM_NOT_FOUND 3

int main(void)
{
    const char *libnames[] = {
        "libmockdevice.so.0.1.0",
        "librealdevice.so.0.1.0"
    };

    for(;;) {
        printf("input mode (1-mock, 2-real) or 3 for exit: ");
        int mode = -1;
        scanf("%d", &mode);
        if ((mode < -1) || (mode > 3)) {
            printf("mode error\n");
            continue;
        } else if (mode == 3) {
            printf("bye\n");
            return EXIT_SUCCESS;
        }

        mode -= 1;
        void *handle = dlopen(libnames[mode], RTLD_NOW);
        if (!handle) {
            printf("dlopen error\n");
            return DLOPEN_ERROR;
        }

        void (*ptr_set_emission_level)(int) = NULL;
        ptr_set_emission_level = dlsym(handle, "set_emission_level");
        if (!ptr_set_emission_level) {
            printf("dlsym set_emission_level not found\n");
            return DLSYM_NOT_FOUND;
        }

        int (*ptr_get_emission_level)() = NULL;
        ptr_get_emission_level = dlsym(handle, "get_emission_level");
        if (!ptr_get_emission_level) {
            printf("dlsym get_emission_level not found\n");
            return DLSYM_NOT_FOUND;
        }

        ptr_set_emission_level(EMISSION_LEVEL);
        int level = ptr_get_emission_level();
        printf("emission level: %d\n", level);

        dlclose(handle);
    }

    return 0;
}
