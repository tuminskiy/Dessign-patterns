#include "impl.hpp"

#include <iostream>
#include <memory>

LegacyRect::LegacyRect(unsigned int width, unsigned int height)
  : width_{ width }
  , height_{ height_ }
{ }

void LegacyRect::display() const
{
  std::cout << "Width: " << width_ << "\nHeight: " << height_ << std::endl;
}


Rect::Rect(unsigned int width, unsigned int height)
  : width_{ width }
  , height_{ height_ }
{ }

void Rect::draw() const
{
  std::cout << "Width: " << width_ << "\nHeight: " << height_ << std::endl;
}


void draw(const std::shared_ptr<IDrawable> obj)
{
  if (obj)
    obj->draw();
}

int main()
{
  auto rect = std::make_shared<Rect>(100, 42);
  auto legacy_rect = std::make_shared<LegacyRect>(42, 100);

  auto adapter = std::make_shared<DrawAdapter<LegacyRect>>(*legacy_rect);

  draw(rect);
  draw(adapter);
}