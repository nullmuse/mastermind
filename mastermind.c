#include <stdio.h> 
#include <string.h> 
#include "mmlib.h"


int main(void) { 

char *guess = malloc(5);
char *printstr = malloc(20);  
int a; 
int sn; 
fgets(guess,5,stdin);


int tr = transmute_char(guess);
if(!tr) { 
printf("invalid input detected nerd\n"); 
exit(2); 
} 
sn = generate_number(); 
printf("You entered %i\n",tr); 
printf("Also known as %s\n",transmute_int(tr)); 

printf("sekrit_number = %i\n",sn); 
master_strings(master_compare(tr,sn),printstr,20); 
puts(printstr); 
 
free(guess);
return 0;

} 




