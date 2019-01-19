#include "./game.hpp"
#include "./utils.hpp"

using namespace Engine;

const int TPS = 128;

Game::Game(std::string name, int width, int height)
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  _window = new sf::RenderWindow(sf::VideoMode(width, height), name, sf::Style::Default, settings);
  sf::View view(sf::Vector2f(0, 0), sf::Vector2f(width, height));
  _window->setView(view);
  _window->setFramerateLimit(300);
}

Game::~Game()
{
  delete _window;
}

void Game::Start(IGameLogic* logic)
{
  logic->setWindow(_window);
  logic->init();
  int last_time = Engine::getTime();
  float lag = 0.0f;

  while (_window->isOpen())
  {
    sf::Event event;

    while(_window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        _window->close();
      else if (event.type == sf::Event::Resized) {
        sf::View view = _window->getView();
        view.setSize(event.size.width, event.size.height);
        _window->setView(view);
      }
    }

    int current = Engine::getTime();
    int elapsed = current - last_time;
    last_time = current;

    float ticks = elapsed * TPS / 1000.0f + lag;
    int ticks_rounded = (int)ticks;
    lag = ticks - ticks_rounded;

    for (int i = 0; i < ticks_rounded; i++) {
      logic->update();
    }

    _window->clear(sf::Color::Blue);
    logic->render();
    _window->display();
  }
}

