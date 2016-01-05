#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include "IThread.h"

class Thread : public IThread {
    public:
        Thread() {}
        virtual ~Thread();

        virtual void Dispatch(IRunnable *runnable) override;

    private:
        pthread_t mPtid;
};

#endif //_THREAD_H_
