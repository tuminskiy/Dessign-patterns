#include "impl.hpp"

void Calc::set_operation(operation_ptr op) { op_ = op; }

double Calc::exec(double lhs, double rhs)
{
  return op_ ? (*op_)(lhs, rhs) : 0.;
}


double OperationPlus::operator() (double lhs, double rhs) { return lhs + rhs; }

double OperationMinus::operator() (double lhs, double rhs) { return lhs - rhs; }

double OperationMultiply::operator() (double lhs, double rhs) { return lhs * rhs; }

double OperationDivide::operator() (double lhs, double rhs) { return lhs / rhs; }