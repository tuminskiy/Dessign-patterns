#pragma once

class Character
{
public:
  ~Character() = default;

  void combat_turn();

protected:
  int health_;

  virtual bool must_flee() const = 0;
  virtual bool ready() const = 0;
  virtual void get_ready() = 0;
  virtual void combat_action() = 0;

  virtual void flee() const;
};


class SwordMan : public Character
{
protected:
  bool wielded_sword_ = false;

  bool must_flee() const override;
  bool ready() const override;
  void get_ready() override;
  void combat_action() override;

  virtual void wield();
  virtual void attack();
};


class Wizard : public Character
{
protected:
  int mana_ = 100;
  bool scroll_ready_ = false;

  bool must_flee() const override;
  bool ready() const override;
  void get_ready() override;
  void combat_action() override;

  virtual void read_scroll();
  virtual void cast_spell();
};