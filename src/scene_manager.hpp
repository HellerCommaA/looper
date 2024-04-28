
#pragma once

#include <SDL2/SDL.h>

#include <memory>
#include <string>
#include <unordered_map>

#include "scene.hpp"

class SceneManager {
   public:
    void AddScene(const std::string &name, std::shared_ptr<Scene> scene);

    void SetActiveScene(const std::string &name);

    void Render(tcod::Context &, tcod::Console &);
    void Update(SDL_Event &, const float);

   private:
    std::shared_ptr<Scene> activeScene;

    std::unordered_map<std::string, std::shared_ptr<Scene>> map;
};
