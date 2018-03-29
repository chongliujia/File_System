
#include "lib/core/fs_core.h"
#include "lib/print.h"
#include "lib/ls.h"
#include "lib/show.h"
#include "lib/enter.h"
#include "lib/initfile.h"
#include "lib/format.h"
#include "lib/mkdir.h"
#include "lib/rmdir.h"
#include "lib/cd.h"
#include "lib/create.h"
#include "lib/delete.h"


int main(int argc, char* argv[])
{
    FILE *fp;
    
    char ch;
    char a[100];
    char code[20][20];
    char name[10];
    
    char *contect;
    contect = (char *)malloc(MAX_WRITE*sizeof(char));
    
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
    
    strcpy(code[0], "ls");
    strcpy(code[1], "mkdir");
    strcpy(code[2], "rmdir");
    strcpy(code[3], "cd");
    strcpy(code[4], "create");
    strcpy(code[5], "delete");
    
    while(1){
        scanf("%s", a);
        for(i = 0; i < 5; i++){
            if(!strcmp(code[i], a)) break;
        }
        
        switch(i){
            case 0:                 //ls
                ls();
                show();
                break;
                
            case 1:
                scanf("%s", name);    //mkdir
                flag = mkdir(name);
                
                if(flag == -1) printf("Error: \n The length of name is long!\n");
                else if(flag == -2) printf("Error: \n The direct item is already full! \n");
                else if(flag == -3) printf("Error: \n The name is already in the direct! \n");
                else if(flag == -4) printf("Error: \n Can't in the name of a direct !\n");
                else if(flag == -5) printf("Error: \n The Disk space is full! \n");
                else if(flag == -6) printf("Error: \n '..' or '.' can't as the name of the direct! \n");
                else if(flag == 0) printf("Successfully make direct! \n");
                
                show();
                break;
                
            case 2:
                scanf("%s", name);
                flag = rmdir(name);
                
                if(flag == -1) printf("Error: \n The direct is not exist! \n");
                else if(flag == -2) printf("Error: \n The direct has son direct, please first remove the son direct! \n");
                else if(flag == -3) printf("Error: \n The remve is not direct! \n");
                else if(flag == 0) printf("Successfully remove direct! \n");
                
                show();
                break;
                
            case 3:
                scanf("%s", name);
                flag = cd(name);
                
                if(flag == -1) printf("Error: \n The path no correct! \n");
                else if(flag == -2) printf("Error: \n The opened is not direct! \n");
                else if(flag == -3) printf("Error: \n The '\\' is too much! \n");
                
                show();
                break;
                
            case 4:
                scanf("%s", name);
                flag = create(name);
                
                if(flag == -1) printf("Error: \n The length is too long! \n");
                else if(flag == -2) printf("Error: \n The direct item is already full! \n");
                else if(flag == -3) printf("Error: \n The number of openfile is too much! \n");
                else if(flag == -4) printf("Error: \n The name is already in the direct! \n");
                else if(flag == -5) printf("Error: \n The disk space is full! \n");
                else printf("Successfully create a file! \n");
                
                show();
                break;
                
            case 5:
                scanf("%s", name);
                flag = delete(name);
                if(flag == -1) printf("Error: \n The file not exist! \n");
                else if(flag == -2) printf("Error: \n The file is opened, please first close it! \n");
                else if(flag == -3) printf("Error: \n The delete is not file! \n");
                else printf("Successfully delete! \n");
                
                show();
                break;
                
            default:
                printf("\n Error! \n The command is wrong! or The command is unknown! ");
                show();
                
        }
    }
}
