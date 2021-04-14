#include "impl.hpp"

#include <iostream>
#include <vector>
#include <memory>


Pet::Pet(const std::string& name) : name_(name) { }

std::string Pet::name() const { return name_; }

void Pet::accept(PetVisitor& v) { v.visit(*this); }



Cat::Cat(const std::string& name) : Pet(name) { }

void Cat::accept(PetVisitor& v) { v.visit(*this); }


Dog::Dog(const std::string& name) : Pet(name) { }

void Dog::accept(PetVisitor& v) { v.visit(*this); }



void PetVisitor::visit(Pet& p) { std::cout << p.name() << ": *make sound*\n"; }

void PetVisitor::visit(Cat& c) { std::cout << c.name() << ": Meow!\n"; }

void PetVisitor::visit(Dog& d) { std::cout << d.name() << ": Bark!\n"; }


int main()
{
  std::vector<std::shared_ptr<Pet>> pets;
  pets.reserve(3);

  pets.push_back(std::make_shared<Cat>("Barsik"));
  pets.push_back(std::make_shared<Pet>("Entity"));
  pets.push_back(std::make_shared<Dog>("Muhtar"));

  PetVisitor visitor;

  for (auto pet : pets) {
    pet->accept(visitor);
  }

  return 0;
}