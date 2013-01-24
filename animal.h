#ifndef ANIMAL_H
#define ANIMAL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "error.h"

typedef struct {
  struct {
    void (*speak)(void* self);
  } vtable;

  void* private;
  char* name;
} animal_t;

int animal_new(animal_t* self, const char* type, const char* name);

int animal_delete(animal_t* self);

void animal_speak(animal_t* self);

const char* animal_getType(animal_t* self);

// Create a nice structure to expose them in :D
static const struct {
  int (*new)(animal_t*, const char*, const char*);
  int (*delete)(animal_t*);

  void (*speak)(animal_t*);
  const char* (*getType)(animal_t*);
} Animal = {
  .new = &animal_new,
  .delete = &animal_delete,
  .speak = &animal_speak,
  .getType = &animal_getType
};

#endif // ANIMAL_H
