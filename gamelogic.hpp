#pragma once

#include <SFML/Graphics.hpp>

namespace Engine
{
  class IGameLogic
  {
  public:
    virtual void init() = 0;
    virtual void update(sf::RenderWindow*) = 0; // Tmp until Camera is implemented
    virtual void render(sf::RenderTarget*) = 0;
  };
}

