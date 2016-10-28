#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> 
#include <string.h> 
#include "mmlib.h"


void stdflush(void) {  
int count = 0;
while(count != 0xa) {  
count = getchar_unlocked(); 
} 
return;
}






int main(void) { 

char *guess = malloc(5); 
char *printstr = malloc(20);  
int compres = 0;
int counter = 0;
int sn,tr;
 
printf("MASTERMIND V1.3.3.7\n\nPress enter to begin\n\n");
sn = generate_number();  
while(compres != 40) {
   stdflush(); 
   counter++;   
   memset(guess,0,5); 
   memset(printstr,0,20);
   *guess = 0; 
   printf("sekrit_number = %i\n",sn);
   printf("Guess a number: "); 
   fgets(guess,5,stdin); 
   tr = transmute_char(guess);
   if(tr == 0) { 
      printf("invalid input detected nerd\n"); 
      continue;  
   }  
   compres = master_compare(tr,sn);  
   master_strings(compres,printstr,20); 
   puts(printstr); 
    
}
printf("You win! It took you %i guesses.\n",counter); 
free(guess);
free(printstr); 
return 0;

} 




