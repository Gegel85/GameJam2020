//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_MAP_HPP
#define DUNGEONINTERN_MAP_HPP


#include <memory>
#include <vector>
#include "Objects/Block.hpp"
#include "Entities/Entity.hpp"

namespace DungeonIntern
{
	class Game;

	class Map {
	private:
		std::vector<std::unique_ptr<Entity>> _entities;
		std::vector<std::unique_ptr<Block>> _objects;
		Game &_game;

	public:
		Map(Game &);

		void loadMap();
		void update();
		void render();
		void reset();
		const std::vector<std::unique_ptr<Entity>> & getEntities();
		const std::vector<std::unique_ptr<Block>> & getObjects();
	};
}


#endif //DUNGEONINTERN_MAP_HPP
