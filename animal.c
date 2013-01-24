#include "animal.h"

int animal_new(animal_t* self, const char* type) {
  if (type == NULL) {
    return ERROR_VAL;
  }

  self->type = malloc(strlen(type)+1);
  strcpy(self->type, type);

  return SUCCESS_VAL;
}

int animal_delete(animal_t* self) {
  if (self->type != NULL) {
    free(self->type);
    self->type = NULL;
  }

  return SUCCESS_VAL;
}

void animal_speak(animal_t* self) {
  if (self->vtable.speak) {
    return self->vtable.speak(self);
  }

  printf("This %s cannot speak!", self->type);
}
