#include <iostream>
#include <vector>

class Node {
 protected:
  std::vector<double> weights;
  double bias;
 public:
  Node();
  Node(std::vector<double> w, double bias);
  double push(std::vector<double> in);
};
////////////////////////////////////////
class Layer: public Node {
 private:
  std::vector<Node> nodes;
 public:
  Layer();
  Layer(std::vector<std::vector<double>> w, std::vector<double> b);
  std::vector<double> operator + (std::vector<double> in);
};
/////////
//  Node
////////
Node::Node() {}

Node::Node(std::vector<double> w, double bias = 0) {
  weights = w;
}

double Node::push(std::vector<double> in) {
  double output = 0;
  for (unsigned int i = 0; i < in.size(); i++) {
    output += in[i] * weights[i];
  }
  output += bias;
  return output;
}
//////////
//  Layer
/////////
Layer::Layer() {}

Layer::Layer(std::vector<std::vector<double>> w, std::vector<double> b = {}) {
  if (!b.size()) {
    b.resize(w[0].size());
  }
  for (unsigned int i = 0; i < w.size(); i++) {
    Node *tmp = new Node(w[i], b[i]);
    nodes.push_back((*tmp));
  }
}
std::vector<double> Layer::operator + (std::vector<double> in) {
  std::vector<double> output;
  output.resize(in.size());
  for(unsigned int i = 0; i < in.size(); i++) {
    output[i] = nodes[i].push(in);
  }
  return output;
}

///////
int main() {
  Layer l1({{1, 2, 3}, {1, 2, 3}});
  Layer l2({{1, 2, 3}, {1, 2, 3}});
}
