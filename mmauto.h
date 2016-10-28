#include <sys/mman.h>
#include <errno.h>
#include <pthread.h> 

int player = 0;

void *autoghost(void *this) {

int seconds = 10; 

for(; seconds > 0; --seconds) { 
sleep(1); 
if(player)
return;
} 
printf("No player detected\n"); 

return; 

}
