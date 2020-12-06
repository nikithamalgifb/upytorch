// See: pytorch/torch/csrc/autograd/generated/python_torch_functions.cpp

#include <iostream>
#include <torch/script.h>

#include "upt_arg_parser.h"
#include "upt_variable.h"

using namespace torch;
using namespace torch::autograd;

// pytorch/torch/csrc/autograd/utils/wrap_outputs.h
inline mp_obj_t wrap(at::Tensor tensor) {
  return UPTVariable_Wrap(Variable(std::move(tensor)));
}

extern "C" {

mp_obj_t UPTVariable_ones(size_t n_args, const mp_obj_t* args, mp_map_t* kw_args) {
  static PythonArgParser parser({
    "ones(IntArrayRef size)",
  });
  ParsedArgs<1> parsed_args;
  auto _r = parser.parse(nullptr, n_args, args, kw_args, parsed_args);
  auto dispatch_ones = [](IntArrayRef size) -> Tensor {
    // pybind11::gil_scoped_release no_gil;
    return torch::ones(size);
  };
  return wrap(dispatch_ones(_r.intlist(0)));
}

mp_obj_t UPTVariable_add(size_t n_args, const mp_obj_t* args, mp_map_t* kw_args) {
  static PythonArgParser parser({
    "add(Tensor input, Scalar alpha, Tensor other, *, Tensor out=None)|deprecated",
    "add(Tensor input, Tensor other, *, Scalar alpha=1, Tensor out=None)",
  });

  ParsedArgs<4> parsed_args;
  auto _r = parser.parse(nullptr, n_args, args, kw_args, parsed_args);
  switch (_r.idx) {
    case 0: {
      if (_r.isNone(3)) {
        // [deprecated] aten::add.Tensor(Tensor self, Tensor other, *, Scalar alpha=1) -> Tensor

        auto dispatch_add = [](const Tensor & self, Scalar alpha, const Tensor & other) -> Tensor {
          // pybind11::gil_scoped_release no_gil;
          return self.add(other, alpha);
        };
        return wrap(dispatch_add(_r.tensor(0), _r.scalar(1), _r.tensor(2)));
      } else {
        // [deprecated] aten::add.out(Tensor self, Tensor other, *, Scalar alpha=1, Tensor(a!) out) -> Tensor(a!)

        auto dispatch_add_out = [](const Tensor & self, Scalar alpha, const Tensor & other, Tensor out) -> Tensor {
          // pybind11::gil_scoped_release no_gil;
          return at::add_out(out, self, other, alpha);
        };
        return wrap(dispatch_add_out(_r.tensor(0), _r.scalar(1), _r.tensor(2), _r.tensor(3)));
      }
    }
    case 1: {
      if (_r.isNone(3)) {
        // aten::add.Tensor(Tensor self, Tensor other, *, Scalar alpha=1) -> Tensor

        auto dispatch_add = [](const Tensor & self, const Tensor & other, Scalar alpha) -> Tensor {
          // pybind11::gil_scoped_release no_gil;
          return self.add(other, alpha);
        };
        return wrap(dispatch_add(_r.tensor(0), _r.tensor(1), _r.scalar(2)));
      } else {
        // aten::add.out(Tensor self, Tensor other, *, Scalar alpha=1, Tensor(a!) out) -> Tensor(a!)

        auto dispatch_add_out = [](Tensor out, const Tensor & self, const Tensor & other, Scalar alpha) -> Tensor {
          // pybind11::gil_scoped_release no_gil;
          return at::add_out(out, self, other, alpha);
        };
        return wrap(dispatch_add_out(_r.tensor(3), _r.tensor(0), _r.tensor(1), _r.scalar(2)));
      }
    }
  }
  return mp_const_none;
}

}  // extern "C"
