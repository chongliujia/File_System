#include "fs_core.h"

struct fatable  *fat;

struct direct    *root;
struct direct    *cur_dir;

struct opentable     u_opentable;


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
int mkdir(int fd, char *buf, int len);
int rmdir(char *name);
int cd(char *name);

void print();
void show();

