//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_DRAGONMAN_HPP
#define DUNGEONINTERN_DRAGONMAN_HPP


#include <memory>
#include "Player.hpp"
#include "../../../Input/Input.hpp"

namespace DungeonIntern
{
	class DragonMan : public Player {
	public:
		DragonMan(Rendering::Screen &screen, Map &map, float x, float y, Input &input, Resources &resources);
		virtual ~DragonMan() override = default;

		void onDeath() override;
	};
}


#endif //DUNGEONINTERN_GOBLIN_HPP
