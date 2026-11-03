#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main(int argc, char *argv[]) {

  int interval;
  int samples;
  int i;
  int j;
  int time;
  struct pstat st;

  if(argc != 3){       // check to be sure that user has inputted 2 arguments
    printf(2, "Usage: monitor interval samples\n");
    exit();
  }

  interval = atoi(argv[1]); // converts from strings to int
  samples = atoi(argv[2]);

  if(interval <= 0 || samples <= 0){
    printf(2, "Interval and samples must be positive\n"); // Error if the samples are not positive
    exit();
  }

    printf(1, "Time | PID | Tickets | Ticks\n");

  for(i = 0; i < samples; i++){ // repeats for the requested number of samples
    sleep(interval);  // pause between intervals

    time = uptime(); // records the tick count

    if(getpinfo(&st) < 0){ // gets stats
      printf(2, "getpinfo failed\n");
      exit();
    }

    for(j = 0; j < NPROC; j++){ // checks all table slots
      if(st.inuse[j]){ // one actiuve print process
        printf(1, "%d |  %d  |   %d   | %d\n",
          time,
          st.pid[j],
          st.tickets[j],
          st.ticks[j]);
      }
    }
  }

  exit();
}
