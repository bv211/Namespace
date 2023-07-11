#pragma once
#include "CharacterController.h"
#include "CharacterAttack.h"
#include "Character.h"

namespace Characters {
	namespace Controllers {
		class EnemyController : public CharacterController {
		public:
			EnemyController(Character* character, CharacterAttack* attack)
				: CharacterController(character, attack) {}

			virtual void select_action() override {
				std::cout << "Какой-то выбор ENEMY" << std::endl;
			}
		};
	}
}
