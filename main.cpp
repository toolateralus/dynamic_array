#include "array.hpp"
#include <iostream>
#include <string>

int main() {
  Array<int> ints(100);
  ints.push(10);
  std::cout << ints.get(0) << std::endl;
  
  for (int i = 0; i < 1000; ++i) {
    ints.push(i);
  }
  
  for(int i = 0; i < 1000; ++i) {
    std::cout << std::to_string(ints.pop()) << std::endl;
  }
}