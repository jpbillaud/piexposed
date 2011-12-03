#include "lock.h"

/*
 * Implement a barrier mechanism where a given number of concurrent clients need
 * to ask for the barrier resource before resuming work.
 */

typedef struct barrier_t {
   mutex_t *mx;
   cond_t  *cd;
   int      count;
   int      nbclients;
} barrier_t;

void barrier_wait(barrier_t *barrier)
{
   mx_lock(barrier->mx);
   barrier->count++;
   if (barrier->count != barrier->nbclients) {
      cond_wait(barrier->cd, barrier->mx);
   } else {
      cond_signal(barrier->cd);
      mx_unlock(barrier->mx);
   }
}
