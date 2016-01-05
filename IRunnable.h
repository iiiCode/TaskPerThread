#ifndef _I_RUNNABLE_H_
#define _I_RUNNABLE_H_

#include "Base.h"

interface IRunnable {
    virtual ~IRunnable() {};
    virtual void Run() = 0;
};

#endif //_I_RUNNABLE_H_
