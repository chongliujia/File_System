void initfile()
{
    fdisk = (char *)malloc(MEM_D_SIZE*sizeof(char));
    format();
    free(fdisk);
}
