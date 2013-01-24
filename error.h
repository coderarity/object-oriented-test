#ifndef ERROR_H
#define ERROR_H

#include <errno.h>

#define ERROR_VAL -1
#define SUCCESS_VAL 0
#define ERROR (err) { errno = (err); }

#endif // ERROR_H
