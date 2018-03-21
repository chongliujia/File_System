#include "lib/core/fs_core.h"
#include "lib/print.h"
#include "lib/ls.h"
#include "lib/show.h"


int main(int argc, char* argv[])
{
    FILE *fp;
    
    char ch;
    char a[100];
    char code[20][20];
    char name[10];
    
    char *contect;
    contect = (char *)malloc(MAX_WRITE)*sizeof(char));
    
    int i, flag, r_size;
    
    if((fp=fopen("disk.dat", "rb")) == NULL){
        printf("You have not format, Do you want format?(y/n)");
        
        scanf("%c", &ch);
        if(ch == 'y'){
            initfile();
            printf("Successfully format! \n");
        }
        else return -1;
    }
    
    enter();
    print();
    show();
    
    strcpy(code[0]."ls");
    
    while(1){
        scanf("%s", a);
        for(i = 0; i < 11; i++
    }
}
