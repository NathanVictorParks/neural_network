#include <iostream>
#include "layer.h"
#include <iomanip>
int main() {
  std::vector<double> in = {1,1,1}, out;
  Layer l1(5, 5);
  out = l1.push(in);
  for (unsigned int i = 0; i < out.size(); i++) {
    std::cout << out[i] << ' ' << std::endl;
  }
  /*
  for (size_t i = 0; i < 100; i++) {
    double r = double(rand() % 100)/60;
    std:: cout << std::setprecision(2) << r << std::endl;
  }*/
}
