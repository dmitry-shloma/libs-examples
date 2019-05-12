#include "helper.h"

void clearScreen()
{
#ifdef __linux__
    system("clear");
#elif defined(_WIN32)
    system("cls");
#endif
}

void systemPause()
{
#ifdef __linux__
    getchar();
#elif defined(_WIN32)
    system("pause");
#endif
}

#ifdef __linux__
#   include <stdbool.h>
#endif
