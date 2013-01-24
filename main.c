#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "dog.h"

int main (int argc, char* argv[]) {
  dog_t* dog = malloc(sizeof(dog_t));
  Dog.new(dog, "white", "small");

  printf("The %s dog has %s fur!\n", Dog.getSize(dog), Dog.getFurColor(dog));

  Animal.speak((animal_t*)dog);

  Dog.delete(dog);
  free(dog);

  return 0;
}
