#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> 
#include <string.h> 
#include "mmlib.h"
#include "mmfile.h"
#include "mmauto.h"

//helper function for flushing stdin garbage and holding the enter screen
void stdflush(void) {
   int count = 0;
   while(count != 0xa) {
      count = getchar();
                       }
   return;
                    }


int main(void) {

   char *guess = malloc(5);
   char *printstr = malloc(20);
   pthread_t ghost;
   int autotimer = 10;
   int compres = 0;
   int counter = 0;
   int sn,tr;
   int filereturn;
   char *mmkey = malloc(5);
   memset(mmkey,0,5); 
   filereturn = mm_fileopen(mmkey,5);

   if(!filereturn) {
      mm_sekrit = transmute_char(mmkey);
      free(mmkey);
                   }
   //kick off autoplay
   pthread_create(&ghost,NULL,&autoghost,(void *) &autotimer);
   printf("MASTERMIND V1.3.3.7\n\nPress enter to begin\n\n");
   stdflush();
   player = 1;
   if(!mm_sekrit)
      sn = generate_number();
   else
      sn = mm_sekrit;
   sleep(1);

   while(compres != 40) {
      counter++;
      memset(guess,0,5);
      memset(printstr,0,20);
      printf("Guess a four digit number: "); 
      fgets(guess,5,stdin); 
      tr = transmute_char(guess);

      if(tr == 0) {
         printf("invalid input detected nerd\n"); 
         printf("Press enter to continue\n"); //provide input to stdflush()
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




