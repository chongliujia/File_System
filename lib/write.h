int write(int fd, char* buf, int len)
{
    char *first;

    char space  = 32;
    char endter = '\n';

    int item;
    int i, j, k;
    int ilen1, ilen2;
    int modlen, temp;

    for(i = 0; i < len; i++){
        if(buf[i] == '$') buf[i] = space;
        else if(buf[i] == '#') buf[i] = endter;
    }

    item = u_opentable.openitem[fd].firstDisk;

    for(i = 2; i < MSD+2; i++){
        if(cur_dir->directitem[i].firstDisk == item) break;
    }

    temp = i;

    while(fat[item].item != -1){
        item = fat[item].item;
    }

    first = fdisk + item * DISKSIZE + u_opentable.openitem[fd].size % DISKSIZE;

    if(DISKSIZE - u_opentable.openitem[fd].size % DISKSIZE > len){
        strcpy(first, buf);
        u_opentable.openitem[fd].size  = u_opentable.openitem[fd].size + len;
        cur_dir->directitem[temp].size = cur_dir->directitem[temp].size + len; 
    }
    else{
        for(i = 0; i < (DISKSIZE - u_opentable.openitem[fd].size % DISKSIZE); i++){
            first[i] = buf[i];
        }

        ilen1  = len - (DISKSIZE - u_opentable.openitem[fd].size % DISKSIZE);
        ilen2  = ilen1/DISKSIZE;
        
        modlen = ilen1 % DISKSIZE;
        if(modlen > 0) ilen2 = ilen2 + 1;

        for(j = 0;j < ilen2; j++){
            for(i = ROOT_DISK_NO + 1; i < DISK_NUM; i++){
                if(fat[i].em_disk == '0') break;
            }

            if(i >= DISK_NUM) return (-1);
            
            first = fdisk + i * DISKSIZE;

            if(j == ilen2 - 1){
                for(k = 0; k < len - (DISKSIZE - u_opentable.openitem[fd].size % DISKSIZE) - j * DISKSIZE; k++){
                    first[k] = buf[k];
                }
            }
            else{
                for(k = 0; k < DISKSIZE; k++){
                    first[k] = buf[k];
                }
            }

            fat[item].item = i;
            fat[i].em_disk = '1';
            fat[i].item    = -1;
        }

        u_opentable.openitem[fd].size  = u_opentable.openitem[fd].size + len;

        cur_dir->directitem[temp].size = cur_dir->directitem[temp].size + len; 
    }
    return 0;
}
