#include <stdio.h>

#define STAMPA printf("%d \n", giorno)

int main(void) {
  int anno = 1901;
  int giorno = 1; /* 0 - 6 */
  do {
    STAMPA;
    giorno = (giorno + 31) %7;
    STAMPA;
    giorno = (giorno + (anno % 4 == 0? 29 : 28)) %7;
    STAMPA;
    giorno = (giorno + 31) %7;
    STAMPA;
    giorno = (giorno + 30) %7;
    STAMPA;
    giorno = (giorno + 31) %7;
    STAMPA;
    giorno = (giorno + 30) %7;
    STAMPA;
    giorno = (giorno + 31) %7;
    STAMPA;
    giorno = (giorno + 31) %7;
    STAMPA;
    giorno = (giorno + 30) %7;
    STAMPA;
    giorno = (giorno + 31) %7;
    STAMPA;
    giorno = (giorno + 30) %7;
    STAMPA;
    giorno = (giorno + 31) %7;
  } while (++anno <= 2000);

  return 0;
}
