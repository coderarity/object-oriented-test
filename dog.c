#include "dog.h"

void dog_speak (void* _self) {
  dog_t* self = _self;
  printf("'woof!' says the %s %s dog!\n", self->size, self->furColor);
}

int dog_new (dog_t* self, const char* furColor, const char* size) {
  if (furColor == NULL || size == NULL) {
    return ERROR_VAL;
  }

  Animal.new(&(self->super), "dog");

  self->super.vtable.speak = &dog_speak;

  self->furColor = malloc(strlen(furColor) + 1);
  strcpy(self->furColor, furColor);

  self->size = malloc(strlen(size) + 1);
  strcpy(self->size, size);

  return SUCCESS_VAL;
}

int dog_delete (dog_t* self) {
  Animal.delete(&self->super);

  if (self->furColor != NULL) {
    free(self->furColor);
    self->furColor = NULL;
  }
  if (self->size != NULL) {
    free(self->size);
    self->size = NULL;
  }

  return SUCCESS_VAL;
}

const char* dog_getFurColor (dog_t* self) {
  return self->furColor;
}

const char* dog_getSize (dog_t* self) {
  return self->size;
}
