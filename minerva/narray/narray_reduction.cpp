#include "narray/narray.h"
#include "op/shared_op.h"
#include <glog/logging.h>

using namespace std;

namespace minerva {

// Lazy reductions
NArray NArray::Sum(int dim) {
  return Sum(Scale{dim});
}

NArray NArray::Sum(const Scale& dims) {
  auto size = Size();
  for (auto i : dims) {
    size[i] = 1;
  }
  ReductionOp* reduction_op = new ReductionOp();
  reduction_op->closure.type = ReductionType::kSum;
  reduction_op->closure.dims_to_reduce = dims;
  return NArray::ComputeOne({*this}, size, reduction_op);
}

NArray NArray::Max(int dim) {
  return Max(Scale{dim});
}

NArray NArray::Max(const Scale& dims) {
  auto size = Size();
  for (auto i : dims) {
    size[i] = 1;
  }
  ReductionOp* reduction_op = new ReductionOp();
  reduction_op->closure.type = ReductionType::kMax;
  reduction_op->closure.dims_to_reduce = dims;
  return NArray::ComputeOne({*this}, size, reduction_op);
}

NArray NArray::MaxIndex(int dim) {
  auto size = Size();
  size[dim] = 1;
  MaxIndexOp* op = new MaxIndexOp();
  op->closure.dim = dim;
  return NArray::ComputeOne({*this}, size, op);
}

// Non-lazy reductions
float NArray::Sum() {
  // TODO
  CHECK(false) << "not implemented";
  return 0;
}

float NArray::Max() {
  // TODO
  CHECK(false) << "not implemented";
  return 0;
}

int NArray::CountZero() {
  int* value = reinterpret_cast<int*>(Get());
  int size = Size().Prod();
  int counter = 0;
  for (int i = 0; i < size; ++i) {
    if (!value[i]) {
      ++counter;
    }
  }
  return counter;
}

} // end of namespace minerva

