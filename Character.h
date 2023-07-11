#pragma once

namespace Characters {
	class Character {
	protected:
		int _max_hp;
		int _current_hp;
		int _damage;
		std::string _name;
		bool _is_die{ false };

	public:
		Character(int max_hp, int damage, const std::string& name) :
			_max_hp(max_hp), _current_hp(max_hp), _damage(damage), _name(name) {		}

		int get_damage() const {
			return _damage;
		}

		int get_hp() const {
			return _current_hp;
		}

		const std::string& get_name() const {
			return _name;
		}

		bool is_die() const {
			return _is_die;
		}

		void take_damage(int damage) {
			if (_is_die) return;

			auto hp = _current_hp - damage;
			_current_hp = hp < 0 ? 0 : hp;

			if (_current_hp > 0) return;
			on_character_die();
		}

		virtual void on_character_die() {
			_is_die = true;
		}
	};
}
