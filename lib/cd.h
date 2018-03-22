int cd(char *name)
{
    int i, j, item;

    char *str, *str1;
    char *temp, *point, *point1;
    
    struct direct *temp_dir;
    temp_dir = cur_dir;
    str      = name;

    if(!strcmp("\\", name)){
        cur_dir = root;
        strcpy(bufferdir, "root: >>>");
        return 0;
    }

    j = 0;
    for(i = 0; i < (int)strlen(str); i++){
        if(name[i] == '\\'){
            j++;
            if(j >= 2) return (-3);
        }
        else j = 0;
    }

    if(name[0] == '\\'){
        temp_dir = root;
        strcpy(bufferdir, "root: >>>");
        str++;
    }

    if(str[strlen(str) - 1] == '\\') str[strlen(str) - 1] = '\0';

    str1 = strchr(str, '\\');

    temp = (char *)malloc(DIR_LENGTH*sizeof(char));
    while(str1 != NULL){
        for(i = 0; i < str1-str; i++){
            temp[i] = str[i];
        }
        temp[i] = '\0';

        for(j = 2; j < MSD+2; j++){
            if(!strcmp(temp_dir->directitem[j].name, temp)) break;
        }

        if(j >= MSD+2) return (-1);

        item     = temp_dir->directitem[j].firstDisk;
        temp_dir = (struct direct *)(fdisk + item*DISKSIZE);
        str      = str1 + 1;
        str1     = strchr(str, '\\');
    }

    str1 = str1 + strlen(str);
    for(i = 0; i < (int)strlen(str); i++){
        temp[i] = str[i];
    }
    temp[i] = '\0';

    for(j = 0; j < MSD+2; j++){
        if(!strcmp(temp_dir->directitem[j].name, temp)) break;
    }

    free(temp);
    if(temp_dir->directitem[j].property != '1') return (-2);
    if(j >= MSD + 2) return (-1);

    item = temp_dir->directitem[j].firstDisk;
    temp_dir = (struct direct *)(fdisk + item*DISKSIZE);

    if(!strcmp("..", name)){
        if(cur_dir->directitem[j-1].sign != 1){
            point = strchr(bufferdir, '\\');
            while(point != NULL){
                point1 = point + 1;
                point  = strchr(point1, '\\');
            }
            *(point1 - 1) = '\0';
        }
        else {}
    }
    else if(!strcmp(".", name)) bufferdir = bufferdir;
    else{
        if(name[0] != '\\'){
            bufferdir = strcat(bufferdir, "\\");
            bufferdir = strcat(bufferdir, name);
        }
    }
    
    cur_dir = temp_dir;

    return 0;
}
