#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

sig_atomic_t child_exit_status;

void clean_up_child_process(int signal_number) {
  /* Clean up the child process.  */
  int status;
  wait(&status);
  /* Store its exit status in a global variable.  */
  child_exit_status = status;
  printf("Cleaning child process\n");
}

int main() {
  /* Handle SIGCHLD by calling clean_up_child_process.  */
  struct sigaction sigchld_action;
  memset(&sigchld_action, 0, sizeof(sigchld_action));
  sigchld_action.sa_handler = &clean_up_child_process;
  sigaction(SIGCHLD, &sigchld_action, NULL);

  /* Now do things, including forking a child process.  */
  /* ...  */

  pid_t child_pid;

  /* Create a child process.  */
  child_pid = fork();
  if (child_pid > 0) {
    /* This is the parent process.  Sleep for a minute.  */
    sleep(60);
  } else {
    /* This is the child process.  Exit immediately.  */
    exit(0);
  }

  if (WIFEXITED(child_exit_status))
    printf("the child process exited normally, with exit code %d\n",
           WEXITSTATUS(child_exit_status));
  else
    printf("the child process exited abnormally\n");

  return 0;
}