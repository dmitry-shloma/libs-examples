#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "transmitter/transmitter.h"

#define EMISSION_LEVEL 123

void static_linking_shared_lib();
void dynamic_linking_shared_lib();

int main(void)
{
    dynamic_linking_shared_lib();

    return 0;
}

void static_linking_shared_lib()
{
//    set_emission_level(EMISSION_LEVEL);
//    int level = get_emission_level();
//    printf("emission level: %d\n", level);
}

void dynamic_linking_shared_lib()
{
    printf("lib name: ");
    char lib_name[MAX_PATH] = "realtransmitter";
    //    scanf("%s", lib_name);
    char lib_path[MAX_PATH] = "C:\\QtProjects2\\pult-project\\build\\src\\pult\\debug\\bin";
    strcat(lib_path, "\\");
    strcat(lib_path, lib_name);
    strcat(lib_path, ".dll");

    HMODULE hModule = LoadLibraryA(lib_path);
    if (!hModule) {
        printf("error load lib\n");
        return;
    }

    void (*ptr_set_emission_level)(int level) = NULL;
    ptr_set_emission_level = GetProcAddress(
                hModule, "set_emission_level");

    if (!ptr_set_emission_level) {
        printf("error find add in lib\n");
        return;
    }

    int (*ptr_get_emission_level)() = NULL;
    ptr_get_emission_level = GetProcAddress(
                hModule, "get_emission_level");

    if (!ptr_get_emission_level) {
        printf("error find add in lib\n");
        return;
    }

    ptr_set_emission_level(123);
    int level = ptr_get_emission_level();
    printf("level: %d\n", level);

    FreeLibrary(hModule);
}
