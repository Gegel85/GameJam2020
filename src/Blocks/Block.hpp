//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_BLOCK_HPP
#define DUNGEONINTERN_BLOCK_HPP


#include "../Position.hpp"
#include "../Size.hpp"


namespace DungeonIntern
{
	//! @brief Every position of the map where you can move is a block. If there is nothing on this tile, use an AirBlock (it will do nothing).
	class Block {
	protected:
		//! @brief The max health of the block (amount of damage to take before it breaks)
		const unsigned _maxHealth;
		unsigned _health;
		//! @brief For example, a chest will need repair if he is empty or broken (same cost for the player).
		bool _needRepair = false;
		//! @brief Position of the block. 0, 0 is the top left corner of the screen.
		Position<unsigned> _pos;
		//! @brief Size of the entity.
		Size<unsigned> _size;

	public:
		Block(unsigned maxHealth, Orientation orientation, unsigned sx, unsigned sy);
		virtual ~Block() = default;

		//! @brief Called when a character walk on the block. This should push back the character if he isn't allowed to walk on this block.
		virtual void onWalk(class Character &) = 0;
		//! @brief For example, using a ladder will make the player go up and ask him to press keys.
		virtual void use(class Player &) = 0;
		//! @brief When an enemy use the block (loot for a chest, fall into a trap...)
		virtual void loot(class Enemy &) = 0;
		//! @brief For example, filling the chest or repairing it if it is broke.
		virtual void repair(Player &) = 0;
		virtual void render() = 0;
		const Position<unsigned> & getPosition();
		const Size<unsigned> & getSize();
	};
}


#endif //DUNGEONINTERN_BLOCK_HPP
