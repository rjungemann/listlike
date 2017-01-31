# listlike

A well-tested dead-simple doubly-linked-list library for C.

## Features

* Stack semantics (push, pop, and peek).
* Queue semantics (push and shift).
* List length.
* Does not memory assumptions for items stored (free data yourself).
* Purposely thread-unsafe out of the box (wrap in a mutex yourself).
* Non-breaking API (new features will be added, but no old features removed).
* Given a list, you can look at its `head` or `tail`.
* Given an element, you can look at its `next` or `previous`.

## Usage

Make a file, `main.c`, and make sure that `listlike.h` is in your library path
or the same directory as `main.c`.

```c
#include "listlike.h"

int main (int argc, char **argv) {
  listlike *list = listlike_create();

  char *data1 = "Hello";
  listlike_push(listlike, data1);

  char *data2 = "world";
  listlike_push(listlike, data2);

  printf("%i\n", listlike_length(listlike);

  // Try replacing `listlike_pop` with `listlike_shift`.
  //
  // You can also `listlike_peek` to see what will be popped.
  //
  char *new_data_1 = (char *) listlike_pop(listlike);
  char *new_data_2 = (char *) listlike_pop(listlike);

  printf("%s %s\n", new_data_1, new_data_2);

  // NOTE: If you `malloc`ed the items you popped, make sure to `free` them
  // before destroying the list!

  listlike_destroy(listlike);

  return 0;
}
```

To build:

```bash
clang main.c -o main
./main
```
