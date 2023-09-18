#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* An array of balances in accounts, indexed by account number.  */

float *account_balances;
int from_account = 0;
int to_account = 1;
float transfer_amount = 50.0;

void *thread_function(void *thread_arg) {
  int old_cancel_state;
  int result = 0;
  /* Check the balance in FROM_ACCT.  */
  if (account_balances[from_account] < transfer_amount) {
    result = 1; // Establecer el valor de retorno
    return (void *)result;
  }

  /* Begin critical section.  */
  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancel_state);
  /* Move the money.  */
  account_balances[to_account] += transfer_amount;
  account_balances[from_account] -= transfer_amount;
  /* End critical section.  */
  pthread_setcancelstate(old_cancel_state, NULL);

  return (void *)result;
}

int main() {
  pthread_t thread;
  int resultado;
  // Initialize account balances (assuming two accounts)
  account_balances = (float *)malloc(2 * sizeof(float));
  account_balances[0] = 100.0; // Initial balance for account 0
  account_balances[1] = 100.0; // Initial balance for account 1

  printf("Initial Balances:\n");
  printf("Account 0: $%.2f\n", account_balances[0]);
  printf("Account 1: $%.2f\n", account_balances[1]);

  pthread_create(&thread, NULL, &thread_function, NULL);

  pthread_join(thread, (void *)&resultado);

  printf("La operacion de transaccion devolvió: %d /n", resultado);

  printf("\nFinal Balances:\n");
  printf("Account 0: $%.2f\n", account_balances[0]);
  printf("Account 1: $%.2f\n", account_balances[1]);
}
