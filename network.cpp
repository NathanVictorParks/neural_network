#include <iostream>
#include <vector>

class Node {
 protected:
  std::vector<double> weights;
  double value, bias;
 public:
  Node();
  Node(std::vector<double> w);
};
////////////////////////////////////////
class Layer: public Node {
 private:
  std::vector<Node> nodes;
 public:
  Layer();
  Layer(std::vector<std::vector<double>> w);
};
/////////
//  Node
////////
Node::Node() {
  value = 0;
}
Node::Node(std::vector<double> w) {
  weights = w;
  value = 0;
}
//////////
//  Layer
/////////
Layer::Layer() {}

Layer::Layer(std::vector<std::vector<double>> w) {
  for (unsigned int i = 0; i < w.size(); i++) {
    Node *tmp = new Node(w[i]);
    nodes.push_back((*tmp));
  }
}
///////
int main() {
  Layer l({{1, 2, 3}, {1, 2, 3}});
}
