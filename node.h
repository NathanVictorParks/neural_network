#ifndef NODE_H
#define NODE_H
#include <vector>

class Node {
 protected:
  std::vector<double> weights;
  double bias;
 public:
  Node();
  Node(std::vector<double> w, double b);
  double push(std::vector<double> in);
};
#endif
