#include <time.h>
#include <stdlib.h> 

int transmute_char(char *subject) {
   int len = strlen(subject) - 1;
   int i,new = 0;
   for(i = 1;len >= 0;--len,i *= 10) {
      if(subject[len] > 0x39 || subject[len] < 0x30) {
         return 0; 
      }
      new += (subject[len] - 0x30) * i;
   }
   return new;
}


char *transmute_int(int subject, int size) {
   int container = 0;
   int count = size - 1;
   int check = 0;
   char *new = malloc(size);
   memset(new,0,size);
   while(subject) {
      container = subject % 10;
      subject /= 10;
      new[--count] = container + 0x30;
      check++;
   }
   return new;
}

int generate_number(void) {
   srand(time(NULL)); 
   int sekrit_number = 0; 
   while(!(sekrit_number / 1000))
      sekrit_number = rand() % 9999; 
   return sekrit_number; 

}






int master_compare(int guess, int sekrit) { 

if(!(guess - sekrit))
return 40; 

int retnum = 0; 
char *guess_s = transmute_int(guess,5);
char *sekrit_s = transmute_int(sekrit,5); 
char *comp;
char *selection = malloc(2);
selection[1] = '\0';  
int i,tmp; 

for(i=0;i < strlen(sekrit_s);++i) {
   selection[0] = guess_s[i]; 
   comp = strstr(sekrit_s,selection); 
   if(comp != 0) {
      tmp = (comp - sekrit_s) - i;
      if(tmp)
         retnum += 1; 
      else
         retnum += 10;  
      }
   comp = 0; 
   }
  free(selection); 
  free(sekrit_s); 
  free(guess_s); 
  return retnum; 
}

void master_strings(int results, char *string, int slen) { 

char *tmpbuf = malloc(slen); 
memset(tmpbuf,0,slen); 
int red = results / 10; 
int white = results % 10; 

if(red) { 
snprintf(tmpbuf,slen,"%i red ",red); 
strncat(string,tmpbuf,strlen(tmpbuf)); 
memset(tmpbuf,0,slen); 
}

if(white) { 
snprintf(tmpbuf,slen,"%i white ",white);
strncat(string,tmpbuf,strlen(tmpbuf));
memset(tmpbuf,0,slen);
} 

if(!(red + white)) 
strncpy(string,"No matches",slen);


free(tmpbuf); 
return; 

} 

