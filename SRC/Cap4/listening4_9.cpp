#include <iostream>
#include <pthread.h>
#include <chrono>

extern bool should_exit_thread_immediately();

class ThreadExitException
{
public:
  /* Create an exception signaling thread exit with RETURN_VALUE.  */
  ThreadExitException(void* return_value)
    : thread_return_value_(return_value)
  {
  }

  /* Actually exit the thread, using the return value provided in the
     constructor.  */
  void* DoThreadExit()
  {
    pthread_exit(thread_return_value_);
  }

private:
  /* The return value that will be used when exiting the thread.  */
  void* thread_return_value_;
};

void do_some_work()
{
  while (true) {
    /* Do some useful things here...  */

    if (should_exit_thread_immediately())
      throw ThreadExitException(/* thread's return value = */ nullptr);
  }
}

void* thread_function(void*)
{
  try {
    do_some_work();
  }
  catch (ThreadExitException ex) {
    /* Some function indicated that we should exit the thread.  */
    ex.DoThreadExit();
  }
  return nullptr;
}

int main()
{
  pthread_t thread;
  
  // Create a thread
  if (pthread_create(&thread, nullptr, thread_function, nullptr) != 0) {
    std::cerr << "pthread_create failed" << std::endl;
    return 1;
  }

  // Let the thread run for a while
  //sleep(5);

  // Cancel the thread
  pthread_cancel(thread);

  // Wait for the thread to finish
  if (pthread_join(thread, nullptr) != 0) {
    std::cerr << "pthread_join failed" << std::endl;
    return 1;
  }

  std::cout << "Main thread has finished." << std::endl;
  
  return 0;
}
