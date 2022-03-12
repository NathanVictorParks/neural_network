#ifndef LAYER_H
#define LAYER_H
#include "node.h"

class Layer: public Node {
protected:
  std::vector<Node> nodes;
 public:
  Layer();
  Layer(int w, int b);
  Layer(std::vector<std::vector<double>> w, std::vector<double> b);
  std::vector<double> push(std::vector<double> in);
};

#endif
