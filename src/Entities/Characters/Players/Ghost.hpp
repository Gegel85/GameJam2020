//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_GHOST_HPP
#define DUNGEONINTERN_GHOST_HPP


#include <memory>
#include "Player.hpp"
#include "../../../Input/Input.hpp"

namespace DungeonIntern
{
	class Ghost : public Player {

	public:
		Ghost(Rendering::Screen &screen, Map &map, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input, Resources &resources);
		virtual ~Ghost() override = default;
	};
}


#endif //DUNGEONINTERN_GHOST_HPP