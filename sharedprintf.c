#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char* argv[]) {
  void *handle;
  char *error;
  typedef void (*Func)(char *, ...);
  Func fptr;

  handle = dlopen("./libfoo.so", RTLD_LAZY);
  if (handle == NULL) {
    perror("dlopen");
    return 1;
  }

  // Clears any existing error, helps dlsym distinguish between
  //  a symbol NULL and an error NULL
  dlerror();

  // Find address of function
  fptr = (Func)dlsym(handle, "Printf");

  // Check the error to ensure there is none
  error = dlerror();
  if (error != NULL) {
    perror(error);
    return 1;
  } 

  // Invoke the function
  fptr("The shared %s test of my Printf, attempt %d.%x\n", "library", 20, 86);

  // Close the opened handle
  dlclose(handle);

  return 0;
}
