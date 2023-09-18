
#include <iostream>
#include <pthread.h>
#include <unistd.h> // Para sleep()

int flag = 0;
bool should_exit_thread_immediately() {
  if (flag == 0)
    return false;
  std::cout << "the thread should exit" << std::endl;
  return true;
}

class ThreadExitException {
public:
  /* Create an exception signalling thread exit with RETURN_VALUE.  */
  ThreadExitException(void *return_value)
      : thread_return_value_(return_value) {}

  /* Actually exit the thread, using the return value provided in the
     constructor.  */
  void *DoThreadExit() { pthread_exit(thread_return_value_); }

private:
  /* The return value that will be used when exiting the thread.  */
  void *thread_return_value_;
};

void do_some_work() {
  while (1) {
    std::cout << "Working... " << std::endl;
    sleep(1);

    if (should_exit_thread_immediately()) {
      throw ThreadExitException(NULL);
    }
  }
}

void *thread_function(void *) {
  try {
    do_some_work();
  } catch (ThreadExitException ex) {
    /* Some function indicated that we should exit the thread.  */
    ex.DoThreadExit();
  }
  return NULL;
}

int main() {
  pthread_t thread_id;

  pthread_create(&thread_id, NULL, thread_function, NULL);

  sleep(6);

  flag = 1; // indicate exit
  if (should_exit_thread_immediately()) {
    pthread_cancel(thread_id);
    pthread_join(thread_id, NULL);
  }
  return 0;
}