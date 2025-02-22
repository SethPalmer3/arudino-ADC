#ifndef ARDN_SERIAL
#define ARDN_SERIAL

typedef struct arudino_serial {
  int baudrate;
  int (*begin)();
  int (*write)(int, char *);
  void (*free)(struct arudino_serial *);
} Serial;

#endif // !ARDN_SERIAL
