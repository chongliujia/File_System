#ifdef  USER_H
#define USER_H

struct stat;
struct rtcdate;

int write(int, void*, int);
int read(int, void*, int);
int close(int);
int open(char*, int);
int mkdir(char*);






#endif
