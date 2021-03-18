#include "impl.hpp"

#include <iostream>
#include <string>

void custom_deleter(std::string* data)
{
  std::clog << "Call custom deleter for string: " << *data << "\n";
  delete data;
}

int main()
{
  SmartPtr ptr = new int(5);

  SmartPtr ptr(new std::string("data"), custom_deleter);

  // Compiler error:
  // SmartPtr ptr(new int(5), custom_deleter);

  return 0;
}