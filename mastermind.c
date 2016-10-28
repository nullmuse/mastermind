#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> 
#include <string.h> 
#include "mmlib.h"
#include "mmauto.h"
static char *MARKER = "DEAD"; 
static char *PASS = "ABCD";


void stdflush(void) {  
int count = 0; 
while(count != 0xa) {  
count = getchar(); 
} 
return;
}






int main(void) { 
char *autoplay = "deadc0de";
char *guess = malloc(5); 
int PAGE_SIZE = getpagesize();
char *printstr = malloc(20);  
pthread_t ghost; 
int compres = 0;
int counter = 0;
int sn,tr;
printf("%p\n",&autoghost); 
pthread_create(&ghost,NULL,&autoghost,NULL); 
printf("MASTERMIND V1.3.3.7\n\nPress enter to begin\n\n");
stdflush(); 
player = 1; 
sn = generate_number();  
while(compres != 40) {  
   counter++;   
   memset(guess,0,5); 
   memset(printstr,0,20);
   printf("\nsekrit_number = %i\n",sn);
   printf("Guess a four digit number: "); 
   fgets(guess,5,stdin); 
   tr = transmute_char(guess);
   if(tr == 0) { 
      printf("invalid input detected nerd\n"); 
      printf("Press enter to continue\n"); 
      continue;  
   }  
   printf("\nYour guess is %i\n",tr); 
   compres = master_compare(tr,sn);  
   master_strings(compres,printstr,20); 
   puts(printstr); 
   stdflush(); 
}
printf("You win! It took you %i guesses.\n",counter); 
free(guess);
free(printstr); 
return 0;

} 




