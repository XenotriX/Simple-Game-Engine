#include "./utils.hpp"

int Engine::getTime()
{
  auto time = std::chrono::system_clock::now().time_since_epoch();
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
  return ms.count();
}

float Engine::rand()
{
  return (float)std::rand()/RAND_MAX;
}
