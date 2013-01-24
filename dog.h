#ifndef DOG_H
#define DOG_H

#include <stdlib.h>
#include <string.h>

#include "error.h"

// INHERITS FROM ANIMAL
#include "animal.h"

typedef struct {
  animal_t super;
  char* furColor;
  char* size;
} dog_t;

// Creates a dog, takes fur color and size. Returns pointer to dog. This copies
// the strings.
int dog_new (dog_t* self, const char* furColor, const char* size);

// Deletes a dog. Takes pointer to dog created with dog_ctor D:
int dog_delete (dog_t* self);

// Gets the fur color passed to the constructor, takes pointer to dog created
// with dog_ctor.
const char* dog_getFurColor (dog_t* self);

// Gets the size passed to the constructor, takes pointer to dog created with
// dog_ctor.
const char* dog_getSize (dog_t* self);

// Create a nice structure to expose them in :D
static const struct {
  int (*new)(dog_t*, const char* furColor, const char* size);
  int (*delete)(dog_t*);

  const char* (*getFurColor)(dog_t*);
  const char* (*getSize)(dog_t*);
} Dog = {
  .new = &dog_new,
  .delete = &dog_delete,
  .getFurColor = &dog_getFurColor,
  .getSize = &dog_getSize
};

#endif // DOG_H
