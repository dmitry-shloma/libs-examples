#include "shared-lib.h"

#include <string.h>
#include <stdlib.h>

int add_num(int v1, int v2)
{
    return v1 + v2;
}

char *cat_str(const char *str1, const char *str2)
{
    int size = strlen(str1) + strlen(str2) + 1;
    char *buf = (char *) malloc(size);
    strcpy(buf, str1);
    strcat(buf, str2);
    return buf;
}
