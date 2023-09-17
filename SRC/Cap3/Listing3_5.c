#include <signal.h>
#include <stdio.h>
#include <setjmp.h>

sig_atomic_t sigfpe_count = 0;
jmp_buf env;

void handler(int signal_number) {
  printf ("Excepción de punto flotante capturada.\n");
  ++sigfpe_count;
  longjmp(env, 1);
}

int main() {
  struct sigaction sa;
  sa.sa_handler = &handler;
  sigaction(SIGFPE, &sa, NULL);

  int a = 0;
  int b = 0;

  if (setjmp(env) == 0) {
    int c = a / b; // Esto lanzará SIGFPE
  } else {
    printf("Se evitó una división por cero.\n");
  }
  longjmp(env, 0);

  printf("SIGFPE se lanzó %d veces\n", sigfpe_count);
  return 0;
}
