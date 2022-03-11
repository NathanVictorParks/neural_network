#include "node.h"  // Copyright [2022] <Nathan Victor Parks>" [Free for Use]

Node::Node() {}

Node::Node(std::vector<double> w, double b = 0) {
  weights = w;
  bias = b;
}

double Node::push(std::vector<double> in) {
  double output = 0;
  for (unsigned int i = 0; i < in.size(); i++) {
    output += in[i] * weights[i];
  }
  output += bias;
  return output;
}
