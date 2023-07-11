#pragma once
#include "Character.h"

namespace Characters {
	class CharacterAttack {
		Character* character;

	public:
		CharacterAttack(Character* character) :
			character(character) {}

		void inflict_damage(Character* character) {
			auto damage = character->get_damage();
			character->take_damage(damage);
		}
	};
}
