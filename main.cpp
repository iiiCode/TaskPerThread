#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    for (int i = 0; i < 11; i ++) {
        printf("MainThread: Do more work...\n");
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    IThread *thread;
    CalcPI *calc;
    CalcMatrix *matrix;

    thread = new Thread();
    calc = new CalcPI(ResultCallBack);
    thread->Dispatch(calc);

    matrix = new CalcMatrix(ResultCallBack);
    thread->Dispatch(matrix);

    DoMoreWork();

    delete calc;
    delete matrix;
    delete thread;
    return 0;
}

