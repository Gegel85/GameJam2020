//
// Created by andgel on 31/01/2020
//

#include "Map.hpp"
#include "Entities/Characters/Players/Player.hpp"
#include "Game.hpp"


namespace DungeonIntern
{
	Map::Map(DungeonIntern::Game &game)
		: _game(game)
	{}

	void Map::update()
	{
		for (auto &ent : this->_entities)
			ent->update();
	}

	void Map::render()
	{
		for (auto &obj : this->_objects)
			obj->render();
		for (auto &ent : this->_entities)
			ent->render();
		this->_game.resources.screen->renderEntities();
	}

	void Map::reset()
	{
		this->_objects.clear();
	}

	void Map::loadMap()
	{
		logger.debug("Loading the map.");
		this->_entities.emplace_back(new Player({*this->_game.resources.screen, "assets/entities/test.json", *this}, 50, 50, 100, 100, *this->_game.state.settings.inputs[0]));
		this->_entities.emplace_back(new Player({*this->_game.resources.screen, "assets/entities/test.json", *this}, 50, 25, 25, 100, *this->_game.state.settings.inputs[1]));
	}
}