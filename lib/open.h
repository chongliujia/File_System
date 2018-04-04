int open(char *name)
{
    int i, j;

    for(i = 2; i < MSD+2; i++){
        if(!strcmp(cur_dir->directitem[i].name, name)) break;
    }

    if(i >= MSD+2) return (-1);

    if(cur_dir->directitem[i].property == '1') return (-4);
    
    for(j = 0; j < MOFN; j++){
        if(!strcmp(u_opentable.openitem[j].name, name)) break;
    }

    if(j < MOFN) return (-2);

    if(u_opentable.cur_size >= MOFN) return (-3);

    for(j = 0; j < MOFN; j++){
        if(u_opentable.openitem[j].firstDisk == -1) break;
    }

    u_opentable.openitem[j].firstDisk = cur_dir->directitem[i].firstDisk;

    strcpy(u_opentable.openitem[j].name, name);

    u_opentable.openitem[j].size = cur_dir->directitem[i].size;
    u_opentable.cur_size++;

    return (j);
}
