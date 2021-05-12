#pragma once

class LegacyRect
{
public:
  explicit LegacyRect(unsigned int width, unsigned int height);

  void display() const;

private:
  unsigned int width_;
  unsigned int height_;
};


class IDrawable
{
public:
  virtual ~IDrawable() = default;

  virtual void draw() const = 0;
};

class Rect : public IDrawable
{
public:
  explicit Rect(unsigned int width, unsigned int height);

  void draw() const override;

private:
  unsigned int width_;
  unsigned int height_;
};


template <class Displayable>
class DrawAdapter : public IDrawable
{
public:
  explicit DrawAdapter(const Displayable& obj)
    : obj_{ obj }
  { }

  void draw() const override { obj_.display(); }

private:
  const Displayable& obj_;
}