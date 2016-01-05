#ifndef _I_THREAD_H_
#define _I_THREAD_H_

#include "Base.h"
#include "IRunnable.h"

interface IThread {
    virtual ~IThread() {};
    virtual void Dispatch(IRunnable *) = 0;
};

#endif //_I_THREAD_H_
