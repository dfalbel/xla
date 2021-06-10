#include "tensorflow/compiler/xla/client/xla_builder.h"
#include "tensorflow/compiler/xla/pjrt/cpu_device.h"
#include "tensorflow/compiler/xla/pjrt/pjrt_client.h"
#include "tensorflow/compiler/xla/shape_util.h"

#include <memory>
#include <string>
#include <iostream>

void fun(const std::string& name) {
  std::cout << "Creating a builder" << std::endl;
  xla::XlaBuilder builder("hello_world");
  auto param_shape = xla::ShapeUtil::MakeShape(xla::PrimitiveType::F32, {1});
  auto x = xla::Parameter(&builder, 0, param_shape, "param_name");
  auto y = xla::Sin(x);
  auto computation = builder.Build().ValueOrDie();

  auto cpu_backend = xla::GetCpuClient(false).ValueOrDie();
  // compile graph based on shape
  auto compiled_computation = cpu_backend->Compile(computation, xla::CompileOptions());
  
  // define a host variable with above parameter shape
  auto host_input = {1.0, 2.0, 3.0};

  // place host variable on device and execute
  // cpu_backend->BufferFromHostBuffer(host_input.begin(), param_shape, xla::PjRtClient::HostBufferSemantics::kZeroCopy);
  //device_input = cpu_backend.buffer_from_pyval(host_input)

  //compiled_computation

  auto c = std::make_shared<xla::XlaBuilder>(name);
}