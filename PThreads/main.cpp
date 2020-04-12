#include <iostream>
#include <thread>

/* function executed by thread */
void myRun ();

int main() {

    /* variable for number of threads that will be used */
    int numThreads = 4;

    /* create an empty array of thread pointers of length numThreads */
    std::thread* threads[numThreads];

    /* loop through the thread array and start each thread */
    for (int i=0; i<numThreads; i++) {
        /* this statement creates a new thread and returns a pointer to it */
        std::thread* th = new std::thread(myRun);

        /* stores the pointer to the thread into the array of thread pointers */
        threads[i] = th;
    }

    /* loop joins all the open threads */
    for (int i=0; i<numThreads; i+=1) {
        threads[i]->join();
    }

    return 0;
}

void myRun () {
    /* implementation of the process that will be run by the thread */
}
