/*
 * created: 2018.3.19
 * author: J
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define DIR_LENGTH       1024
#define MAX_WRITE        1024*128
#define MEM_D_SIZE       1024*1024
#define DISKSIZE         1024
#define MSD              10
#define DISK_NUM         MEM_D_SIZE/DISKSIZE
#define FATSIZE          DISK_NUM*sizeof(struct fatable)
#define MOFN             5

#define ROOT_DISK_NO     FATSIZE/DISKSIZE+1
#define ROOT_DISK_SIZE   sizeof(struct direct)



struct fatable{
    int     item;

    char    em_disk;
};

struct direct{
    struct FCB{
        char   name[10];
        char   property;

        int    size;
        int    firstDisk;
        int    next;
        int    sign;
    }directitem[MSD+2];
};

struct opentable{
    struct opentableitem{
        char    name[10];

        int     firstDisk;
        int     size;
    }openitem[MOFN];

    int cur_size;
};

struct fatable   *fat;
struct direct    *root;
struct direct    *cur_dir;

struct opentable  u_opentable;


int fd = -1;

char *bufferdir;
char *fdisk;


void initfile();
void enter();
void ls();
void format();

int create(char *name);
int open(char *name);
int close(char *name);
int mkdir(char *name);
int rmdir(char *name);
int cd(char *name);
int delete(char *name);

void print();
void show();
