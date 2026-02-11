#ifndef UNIONS_H
#define UNIONS_H

#include <stdint.h>

// Union
typedef enum SnekObjectKind {
  INTEGER,
  STRING,
} snek_object_kind_t;

typedef union SnekObjectData {
  int v_int;
  char *v_string;
} snek_object_data_t;

typedef struct SnekObject {
  snek_object_kind_t kind;
  snek_object_data_t data;
} snek_object_t;

// Memory layout
typedef union {
  int value;
  unsigned int err;
} val_or_err_t;

// Union size
union SensorData {
  long int temperature;
  long int humidity;
  long int pressure;
};

union PacketPayload {
  char text[256];
  unsigned char binary[256];
  struct ImageData {
    int width;
    int height;
    unsigned char data[1024];
  } image;
};

union Item {
  struct {
    int damage;
    int range;
    int size;
  } weapon;
  struct {
    int healingAmount;
    int duration;
  } potion;
  struct {
    int doorID;
  } key;
};

// Helper field
typedef struct {
  uint16_t src_port;
  uint16_t dest_port;
  uint32_t seq_num;
} tcp_header_t;

typedef union PacketHeader {
  tcp_header_t tcp_header;
  char raw[8];
} packet_header_t;

// Union
snek_object_t new_integer(int);
snek_object_t new_string(char *str);
void format_object(snek_object_t obj, char *buffer);

#endif // !UNIONS_H
