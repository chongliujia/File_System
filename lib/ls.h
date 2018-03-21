void ls()
{
    for(int i = 0; i < MSD + 2; i++){
        if(cur_dir->directitem[i].firstDisk != -1){
            printf("%s\t", cur_dir->directitem[i].name);
            if(cur_dir->directitem[i].property == '0'){
                printf("%d\t\t\n", cur_dir->directitem[i].size);
            }
            else{
                printf("\t<ls>\t\n");
            }
        }
    }
}
