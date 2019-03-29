#include <ctime>
#include <string>
#include <iostream>

#include "molest_cpp_11/cpp_molest.h"

std::string get_greet(const std::string& who) {
  return "Hello " + who;
}

void print_localtime() {
  std::time_t result = std::time(nullptr);
  std::cout << std::asctime(std::localtime(&result));
}

int main(int argc, char** argv) {
    // print_localtime();
    CPPMolest::molest_memcpy();
  return 0;
}