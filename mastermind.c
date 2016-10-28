#include <stdio.h> 
#include <string.h> 
#include "mmlib.h"


int main(void) { 

char *guess = malloc(5); 
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
printf("%i\n",master_compare(tr,sn));
 
free(guess);
return 0;

} 




