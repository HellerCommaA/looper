
#include "scene_manager.hpp"

#include <iostream>

void SceneManager::AddScene(const std::string &name, std::shared_ptr<Scene> scene) { map[name] = scene; }

void SceneManager::SetActiveScene(const std::string &name) {
    activeScene = map[name];
    std::cout << "Swapping scene to " << name << std::endl;
}

void SceneManager::Render(tcod::Context &ctx, tcod::Console &root) { activeScene->Render(ctx, root); }

void SceneManager::Update(SDL_Event &evt, const float delta) { activeScene->Update(evt, delta); }
