#include <iostream>
 
// int main() {
//   int number {5};
//   int &refNumber {number};
//   std::cout << refNumber << std::endl; // 5
//   refNumber = 20;
//   std::cout << number << std::endl;   // 20
// }

int main() {
  int numbers[] {1, 2, 3, 4, 5};
  for (auto n : numbers) {
    n = n * n;
  }
  for (auto n : numbers) {
    std::cout << n << "   ";
  }
  std::cout << std::endl;

  for (auto& n : numbers) {
    n = n * n;
  }
  for (auto n : numbers) {
    std::cout << n << "   ";
  }
  std::cout << std::endl;

  int& b {7 + 8};
  std::cout << "int& b = " << b << std::endl;

  int&& c {7 + 8};
  std::cout << "int&& c = " << c << std::endl;
  
}