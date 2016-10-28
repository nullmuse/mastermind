#include <stdio.h> 
#include <string.h> 
#include "mmlib.h"


int main(void) { 

char *guess = malloc(5); 


fgets(guess,5,stdin);


int tr = transmute_char(guess);
if(!tr) { 
printf("invalid input detected nerd\n"); 
exit(2); 
} 
printf("You entered %i\n",tr); 
printf("Also known as %s\n",transmute_int(tr)); 
printf("sekrit_number = %i\n",generate_number()); 

free(guess);
return 0;

} 




