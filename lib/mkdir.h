int mkdir(char *name)
{
    int i, j;
    struct direct *cur_mkdir;

    if(strchr(name, '\\')) return (-4);
    if(!strcmp(name, ".")) return (-6);
    if(!strcmp(name, "..")) return (-6);
    if(strlen(name) > 8) return (-1);

    for(i = 2; i < MSD+2; i++){
        if(cur_dir->directitem[i].firstDisk == -1) break;
    }

    if(i >= MSD + 2) return (-2);
    for(j = 2; j < MSD + 2; j++){
        if(!strcmp(cur_dir->directitem[j].name, name)) break;
    }

    if(j < MSD + 2) return (-3);
    for(j = ROOT_DISK_NO+1; j < DISK_NUM; j++){
        if(fat[j].em_disk == '0') break;
    }

    if(j >= DISK_NUM) return (-5);
    fat[j].em_disk = '1';

    strcpy(cur_dir->directitem[i].name, name);

    cur_dir->directitem[i].firstDisk = j;
    cur_dir->directitem[i].size      = ROOT_DISK_SIZE;
    cur_dir->directitem[i].next      = j;
    cur_dir->directitem[i].property  = '1';

    cur_mkdir = (struct direct *)(fdisk + cur_dir->directitem[i].firstDisk * DISKSIZE);

    cur_dir->directitem[0].sign      = 0;
    cur_dir->directitem[0].firstDisk = cur_dir->directitem[i].firstDisk;

    strcpy(cur_mkdir->directitem[0].name, ".");

    cur_mkdir->directitem[0].next      = cur_mkdir->directitem[0].firstDisk;
    cur_mkdir->directitem[0].property  = '1';
    cur_mkdir->directitem[0].size      = ROOT_DISK_SIZE;

    cur_mkdir->directitem[1].sign      = cur_dir->directitem[0].sign;
    cur_mkdir->directitem[1].firstDisk = cur_dir->directitem[0].firstDisk;

    strcpy(cur_mkdir->directitem[1].name, "..");

    cur_mkdir->directitem[1].next      = cur_mkdir->directitem[1].firstDisk;
    cur_mkdir->directitem[1].property  = '1';
    cur_mkdir->directitem[1].size      = ROOT_DISK_SIZE;

    for(i = 2; i < MSD+2; i++){
        cur_mkdir->directitem[i].sign       = 0;
        cur_mkdir->directitem[i].firstDisk  = -1;

        strcpy(cur_mkdir->directitem[i].name, "");

        cur_mkdir->directitem[i].next       = -1;
        cur_mkdir->directitem[i].property   = '0';
        cur_mkdir->directitem[i].size       = 0;
    }

    return 0;
}
