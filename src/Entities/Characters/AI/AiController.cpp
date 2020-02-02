//
// Created by anonymus-raccoon on 2/1/20.
//

#include "AiController.hpp"
#include "AStarNode.hpp"
#include "../../../Blocks/Block.hpp"
#include "../../../Map.hpp"
#include "../../../Blocks/Objects/Chest.hpp"

namespace DungeonIntern::AI
{
	AIController::AIController(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Orientation orientation) :
		Character(cfg, maxSpeed, x, y, sx, sy, maxHealth, orientation)
	{
	}

	std::vector<sf::Vector2u> &AIController::_findPath()
	{
		uNode target(10, 15);

		uNode current(this->_pos.x, this->_pos.y);
		std::vector<uNode> openList = {current};
		std::vector<uNode> closedList = {};

		std::vector<uNode> neighbors;

		while (!openList.empty() && std::find_if(openList.begin(), openList.end(), [&target](uNode &n) {return n.x == target.x && n.y == target.y;}) == openList.end()) {
			current = openList[0];
			openList.erase(openList.begin());
			closedList.push_back(current);

			neighbors.clear();
			neighbors.emplace_back(current.x -1, current.y);
			neighbors.emplace_back(current.x, current.y -1);
			neighbors.emplace_back(current.x + 1, current.y);
			neighbors.emplace_back(current.x, current.y + 1);
			for (auto &neighbor : neighbors) {
				if (!neighbor.isWalkable)
					continue;
				if (std::find_if(closedList.begin(), closedList.end(), [neighbor](uNode &n){return n.x == neighbor.x && n.y == neighbor.y;}) != closedList.end())
					continue;
				if (std::find_if(openList.begin(), openList.end(), [neighbor](uNode &n){return n.x == neighbor.x && n.y == neighbor.y;}) != openList.end())
					continue;
				neighbor.parent.reset(&current);
				neighbor.cost = current.cost + 1;
				neighbor.distanceToEnd = std::abs((int)neighbor.x - (int)target.x) + std::abs((int)neighbor.y - (int)target.y);
				openList.push_back(neighbor);
				std::sort(openList.begin(), openList.end(), [](uNode a, uNode b){return a.getFCost() < b.getFCost();});
			}
		}

//		if (std::find(openList.begin(), openList.end(), [target](uNode &n) {return n.x == target.x && n.y == target.y;}) == openList.end())
//			return {};
		//return closedList;
	}

	void AIController::update()
	{
		if (this->_path.empty())
			this->_path = this->_findPath();

		Character::update();
	}

	void AIController::onCollide(Entity &other)
	{
		Character::onCollide(other);
	}

	void AIController::onDeath()
	{

	}

	uNode AIController::findTarget()
	{
		const std::vector<std::unique_ptr<Block>> &blocks = this->_map.getObjects();

		for (auto &block : blocks) {
			if (dynamic_cast<Chest *>(&*block) != nullptr) {
				return DungeonIntern::AI::uNode(block->getPosition().x, block->getPosition().y);
			}
		}
		return DungeonIntern::AI::uNode(0, 0);
	}
}