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


char *transmute_int(int subject) {
   int container = 0;
   int count = 5;
   int check = 0;
   char *new = malloc(5);
   memset(new,0,5);
   while(subject) {
      container = subject % 10;
      subject /= 10;
      new[--count] = container + 0x30;
      check++;
   }
   if(count) {
   memcpy(new,new + count,6 - count);
   }
   return new;
}

int generate_number(void) {
   srand(time(NULL)); 
   int sekrit_number = 0; 
   while(!sekrit_number)
      sekrit_number = rand() % 9999; 
   return sekrit_number; 

}






int master_compare(int guess, int sekrit) { 

if(!(guess - sekrit))
return 40; 

int retnum = 0; 
char *guess_s = transmute_int(guess);
char *sekrit_s = transmute_int(sekrit); 
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
  return retnum; 
}



