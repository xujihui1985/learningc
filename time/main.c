#include <stdio.h>
#include <time.h>

#define TIME_STR_LEN 64

static void greet();

int main() {
  time_t now;
  struct tm *clock;

  time(&now);
  clock = localtime(&now);


  puts("time details");

  printf(" Day of year: %d\n", clock->tm_year);
  printf(" Day of week: %d\n", clock->tm_wday);
  printf(" year: %d\n", clock->tm_year + 1900);
  printf(" month: %d\n", clock->tm_mon + 1);
  printf(" day of the month: %d\n", clock->tm_mday);
  printf(" Hour: %d\n", clock->tm_hour);
  printf(" Minute: %d\n", clock->tm_min);
  printf(" Second: %d\n", clock->tm_sec);

  greet();

  return 0;
}

static void greet() {

  time_t now;
  struct tm *clock;
  char time_str[TIME_STR_LEN];

  time(&now);
  clock = localtime(&now);

  strftime(time_str, TIME_STR_LEN, "Today is %A, %B, %d, %Y%nIt is %r%n", clock);
  printf("%s\n", time_str);
}
