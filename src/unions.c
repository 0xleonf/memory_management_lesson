#include "unions.h"
#include <stdio.h>

#define UINT_MAX 4294967295

void format_object(snek_object_t obj, char *buffer) {
  switch (obj.kind) {
  case INTEGER:
    sprintf(buffer, "int:%d", obj.data.v_int);
    return;

  case STRING:
    sprintf(buffer, "string:%s", obj.data.v_string);
    return;
  }
}

snek_object_t new_integer(int i) {
  return (snek_object_t){.kind = INTEGER, .data = {.v_int = i}};
}

snek_object_t new_string(char *str) {
  return (snek_object_t){.kind = STRING, .data = {.v_string = str}};
}

// int main() {
//   val_or_err_t lanes_score = {.value = -420};
//   printf("value (set): %d\n", lanes_score.value);
//   printf("err (unset): %u\n", lanes_score.err);
//
//   val_or_err_t teejs_score = {.err = UINT_MAX};
//   printf("value (unset): %d\n", teejs_score.value);
//   printf("err (set): %u\n", teejs_score.err);
// }
