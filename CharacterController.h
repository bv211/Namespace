#pragma once
#include "CharacterAttack.h"
#include "Character.h"
#include <conio.h>

namespace Characters {
	namespace Controllers {
		class CharacterController {
		public:
			Character* character;
			CharacterAttack* attack;

			CharacterController(Character* character, CharacterAttack* attack)
				: character(character), attack(attack) {}

			virtual void select_action() {
				std::cout << "Какой-то выбор PLAYER" << std::endl;
			}
		};
	}
}
