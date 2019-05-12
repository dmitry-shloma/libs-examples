#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

int main()
{
    
   HMODULE hMod = LoadLibrary("libtmodule.dll");
   if (!hMod) {
       printf("ERROR 1\n");
       return 1;
   }

    typedef int (*ptr_func)();
    ptr_func get_id;
     get_id = (ptr_func) GetProcAddress(hMod, "get_id");
     if (!get_id) {
       printf("ERROR 2\n");
       return 1;
    }

   int id = get_id();
 //   float temper = get_temper();
   printf("id: %d, temper: %.1f\n\n", id, 0.0);

	FreeLibrary(hMod);
    system("pause");
    return 0;
}
