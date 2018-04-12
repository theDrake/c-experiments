void print_cubes(void);
void print_pythagorean_triples(int low, int high);

int main(void) {
  /* Print all integers with the cube property */
  print_cubes();

  /* Print all triples [1, 100) */
  print_pythagorean_triples(1, 100);

  return 0;
}
