#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

// Prints the processes currently in the process table.
int
main(int argc, char *argv[])
{
 struct pstat st;
 int i;
 if(getpinfo(&st) < 0){
  printf(2, "getpinfo failed\n");
  exit();
 }
 printf(1, "PID\tSize\tTickets\tStride\tPass\n");
 for(i = 0; i < NPROC; i++){
  if(st.inuse[i])
   printf(1, "%d\t%d\t%d\t%d\t%d\n", st.pid[i], st.size[i], st.tickets[i], st.stride[i], st.pass[i]);
 }
 exit();
}
