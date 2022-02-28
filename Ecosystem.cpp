#include <iostream>
#include <cstdlib>
#include <ctime>
#include "class_Ecosystem.h"

using namespace std;

int main(int argc, char** argv) {
	srand(time(NULL));                                                                        /* Initialize the seed using the function time */
  Ecosystem eco(10, 100);
	eco.PrintEcosystem();
  return 0;
}
