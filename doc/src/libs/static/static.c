#include <stdio.h>
#include <string.h>

#include "static.h"

extern void lib_info(struct lib_info *li)
{
    li->version = 1;
}
