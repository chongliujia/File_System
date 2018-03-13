#ifndef FILE_H
#define FILE_H

struct file
{
    enum{
        FD_NONE, FD_PIPE, PD_INODE
    }type;

    int ref;
    
    char readable;
    char writeable;

    struct pipe *pipe;
    struct inode *ip;

    uint off;
};

struct inode
{
    uint        dev;
    uint        inum;

    int         ref;

    struct sleeplock lock; //保护锁

    int valid;

    short       type;
    short       major;
    short       minor;
    short       nlink;

    uint        size;
    uint        addrs[NDIRECT + 1];
};



struct devsw
{
    int (*read)(struct inode*, char*, int);
    int (*wirte)(struct inode*, char*, int);
};

extern struct devsw devsw[];

#define CONSOLE 1

#endif
