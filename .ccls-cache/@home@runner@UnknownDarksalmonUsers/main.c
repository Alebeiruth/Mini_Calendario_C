#include <stdbool.h>
#include <stdio.h>

bool is_leap_year(int year) {
  if (year % 4 != 0) {
    return false;
  } else if (year % 100 != 0) {
    return true;
  } else if (year % 400 != 0) {
    return false;
  } else {
    return true;
  }
}

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void add_days(int *dd, int *mm, int *yy, int day_faltam_add) {
  int day_faltam_mes;
  while (day_faltam_add > 0) {
    day_faltam_mes = days[*mm] - *dd;
    if (*mm == 2 && is_leap_year(*yy)) {
      day_faltam_mes++;
    }
    if (day_faltam_add >= day_faltam_mes) {
      day_faltam_add -= day_faltam_mes;
      *dd = 1;
      day_faltam_add--;
      if (*mm != 12) {
        *mm = *mm + 1;
      } else {
        *mm = 1;
        *yy = *yy + 1;
      }
    } else {
      *dd += day_faltam_add;
      day_faltam_add = 0;
    }
  }
}

int main() {
  int mm, dd, yy, day_faltam_add;
  printf("mm dd yy num:\n");
  scanf("%d%d%d%d", &mm, &dd, &yy, &day_faltam_add);
  add_days(&mm, &dd, &yy, day_faltam_add);
  printf("%d %d %d\n", mm, dd, yy);
}