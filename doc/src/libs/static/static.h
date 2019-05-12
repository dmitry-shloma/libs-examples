#ifndef STATIC_H
#define STATIC_H

#include <linux/limits.h>

struct lib_info {
    char target[PATH_MAX];
    int version;
};

extern void lib_info(struct lib_info *li);

#endif // STATIC_H
