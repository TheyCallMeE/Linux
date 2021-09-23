#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

static void printOctal(unsigned int num) {
  char n[16];
  int idx = sizeof(n) - 1;

  while (num != 0) {
    int rem = num & 7;
    n[idx] = rem + '0';
    idx--;
    num >>= 3;
  }
  for (int i = idx + 1; i < sizeof(n); i++) {
    fputc(n[i], stdout);
  }
}

static void printHex(unsigned int num, bool upper) {
  char n[16];
  int idx = sizeof(n) - 1;

  while (num != 0) {
    int rem = num & 15;
    if (rem > 9) {
      n[idx] = rem - 10 + (upper ? 'A' : 'a');
    } else {
      n[idx] = rem + '0';
    }
    num >>= 4;
    idx--;
  }
  for (int i = idx + 1; i < sizeof(n); i++) {
    fputc(n[i], stdout);
  }
}

static void printDecimal(int num) {
  char n[16];
  int idx = sizeof(n) - 1;
  bool neg = false;
  if (num < 0) {
    neg = true;
    num = -num;
  }
  while (num != 0) {
    n[idx] = '0' + num % 10;
    num /= 10;
    idx--;
  }
  if (neg) {
    n[idx] = '-';
    idx--;
  }
  for (int i = idx + 1; i < sizeof(n); i++) {
    fputc(n[i], stdout);
  }
}

void Printf(char* str, ...) {
  // Parse the string for % signs
  //  If a %s is found give the type char * to va_arg so it can increment the
  //  pointer If a %d is found give the type int to va_arg
  va_list ap;

  va_start(ap, str);

  while (*str != '\0') {
    if (*str == '%') {
      switch(*++str) {
        case 'd': 
          printDecimal(va_arg(ap, int));
          break;
        case 's':
          fputs(va_arg(ap, char*), stdout);
          break;
        case 'x':
        case 'X':
          printHex(va_arg(ap, unsigned int), *str == 'X');
          break;
        case 'o':
          printOctal(va_arg(ap, unsigned int));
          break;
        case 'c':
          fputc((char)va_arg(ap, int), stdout);
          break;
        default :
          fputc('%', stdout);
          fputc(*str, stdout);
          break;
      }
    } else {
      fputc(*str, stdout);
    }
    str++;
  }

  va_end(ap);
}

int main(int argc, char* argv[]) {
  Printf("This is the %Xst test %s for Printf version %c.%d\n", -11, "string",
         'a', -67);
  return 0;
}
