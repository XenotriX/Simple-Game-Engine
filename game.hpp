#pragma once

#include <SFML/Graphics.hpp>
#include "./gamelogic.hpp"

namespace Engine
{
  class Game
  {
  public:
    Game(std::string, int, int);
    ~Game();
    void Start(IGameLogic*);
  private:
    sf::RenderWindow* _window;
  };
}
