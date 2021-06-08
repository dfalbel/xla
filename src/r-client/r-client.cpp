#include "tensorflow/compiler/xla/client/xla_builder.h"
#include <memory>
#include <string>
#include <iostream>

void fun(const std::string& name) {
  std::cout << "Creating a builder" << std::endl;
  auto c = std::make_shared<xla::XlaBuilder>(name);
}