#include <memory>
#include <string>
#include <cpp11.hpp>

void fun(const std::string& name);

[[cpp11::register]]
void fun2(const std::string& name) {
  fun(name);
}
