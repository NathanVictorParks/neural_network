#ifndef NETWORK_H
#define NETWORK_H
#include "layer.h"
#include <random>

class Network: public Layer {
 private:
  std::vector<Layer> layers;
 public:
  Network();
}

#endif
