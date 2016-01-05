#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <memory>

#include "Thread.h"
#include "IThread.h"
#include "IRunnable.h"

typedef void (*CallBack)(const char *);

class CalcPI : public IRunnable {
    public:
        CalcPI(CallBack cb) { mCallBack = cb; }
        virtual ~CalcPI() {}

        virtual void Run() {
            //calc pi...
            for (int i = 0; i < 10; i ++) {
                mCallBack("3.14");
                sleep(1);
            }
        }
    
    private:
        CallBack mCallBack;
};

class CalcMatrix : public IRunnable {
    public:
        CalcMatrix(CallBack cb) { mCallBack = cb; }
        virtual ~CalcMatrix() {}

        virtual void Run() {
            //calc matrix...
            for (int i = 0; i < 10; i ++) {
                mCallBack("abcdef");
                sleep(1);
            }
        }

    private:
        CallBack mCallBack;
};

static void ResultCallBack(const char *data)
{
    printf("%s\n", data);
}

static void DoMoreWork() 
{
    for (int i = 0; i < 15; i ++) {
        printf("MainThread: Do more work...\n");
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    std::shared_ptr<IThread> thread;
    std::shared_ptr<CalcPI> calc;
    std::shared_ptr<CalcMatrix> matrix;

    thread = std::make_shared<Thread>();
    calc = std::make_shared<CalcPI>(ResultCallBack);
    thread->Dispatch(calc);

    matrix = std::make_shared<CalcMatrix>(ResultCallBack);
    thread->Dispatch(matrix);

    DoMoreWork();

    return 0;
}

