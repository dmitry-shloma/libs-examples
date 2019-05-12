#ifndef TMODULE_H
#define TMODULE_H

#define EXPORT __declspec(dllexport)

extern "C" {

EXPORT int get_id();
EXPORT float get_temper();
}

#endif

