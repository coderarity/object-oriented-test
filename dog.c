#include "dog.h"

typedef struct {
  char* furColor;
  char* size;
} dog_p;

void dog_speak (void* _self) {
  dog_t* self = _self;
  printf("'woof!' says the %s %s dog!\n", Dog.getSize(self), Dog.getFurColor(self));
}

int dog_new (dog_t* self, const char* name, const char* furColor, const char* size) {
  if (furColor == NULL || size == NULL) {
    return ERROR_VAL;
  }

  Animal.new(&(self->super), "dog", name);

  self->super.vtable.speak = &dog_speak;

  self->private = malloc(sizeof(dog_p));
  dog_p* private = self->private;

  private->furColor = malloc(strlen(furColor) + 1);
  strcpy(private->furColor, furColor);

  private->size = malloc(strlen(size) + 1);
  strcpy(private->size, size);

  return SUCCESS_VAL;
}

int dog_delete (dog_t* self) {
  Animal.delete(&self->super);

  if (self->private != NULL) {
    dog_p* private = self->private;
    if (private->furColor != NULL) {
      free(private->furColor);
      private->furColor = NULL;
    }
    if (private->size != NULL) {
      free(private->size);
      private->size = NULL;
    }
    free(private);
    self->private = NULL;
  }

  return SUCCESS_VAL;
}

const char* dog_getFurColor (dog_t* self) {
  dog_p* private = self->private;
  return private->furColor;
}

const char* dog_getSize (dog_t* self) {
  dog_p* private = self->private;
  return private->size;
}
