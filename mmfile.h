


int mm_fileopen(char *passwd, int size) { 
int readret; 
FILE *fp = NULL;   
fp = fopen(".mm","r");

if(fp == -1) {
return -1; 
}
readret = fread((void *)passwd, size - 1, sizeof(char), fp);
if(!readret) { 
fclose(fp);  
return -1; 
} 
fclose(fp); 
return 0; 

}



