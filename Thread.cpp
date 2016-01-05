#include "Thread.h"

static void *_DoThreadWork(void *argv)
{
    IRunnable *runnable;

    runnable = static_cast<IRunnable *>(argv);
    runnable->Run();

    return NULL;
}

Thread::~Thread()
{
    pthread_join(mPtid, NULL);
}

void Thread::Dispatch(IRunnable *runnable)
{
    pthread_create(&mPtid, NULL, _DoThreadWork, static_cast<void *>(runnable));
}
