#include "./../static-lib/static-lib.h"
#include "./../shared-lib/shared-lib.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct INFO info;
    about(&info);
    printf("author: %s,\nversion: %d.%d.%d\n",
           info.author, info.maj, info.min, info.patch);

    printf("add_num: %d\n", add_num(1, 5));
    char *str = cat_str("Hello", "World!");
    printf("%s\n", str);
    free(str);
    str = NULL;

    return 0;
}

