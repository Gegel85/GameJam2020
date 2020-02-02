//
// Created by Gegel85 on 22/12/2019.
//

#include "InGameMenu.hpp"
#include "../Game.hpp"

namespace DungeonIntern
{
	InGameMenu::InGameMenu(MenuMgr &menu, Game &game, Map &map, Rendering::Screen &screen) :
		_map(map),
		_game(game),
		_menu(menu),
		_screen(screen)
	{
	}

	void InGameMenu::render()
	{
		this->_map.update();
		this->_map.render();
	}

	void InGameMenu::switched(bool isActive)
	{
		if (!isActive)
			return;

		if (this->_soundThread.joinable())
			this->_soundThread.join();
		this->_game.resources.stopMusic();
		this->_game.resources.playSound("prepare");
		this->_soundThread = std::thread([this]{
			std::this_thread::sleep_for(std::chrono::seconds(45));
			this->_game.resources.playMusic("music");
		});
		this->_screen.setCameraCenter({0, 0});
	}

	void InGameMenu::handleEvent(const Input::Event &event)
	{
	}
}