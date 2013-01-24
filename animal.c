#include "animal.h"

typedef struct {
  char* type;
} animal_p;

int animal_new(animal_t* self, const char* type, const char* name) {
  if (type == NULL || name == NULL) {
    return ERROR_VAL;
  }

  self->vtable.speak = NULL;
  self->vtable.delete = NULL;

  self->name = malloc(strlen(name)+1);
  strcpy(self->name, name);

  self->private = malloc(sizeof(animal_p));
  animal_p* private = self->private;

  private->type = malloc(strlen(type) + 1);
  strcpy(private->type, type);

  return SUCCESS_VAL;
}

int animal_delete(animal_t* self) {
  if (self->vtable.delete != NULL) {
    return self->vtable.delete(self);
  }

  if (self->name != NULL) {
    free(self->name);
    self->name = NULL;
  }

  if (self->private != NULL) {
    animal_p* private = self->private;
    if (private->type != NULL) {
      free(private->type);
      private->type = NULL;
    }
    free(private);
    self->private = NULL;
  }

  return SUCCESS_VAL;
}

void animal_speak(animal_t* self) {
  if (self->vtable.speak) {
    return self->vtable.speak(self);
  }

  printf("%s cannot speak. Poor %s!\n", self->name, Animal.getType(self));
}

const char* animal_getType(animal_t* self) {
  animal_p* private = self->private;
  return private->type;
}
