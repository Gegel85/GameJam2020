//
// Created by andgel on 31/01/2020
//

#include "Map.hpp"
#include "Entities/Characters/Players/Player.hpp"
#include "Entities/Characters/Players/DragonMan.hpp"
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
		this->_entities.erase(std::remove_if(this->_entities.begin(), this->_entities.end(), [](std::unique_ptr<Entity> &entity){
			return entity->destroyed();
		}), this->_entities.end());
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
		this->_entities.emplace_back(new Player({*this->_game.resources.screen, "assets/entities/test.json", *this}, 5, 50, 100, 32, 32, 100, *this->_game.state.settings.inputs[0]));
		this->_entities.emplace_back(new DragonMan({*this->_game.resources.screen, "assets/entities/test.json", *this}, 25, 25, 64, 64, 100, *this->_game.state.settings.inputs[1]));
	}

	const std::vector<std::unique_ptr<Entity>> & Map::getEntities()
	{
		return (this->_entities);
	}

	const std::vector<std::unique_ptr<Block>> & Map::getObjects()
	{
		return (this->_objects);
	}
}