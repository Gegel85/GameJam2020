//
// Created by andgel on 31/01/2020
//

#include "../../../Game.hpp"
#include "Lonk.hpp"

namespace DungeonIntern
{
	Lonk::Lonk(Rendering::Screen &screen, Map &map, Game &game, float x, float y) :
		AIController({screen, "assets/entities/lonk.json", map}, game, 6, x, y, 64, 64, 100)
	{
		this->_game.resources.playSound("hero3");
	}

	void Lonk::onDeath()
	{
		AI::AIController::onDeath();
		this->_game.resources.playSound("deathS");
	}
}