#include <stdio.h>
#include <unistd.h>
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
  printf ("Enter the number: ");
  scanf ("%d", &num);
  j = num;
  printf ("%d\n", j);
  starttick = rdtsc();

  double fhalf = 1;
  for (int i=1; i <= num; i = i + 1){
      fhalf = fhalf * i;
  }

  endtick = rdtsc();
  processtime = (double)(endtick - starttick) / 2500000000;
  printf("The factorial of %d is %f\n",j,fhalf);
  printf("Tempo total: %f seconds\n", processtime);
  printf("Fim.\n");
}
