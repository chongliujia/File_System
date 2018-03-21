void format()
{
    int i;

    FILE *fp;
    
    fat = (struct fatable *)(fdisk + DISKSIZE);
    fat[0].item = -1;
    fat[0].em_disk = '1';

    for(i = 1; i < ROOT_DISK_NO-1; i++){
        fat[i].item = i + 1;
        fat[i].em_disk = '1';
    }

    fat[ROOT_DISK_NO-1].item    = -1;
    fat[ROOT_DISK_NO-1].em_disk = '1';
    fat[ROOT_DISK_NO].item      = -1;
    fat[ROOT_DISK_NO].em_disk   = '1';

    for(i = ROOT_DISK_NO+1; i<DISK_NUM; i++){
        fat[i].item    = -1;
        fat[i].em_disk = '0';
    }

    root = (struct direct *)(fdisk + DISKSIZE + FATSIZE);

    root->directitem[0].sign      = 1;
    root->directitem[0].firstDisk = ROOT_DISK_NO;

    strcpy(root->directitem[0].name, ".");

    root->directitem[0].next     = root->directitem[0].firstDisk;
    root->directitem[0].property = '1';
    root->directitem[0].size     =ROOT_DISK_SIZE;
    
    root->directitem[1].sign      = 1;
    root->directitem[1].firstDisk = ROOT_DISK_NO;
    
    strcpy(root->directitem[1].name, "..");

    root->directitem[1].next     = root->directitem[0].firstDisk;
    root->directitem[1].property = '1';
    root->directitem[1].size     = ROOT_DISK_SIZE;

    for(i = 2; i < MSD+2; i++){
        root->directitem[i].sign      = 0;
        root->directitem[i].firstDisk = -1;
        
        strcpy(root->directitem[i].name, "");

        root->directitem[i].next      = -1;
        root->directitem[i].property  = '0';
        root->directitem[i].size      = 0;
    }

    if((fp = fopen("disk.dat", "wb")) == NULL){
        printf("Error: \n Cannot open file! \n");
        return ;
    }

    if(fwrite(fdisk, MEM_D_SIZE, 1, fp) != 1){
        printf("Error: \n File write error!!\n");
    }

    fclose(fp);
}
