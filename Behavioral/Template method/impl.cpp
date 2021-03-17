#include "impl.hpp"

#include <iostream>

// Character

void Character::combat_turn()
{
  if (must_flee()) {
    flee();
    return;
  }

  if (!ready()) {
    get_ready();
    return;
  }

  combat_action();
}

void Character::flee() const { std::cout << "flee\n"; }


// Swordman

bool SwordMan::must_flee() const { return health_ < 5; }
bool SwordMan::ready() const { return wielded_sword_; }
void SwordMan::get_ready() { wield(); }
void SwordMan::combat_action() { attack(); }

void SwordMan::wield() { wielded_sword_ = true; }
void SwordMan::attack() { wielded_sword_ = false; }


// Wizard

bool Wizard::must_flee() const { return health_ < 2 || mana_ == 0; }
bool Wizard::ready() const { return scroll_ready_; }
void Wizard::get_ready() { read_scroll(); }
void Wizard::combat_action() { cast_spell(); }

void Wizard::read_scroll() { scroll_ready_ = true; }
void Wizard::cast_spell() { scroll_ready_ = false; mana_ -= 10; }