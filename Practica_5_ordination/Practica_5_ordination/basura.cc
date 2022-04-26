#include <iostream>
int main() {
  /// Display ramdom numbers between 1000 y 9999

  srand(time(NULL));
  int max_number{1000};
  int min_number{9999};
  for (int i = 0; i < 100000000; i++) {
    int number =  rand() %(9999-1000 + 1) + 1000;
    if (number > max_number) {
      max_number = number;
    }
    if (number < min_number) {
      min_number = number;
    }
  }
  std::cout << "min_number" << min_number << std::endl;
  std::cout << "max_number" << max_number << std::endl;
}