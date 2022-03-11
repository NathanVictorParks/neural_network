#include <iostream>
#include "layer.h"

int main() {
  std::vector<double> in = {1,1,1}, out;
  Layer l1({{1, 2, 3}}, {2, 1});
  Layer l2({{2, 2}}, {5});
  out = l1.push(in);
  out = l2.push(out);
  for (unsigned int i = 0; i < out.size(); i++) {
    std::cout << out[i] << ' ' << std::endl;
  }
}
