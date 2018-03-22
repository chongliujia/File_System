int delete(char *name)
{
    int i, cur_item, item, temp;

    for(i = 2; i < MSD+2; i++){
        if(!strcmp(cur_dir->directitem[i].name, name)) break;
    }

    cur_item = i;

    if(i >= MSD+2) return (-1);
    if(cur_dir->directitem[cur_item].property != '0') return (-3);

    for(i = 0; i < MOFN; i++){
        if(!strcmp(u_opentable.openitem[i].name, name)) return (-2);
    }

    item = cur_dir->directitem[cur_item].firstDisk;
    while(item != -1){
        temp = fat[item].item;
        fat[item].item    = -1;
        fat[item].em_disk = '0';
        item              = temp;
    }

    cur_dir->directitem[cur_item].sign      = 0;
    cur_dir->directitem[cur_item].firstDisk = -1;

    strcpy(u_opentable.openitem[cur_item].name, "");

    cur_dir->directitem[cur_item].next      = -1;
    cur_dir->directitem[cur_item].property  = '0';
    cur_dir->directitem[cur_item].size      = 0;

    return 0;
}
