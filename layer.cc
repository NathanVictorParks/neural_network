#include "layer.h"
#include <random>

Layer::Layer() {}

// initializes the layer with random weights and biases.
Layer::Layer(int w, int b) {  // w = num inputs,  b = num of outputs for layer.
  nodes.resize(b);
  for (int i = 0; i < b; i++) {

    std::vector<double> weights(w);

    for (int j = 0; j < w; j++) {
      double weight = (double (std::rand() % 100) / 75)* -1;
      for(int i = 0; i < (std::rand() % 2); i++) {
        weight *= weight;
      }
      weights[j] = weight;
    }

    double bias = double (std::rand() % 100) / 60;
    Node *tmp = new Node(weights, bias);

    nodes[i] = (*tmp);
  }
}

// initializes the layer with preset weights and biases.
Layer::Layer(std::vector<std::vector<double>> w, std::vector<double> b) {
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
