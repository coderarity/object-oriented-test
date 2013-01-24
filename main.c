#include <stdlib.h>
#include <stdio.h>

#include "dog.h"

int main (int argc, char* argv[]) {
  dog_t* dog = malloc(sizeof(dog_t));
  Dog.new(dog, "Scruffy", "white", "small");

  animal_t cat;
  Animal.new(&cat, "cat", "Garfield");

  printf("%s is a %s %s %s!\n", ((animal_t*)dog)->name, Dog.getSize(dog), Dog.getFurColor(dog), Animal.getType((animal_t*)dog));

  Animal.speak((animal_t*)dog);
  Animal.speak(&cat);

  Animal.delete(&cat);

  Dog.delete(dog);
  free(dog);

  return 0;
}
