#include <stdio.h>
#include <stdarg.h>

// '...' is for a variadic function
// va_arg does not know how many arguments there are
//  so we either pass NULL at the end or a number of arguments at the beginning
//  Elected to do latter
void foo(int n, ...) {
  // List for the macros
  va_list ap;

  // Initializes the list for subsequent use by other macros
  va_start(ap, n);

  while (n-- > 0) {
    printf("%s\n", va_arg(ap, char*));
  }

  // Matches va_start and now the argument is undefined
  va_end(ap);
}

int main(int argc, char* argv[]) {
  foo(7, "one", "two", "three", "four", "five", "six", "seven");
  return 0;
}
