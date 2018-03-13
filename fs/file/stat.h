#ifdef  STAT_H
#define STAT_H

struct stat
{
    short       fs_type;
    int         fs_dev;
    uint        fs_ino;
    short       fs_nlink;
    uint        fs_size;
};


#define     T_DIR   1 //文档
#define     T_FILE  2 //文件
#define     T_DEV   3 //设备

#endif
