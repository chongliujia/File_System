#ifdef FS_H
#define FS_H

#define     ROOTINO     1
#define     BSIZE       512


struct superblock
{
    uint    sb_size;       //文件系统的总块数
    uint    sb_nblocks;    //数据块的块数
    uint    sb_ninodes;    //inode的块数
    uint    sb_nlog;       //目录块的块数
    uint    sb_logstart;   //目录块的起始的块数
    uint    sb_inodestart; //inode起始的块数
    uint    sb_bmapstart;  //bitmap
};

#define     NDIRECT     12
#define     NINDIRECT   (BSIZE / sizeof(uint))
#define     MAXFILE     (NDIRECT + NINDIRECT)

struct dinode
{
    short   di_type;
    short   di_major;
    short   di_minor;
    short   di_nlink;

    uint    di_size;
    uint    di_addrs[NDIRECT + 1];
};

#define     IPB     (BSIZE / sizeof(struct dinode))  //inode per block

#define     IBLOCK(i, sb)   ((i) / IPB + sb.sb_inodestart)

#define     BBLOCK(b, sb)   (b/BPB + sb.sb_bmapstart)

#define     DIRSIZ  14

struct dirent
{
    ushort  inum;
    char    name[DIRSIZ];
};


#endif
