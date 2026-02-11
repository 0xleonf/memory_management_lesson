#include "enum.h"
#include "../munit/munit.h"
#include <stdio.h>

char *http_to_str(http_error_code_t code) {
  switch (code) {
  case HTTP_BAD_REQUEST:
    return "400 Bad request";
    break;

  case HTTP_UNAUTHORIZED:
    return "401 Unauthorized";
    break;

  case HTTP_NOT_FOUND:
    return "404 Not found";
    break;

  case HTTP_TEAPOT:
    return "418 I AM A TEAPOT!";
    break;

  case HTTP_INTERNAL_SERVER_ERROR:
    return "500 Interval Server Error";
    break;

  default:
    return "Unknown HTTP status code";
  }
}

int main() {
  printf("The size of BigNumbers is %zu bytes\n", sizeof(BigNumbers));
  ;
  printf("The size of HttpStatusCode is %zu bytes\n", sizeof(HttpStatusCode));
  ;

  return 0;
}
