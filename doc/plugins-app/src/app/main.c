#include <stdio.h>

//#include "plugin1/plugin1.h"
//#include "plugin2/plugin2.h"

#include "mockdevice/mockdevice.h"
#include "realdevice/realdevice.h"

#define EMISSION_LEVEL 123

int main(void)
{
//    char buf[255] = "";
//    about_plugin(buf);
//    printf("%s\n", buf);

    set_emission_level(EMISSION_LEVEL);
    int level = get_emission_level();
    printf("emission level: %d\n", level);

    return 0;
}

