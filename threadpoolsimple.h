#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <assert.h>

void pool_init (int max_thread_num);
/*向线程池中加入任务*/
int pool_add_worker (void *(*process) (void *arg), void *arg);
/*销毁线程池，等待队列中的任务不会再被执行，但是正在运行的线程会一直
把任务运行完后再退出*/
int pool_destroy ();
//非常重要的任务接口函数，各子线程统一调用这个函数，而这个函数内部检查调用任务队列中的实际任务函数指针。
void * thread_routine (void *arg);

#endif
