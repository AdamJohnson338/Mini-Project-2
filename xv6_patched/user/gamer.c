#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
 int i;
 int start;
 int pid;

 for(i = 0; i < 30; i++) { // Makes the 30 children
   pid = fork(); // child proccess is made

   if(pid < 0) { 
    printf(2, "The fork has failed.  Reason: PID less than zero");
    exit();
   }

   if(pid == 0) { //child identifier
    start = uptime(); // gets elepased time in ticks

    while(uptime() - start < 100) { 
     // Child will run for 100 ticks
    }

    exit();
   }

   sleep(20); // makes parent wait 20 ticks before making another child
  }

 for(i = 0; i < 30; i++) {
  wait(); // makes sure theres no zombies
 }

 exit();
}




