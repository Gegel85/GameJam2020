//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_BLOCK_HPP
#define DUNGEONINTERN_BLOCK_HPP


#include "../Position.hpp"

namespace DungeonIntern
{
	class Block {
	private:
		const unsigned _maxHealth;
		unsigned _health;
		bool _needRepair = false;
		Position<unsigned> pos;

	public:
		Block(unsigned maxHealth, Orientation orientation);

		virtual void onWalk(class Character &) = 0;
		virtual void use(class Player &) = 0;
		virtual void loot(class Enemy &) = 0;
		virtual void repair(class Player &) = 0;
	};
}


#endif //DUNGEONINTERN_BLOCK_HPP
