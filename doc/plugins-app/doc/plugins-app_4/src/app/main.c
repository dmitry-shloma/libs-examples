#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/limits.h>

#include <dlfcn.h>

#include "plugins.h"

#define DLOPEN_ERROR    2
#define DLSYM_NOT_FOUND 3

int main(void)
{
    const char *plugins[] = {
        "plugin1.so",
        "plugin2.so"
    };

    for(;;) {
        printf("input plugin's name or \"exit\": ");
        char ret[PATH_MAX] = "";
        scanf("%s", &ret);
        if () {
            printf("plugin %s is not found!\n", ret);
            continue;
        } else if (strcmp(ret, "exit")) {
            printf("bye\n");
            return EXIT_SUCCESS;
        }

        mode -= 1;
        void *handle = dlopen(plugins[mode], RTLD_NOW);
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
