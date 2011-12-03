#ifndef _LOCK_H_
#define _LOCK_H_

typedef struct mutex_t mutex_t;

/* Lock mutex */
void mx_lock(mutex_t *mx);

/* Unlock mutex */
void mx_unlock(mutex_t *mx);

typedef struct cond_t cond_t;

/* Wait for condition variable to be signaled while releasing given mutex */
void cond_wait(cond_t *cd, mutex_t *mx);

/* Signal condition variable  */
void cond_signal(cond_t *cd);

#endif /* _LOCK_H_ */
