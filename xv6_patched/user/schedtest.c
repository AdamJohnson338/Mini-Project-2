#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main(int argc, char *argv[])
{
 int i;
 int rc;
 int tickets;

 printf(1, "Parent PID: %d\n", getpid());
 for(i = 1; i < argc; i++)
 {
  tickets = atoi(argv[i]);

  // Child Process
  rc = fork();

  if(rc == 0)
  {   
   if(settickets(tickets) == -1)
   {
    printf(1, 
           "settickets failed\n");
    exit();
   }

   printf(1,
          "PID: %d, Tickets: %d\n",
	  getpid(),
	  tickets);
   for(;;){}
  }
 }
 exit();
}
