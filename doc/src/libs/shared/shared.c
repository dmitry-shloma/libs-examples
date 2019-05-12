#include <stdio.h>
#include <string.h>

#include "shared.h"

extern void lib_info(struct lib_info *li)
{
    li->version = 2;
}
