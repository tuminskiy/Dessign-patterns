#pragma once

#include <string>

class PetVisitor;

class Pet
{
  std::string name_;

public:
  explicit Pet(const std::string& name);
  virtual ~Pet() = default;

  std::string name() const;

  virtual void accept(PetVisitor& v);
};

class Cat : public Pet
{
public:
  explicit Cat(const std::string& name);

  void accept(PetVisitor& v) override;
};


class Dog : public Pet
{
public:
  explicit Dog(const std::string& name);

  void accept(PetVisitor& v) override;
};


class PetVisitor
{
public:
  void visit(Pet& p);
  void visit(Cat& c);
  void visit(Dog& d);
};