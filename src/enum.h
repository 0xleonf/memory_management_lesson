#ifndef ENUM_H
#define ENUM_H

// Non-default value
typedef enum Colors {
  RED = 55,
  GREEN = 176,
  BLUE = 38,
} color_t;

// Switch case
typedef enum {
  HTTP_BAD_REQUEST = 400,
  HTTP_UNAUTHORIZED = 401,
  HTTP_NOT_FOUND = 404,
  HTTP_TEAPOT = 418,
  HTTP_INTERNAL_SERVER_ERROR = 500
} http_error_code_t;

typedef enum {
  BIG = 123412341234,
  BIGGER,
  BIGGEST,
} BigNumbers;

typedef enum {
  STATUS_OK = 200,
  STATUS_BAD_REQUEST = 400,
  STATUS_FORBIDDEN = 401,
  STATUS_NOT_FOUND = 404,
  STATUS_INTERNAL_SERVER_ERROR = 505,
} HttpStatusCode;

char *http_to_str(http_error_code_t code);

#endif // !ENUM_H
