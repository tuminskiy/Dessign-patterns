#pragma once

#include <memory>

class Operation
{
public:
  ~Operation() = default;
  
  virtual double operator() (double lhs, double rhs) = 0;
};

using operation_ptr = std::shared_ptr<Operation>;


class Calc
{
  operation_ptr op_;

public:
  void set_operation(operation_ptr op);

  double exec(double lhs, double rhs);
};


class OperationPlus : public Operation
{
public:
  double operator() (double lhs, double rhs) override;
};

class OperationMinus : public Operation
{
public:
  double operator() (double lhs, double rhs) override;
};

class OperationMultiply : public Operation
{
public:
  double operator() (double lhs, double rhs) override;
};

class OperationDivide : public Operation
{
public:
  double operator() (double lhs, double rhs) override;
};