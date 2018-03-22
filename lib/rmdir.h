int rmdir(char *name)
{
    int i, j, item;
    struct direct *temp_dir;

    for(i = 2; i < MSD+2; i++){
        if(!strcmp(cur_dir->directitem[i].name, name)) break;
    }

    if(cur_dir->directitem[i].property != '1') return (-3);
    if(i >= MSD+2) return (-1);

    temp_dir = (struct direct *)(fdisk + cur_dir->directitem[i].next * DISKSIZE);
    for(j = 2; j < MSD+2; j++){
        if(temp_dir->directitem[j].next != -1) break;
    }

    if(j < MSD+2) return (-2);

    item = cur_dir->directitem[i].firstDisk;

    fat[item].em_disk = '0';

    cur_dir->directitem[i].sign      = 0;
    cur_dir->directitem[i].firstDisk = -1;
    
    strcpy(cur_dir->directitem[i].name, "");

    cur_dir->directitem[i].next     = -1;
    cur_dir->directitem[i].property = '0';
    cur_dir->directitem[i].size     = 0;

    return 0;
}
