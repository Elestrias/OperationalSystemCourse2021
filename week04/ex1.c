#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int n = fork();
  printf("Hello from %s node PID - %d\n", (n == 0) ? "child" : "parent",
         getpid());
  if (n != 0)
    waitpid(n, NULL, 0);
  return 0;
}