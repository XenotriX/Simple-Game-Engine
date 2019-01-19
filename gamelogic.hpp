#pragma once

#include <SFML/Graphics.hpp>

namespace Engine
{
  class IGameLogic
  {
  public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    void setWindow(sf::RenderWindow* window)
    {
      this->window = window;
    }
  protected:
    sf::RenderWindow* window;
  };
}

