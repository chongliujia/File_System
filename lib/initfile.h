#include "core/core.h"
#include "core/function.h"
#include "lib/format.h"

void initfile()
{
    fdisk = (char *)malloc(MEM_D_SIZE*sizeof(char));
    format();
    free(fdisk);
}
