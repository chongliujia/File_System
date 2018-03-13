#include "file/file.h"
#include "user.h"
#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i;

    if(argc < 2){
        printf(2, "Usage: mkdir files...\n");
        exit(0);
    }

    for(i = 1; i < argc; i++){
        if(mkdir(argv[i]) < 0){
            printf(2, "mkdir: %s failed to create\n", argv[i]);
            break;
        }
    }

    exit(0);
}
