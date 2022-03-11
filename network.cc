#include <iostream>
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
////////////////////////////////////////
class Layer: public Node {
 private:
  std::vector<Node> nodes;
 public:
  Layer();
  Layer(std::vector<std::vector<double>> w, std::vector<double> b);
  std::vector<double>push (std::vector<double> in);
};
/////////
//  Node
////////
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
//////////
//  Layer
/////////
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
std::vector<double> Layer::push (std::vector<double> in) {
  std::vector<double> output;
  output.resize(nodes.size());
  for(unsigned int i = 0; i < nodes.size(); i++) {
    output[i] = nodes[i].push(in);
  }
  return output;
}

///////
int main() {
  std::vector<double> in = {1,1,1}, out;
  Layer l1({{1, 2, 3}, {1, 2, 3}}, {2, 1});
  Layer l2({{2, 2}}, {5});
  out = l1.push(in);
  out = l2.push(out);
  for (unsigned int i = 0; i < out.size(); i++) {
    std::cout << out[i] << ' ' << std::endl;
  }
}
