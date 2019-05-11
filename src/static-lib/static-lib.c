#include "static-lib.h"

#include <string.h>

void about(struct INFO *info)
{
    strcpy(info->author, "test");
    info->maj = 1;
    info->min = 2;
    info->patch = 0;
}
