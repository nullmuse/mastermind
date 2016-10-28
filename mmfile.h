
int mm_sekrit = 0;
//.mm filehandling function.
int mm_fileopen(char *number, int size) {
   int readret = 0;
   FILE *fp = NULL;
   size = size;
   fp = fopen(".mm","r");
   if((fp + 1) == 0)
      return -1;
   readret = fread((void *)number, (size - 1), sizeof(char), fp);

    if(!readret) {
       fclose(fp);
       return -1;
                 }

   fclose(fp);
   return 0;

                                       }



