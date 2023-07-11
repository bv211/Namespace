#pragma once
#include "CharacterAttack.h"
#include "CharacterAttack.h"
#include "Character.h"
#include "CharacterController.h"
#include "Character.h"
#include "EnemyController.h"

using namespace Characters;
using namespace Characters::Controllers;
using namespace std;

namespace Core {
	class Game {
		CharacterController* _player_1;
		CharacterController* _player_2;

	public:
		Game(CharacterController* player_1, CharacterController* player_2) :
			_player_1(player_1), _player_2(player_2) {}

		void start_game() {
			while (true) {
				_player_1->select_action();
				inflict_damage(_player_1->attack, _player_2->character);

				print_info(_player_2->character);
				if (check_live_character(_player_2->character)) break;

				_player_2->select_action();
				inflict_damage(_player_2->attack, _player_1->character);

				print_info(_player_1->character);
				if (check_live_character(_player_2->character)) break;
			}
		}

	private:
		void print_info(Character* character) {
			cout << "Left hp: " << character->get_hp() << endl << endl;
		}

		void inflict_damage(CharacterAttack* attack, Character* character_dest) {
			cout << "Inflict damage to " << character_dest->get_name() << endl;
			attack->inflict_damage(character_dest);
		}

		bool check_live_character(Character* character) {
			return character->is_die();
		}
	};
}
