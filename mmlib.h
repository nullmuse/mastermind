#include <time.h>
#include <stdlib.h> 


//Convert ascii representation of number to int
//Adapted from my timestable code
int transmute_char(char *subject) {
   int len = strlen(subject) - 1;
   int i,new = 0;

   for(i = 1;len >= 0;--len,i *= 10) {
      //built in handling of non-integer input
      if(subject[len] > 0x39 || subject[len] < 0x30) {
         return 0;
                                                     }
      new += (subject[len] - 0x30) * i;
                                     }
   return new;
                                  }

//Convert integer to ascii representation
//Adapted from my timestable code 
char *transmute_int(int subject, int size) {
   int container = 0;
   int count = size - 1;
   int check = 0;
   char *new = malloc(size); //freeing the memory left to caller
   memset(new,0,size);

   while(subject) {
      container = subject % 10;
      subject /= 10;
      new[--count] = container + 0x30;
      check++;
                  }

   return new;
                                           }
//generate a mastermind number
int generate_number(void) {
   int sekrit_number = 0;
   srand(time(NULL));
   while(!(sekrit_number / 1000))
      sekrit_number = rand() % 9999;
   return sekrit_number;

                          }
//mastermind core comparison logic
//returns an int, with the amount of reds in the tenths place, and whites in the ones
int master_compare(int guess, int sekrit) {
   int retnum = 0;
   char *guess_s = transmute_int(guess,5);
   char *sekrit_s = transmute_int(sekrit,5); 
   char *comp;
   int len = strlen(sekrit_s); 
   int i;
   char *selection = malloc(2);
   selection[1] = '\0';  
   for(i=0;i < len;++i) {
      //gather all red, replace with a's to remove them from future comparisons
      if(guess_s[i] == sekrit_s[i]) {
         retnum += 10; 
         guess_s[i] = 'a'; 
         sekrit_s[i] = 'a';
                                    }
                                     }

   for(i=0;i < len;++i) {
      //gather all whites, replace with a's to remove them from future comparisons
      if(guess_s[i] != 'a') {
         selection[0] = guess_s[i];
         comp = strstr(sekrit_s,selection);

         if(comp != 0) {
            *comp = 'a';
            retnum += 1;
            comp = 0;
                       }
                            }
                        }
  free(selection);
  free(sekrit_s);
  free(guess_s);
  return retnum;
                                          }
//mastermind guess result handling
void master_strings(int results, char *string, int slen) {
   char *tmpbuf = malloc(slen);
   int red = results / 10; //reds stored in tenths place
   int white = results % 10; //whites stored in ones
   memset(tmpbuf,0,slen);
   memset(string,0,slen);


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

