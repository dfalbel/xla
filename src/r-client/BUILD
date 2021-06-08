package(default_visibility = ["//tensorflow:internal"])

load(
    "//tensorflow:tensorflow.bzl",
    "tf_cc_binary",
    "tf_cc_shared_object",
    "tf_cc_test",
    "if_with_tpu_support",
)
load(
    "//tensorflow/core/platform/default:build_config.bzl",
    "tf_additional_all_protos",
    "tf_proto_library",
    "tf_proto_library_cc",
    "tf_proto_library_py",
)
load(
    "//tensorflow/core/platform/default:cuda_build_defs.bzl",
    "if_cuda_is_configured",
)

exports_files(
    [
        "tf_version_script.lds",
        "tf_exported_symbols.lds",
    ],
)

tf_cc_shared_object(
    name = "librclient.so",
    linkopts = select({
        "//tensorflow:windows": [],
        "//tensorflow:macos": [
            "-Wl,-exported_symbols_list",  # This line must be directly followed by the exported_symbols.lds file
            "$(location //tensorflow/compiler/xla/r-client:tf_exported_symbols.lds)",
        ],
        "//conditions:default": [
            "-z defs",
            "-Wl,--version-script",  #  This line must be directly followed by the version_script.lds file
            "$(location //tensorflow/compiler/xla/r-client:tf_version_script.lds)",
        ],
    }),
    visibility = ["//visibility:public"],
    deps = [
        "r-client-impl",
        "//tensorflow/compiler/xla/r-client:tf_version_script.lds",
        "//tensorflow/compiler/xla/r-client:tf_exported_symbols.lds",
    ],
)

cc_library(
    name = "r-client-impl",
    visibility = ["//visibility:public"],
    srcs = [
        "r-client.cpp"
    ],
    hdrs = [
        "r-client.h"
    ],
    deps = [
        "//tensorflow/compiler/xla/client",
        "//tensorflow/compiler/xla/client:xla_builder",
    ],
    alwayslink = 1,
)
