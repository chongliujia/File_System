#define DIR_LENGHT 1024



void enter()
{
    FILE *fp;

    int i;

    fdisk = (char *)malloc(MEM_D_SIZE*sizeof(char));
    if((fp=fopen("disk.dat", "rb")) == NULL){
        printf("Error:\nCannot open file\n");
        return ;
    }
    
    if(!fread(fdisk, MEM_D_SIZE, 1, fp)){
        printf("Error:\nCannot read file\n");
        exit(0);
    }

    fat  = (struct fatable *)(fdisk + DISKSIZE);
    root = (struct direct *)(fdisk + DISKSIZE + FATSIZE);
    fclose(fp);

    for(i = 0; i < MOFN; i++){
        strcpy(u_opentable.openitem[i].name, "");
        u_opentable.openitem[i].firstDisk = -1;
        u_opentable.openitem[i].size      = 0;
    }

    u_opentable.cur_size = 0;

    cur_dir = root;
    bufferdir = (char *)malloc(DIR_LENGHT * sizeof(char));
    strcpy(bufferdir, "####--****---#####:");
}
