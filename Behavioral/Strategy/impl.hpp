#pragma once

template <class T>
struct DeleteByOperator
{
  void operator() (T* data) const { delete data; }
};

template <class T, class DeletePolicy = DeleteByOperator<T>>
class SmartPtr
{
  T* data_;
  DeletePolicy delete_policy_;

public:
  SmartPtr(T* data)
    : data_(data)
    , delete_policy_() 
  { }

  explicit SmartPtr(T* data, const DeletePolicy& delete_policy)
    : data_(data)
    , delete_policy_(delete_policy)
  { }

  ~SmartPtr() { delete_policy_(data_); }
};