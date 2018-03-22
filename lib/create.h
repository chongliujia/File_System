int create(char *name)
{
    int i, j;

    if(strlen(name) > 8) return (-1);

    for(i = 2; i < MSD+2; i++){
        if(cur_dir->directitem[i].firstDisk == -1) break;
    }

    for(j = 2; j < MSD+2; j++){
        if(!strcmp(cur_dir->directitem[j].name, name)) break;
    }

    if(i >= MSD+2) return (-2);
    if(u_opentable.cur_size >= MOFN) return (-3);
    if(j < MSD+2) return (-4);

    for(j = ROOT_DISK_NO+1; j < DISK_NUM; j++){
        if(fat[j].em_disk == '0') break;
    }

    if(j >= DISK_NUM) return (-5);

    fat[j].em_disk = '1';
    
    strcpy(cur_dir->directitem[i].name, name);

    cur_dir->directitem[i].firstDisk = j;
    cur_dir->directitem[i].size      = 0;
    cur_dir->directitem[i].next      = j;
    cur_dir->directitem[i].property  = '0';

    fd = open(name);

    return 0;
}
