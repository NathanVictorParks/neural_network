#include "layer.h"

Layer::Layer() {}

Layer::Layer(std::vector<std::vector<double>> w, std::vector<double> b) {
  if (!b.size()) {
    b.resize(w.size());
  }
  for (unsigned int i = 0; i < w.size(); i++) {
    Node *tmp = new Node(w[i], b[i]);
    nodes.push_back((*tmp));
  }
}

std::vector<double> Layer::push(std::vector<double> in) {
  std::vector<double> output;
  output.resize(nodes.size());
  for (unsigned int i = 0; i < nodes.size(); i++) {
    output[i] = nodes[i].push(in);
  }
  return output;
}
