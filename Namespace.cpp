#include <iostream>
#include "CharacterAttack.h"
#include "CharacterAttack.h"
#include "Character.h"
#include "CharacterController.h"
#include "Character.h"
#include "EnemyController.h"
#include "Game.h"

using namespace Characters;
using namespace Characters::Controllers;
using namespace Core;

CharacterController* create_player() {
	auto* character = new Character(12, 2, "vasya");
	auto* attack = new CharacterAttack(character);
	auto* player = new CharacterController(character, attack);

	return player;
}

CharacterController* create_enemy() {
	auto* character = new Character(10, 4, "pupkin");
	auto* attack = new CharacterAttack(character);
	auto* enemy = new EnemyController(character, attack);

	return enemy;
}

void delete_character(CharacterController* controller) {
	delete controller->attack;
	delete controller->character;
	delete controller;
}

int main() {
	setlocale(0, "");

	auto* player = create_player();
	auto* enemy = create_enemy();

	Game game(player, enemy);
	game.start_game();

	delete_character(player);
	delete_character(enemy);

	return 0;
}