#include <sys/mman.h>
#include <errno.h>
#include <pthread.h> 

int player = 0;

void *autoghost(void *timer) {
   char *autostring = "Autoplay: Press enter to start playing";
   int seconds = 10; 
   int auto_compres;
   int auto_counter;
   int *timerargs;
   char *auto_guess = malloc(5);
   char *auto_printstr = malloc(20);
   int auto_tr,auto_sn;

   if(timer) {
      timerargs = (int *) timer; 
      seconds = *timerargs;
             }

   for(; seconds > 0; --seconds) {
      sleep(1); 

      if(player) {
         free(auto_guess); 
         free(auto_printstr);
         pthread_exit(0); 
                 }
                                 }

   printf("No player detected. Beginning autoplay\n");
   while(1) {
      if(!mm_sekrit)
         auto_sn = generate_number();
      else
         auto_sn = mm_sekrit;
      auto_compres = 0;
      auto_counter = 0;

      while(auto_compres != 40) {
         auto_counter++;
         memset(auto_guess,0,5);
         memset(auto_printstr,0,20);
         printf("\nsekrit_number = %i\n",auto_sn);
         puts(autostring);
         printf("Guess a four digit number: ");
         sleep(1);
         auto_tr =  generate_number();
         if(player)
            goto PLAYER;
         printf("\nYour guess is %i\n",auto_tr);
         auto_compres = master_compare(auto_tr,auto_sn);
         master_strings(auto_compres,auto_printstr,20);
         puts(auto_printstr);
                                }

         printf("You win! It took you %i guesses.\n",auto_counter);
            }

PLAYER:
printf("\n\nPlayer detected: Ending Autoplay\n\n\n\n");
free(auto_guess);
free(auto_printstr);
pthread_exit(0); 
                            }
