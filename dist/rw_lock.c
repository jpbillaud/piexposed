#include "lock.h"

/*
 * Implement a read-write lock mechanism.
 */

typedef struct rwlock_t {
   mutex_t *mx;
   cond_t  *cd;
   int     nbreaders;
} rwlock_t;

void rw_rlock(rwlock_t *rwlock)
{
   mx_lock(rwlock->mx);
   rwlock->nbreaders++;
   mx_unlock(rwlock->mx);
}

void rw_runlock(rwlock_t *rwlock)
{
   mx_lock(rwlock->mx);
   if (--rwlock->nbreaders == 0) {
      cond_signal(rwlock->cd);
   }
   mx_unlock(rwlock->mx);
}

void rw_wlock(rwlock_t *rwlock)
{
   mx_lock(rwlock->mx);
   while (rwlock->nbreaders != 0) {
      cond_wait(rwlock->cd, rwlock->mx);
      mx_lock(rwlock->mx);
   }
}

void rw_wunlock(rwlock_t *rwlock)
{
   mx_unlock(rwlock->mx);
}
