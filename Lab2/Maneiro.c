#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> // para o wait()
#include <sys/types.h> // para pid_t
#include <stdlib.h> // para o exit()
#include <stdint.h>

static inline uint64_t rdtsc(void)
{
  uint64_t tick;
  asm volatile ("rdtsc" : "=A" (tick));
  return tick;
}

int main() {
  uint64_t starttick, endtick;
  double processtime;
  int i = 1, num, j;
  pid_t pid;
  int fd[2];

  // Create the pipe
  if (pipe(fd) == -1) {
    perror("pipe");
    return 1;
  }
  printf ("Enter the number: ");
  scanf ("%d", &num);
  j = num;
  num /= 2;

  starttick = rdtsc();
  pid = fork();

  if (pid < 0){
    printf("The child process was not created.\n");
    exit(1);
  }
  else if (pid == 0) { // process son
    double fhalf = 1;
    for (int i=1; i <= num; i = i + 1){
      fhalf = fhalf * i;
    }
    close(fd[0]); // close the read end of the pipe
    write(fd[1], &fhalf, sizeof(fhalf));
    close(fd[1]);
  }
  else { // process father
    double shalf = 1;
    for (int z=j; z > num; z = z - 1){
    shalf = shalf * z;
    }
    wait(NULL);
    double fhalf;
    close(fd[1]); // close the write end of the pipe
    if (read(fd[0], &fhalf, sizeof(fhalf)) == -1) {
      perror("read");
      return 1;
    }
    double ffat = fhalf * shalf;
    endtick = rdtsc();
    processtime = (double)(endtick - starttick) / 2500000000;
    printf("The factorial of %d is %f\n",j,ffat);
    printf("Tempo total: %f seconds\n", processtime);
    printf("Fim.\n");
    exit(0);
  }
}
