
#pragma once

#include <libtcod/libtcod.hpp>

#include "scene_manager.hpp"

class App {
   public:
    static App &Instance() {
        static App instance;
        return instance;
    }

    void Run();
    // scene manager wrapper
    void SetActiveScene(const std::string &);

   private:
    App() {}

    void Setup();
    void MainLoop();
    void Render();
    void Update();

    // Copy constructor and assignment operator are deleted
    App(const App &) = delete;
    App &operator=(const App &) = delete;

   private:
    tcod::Context gContext;
    TCOD_ContextParams gContextParams;
    tcod::Tileset gTileset;
    tcod::Console gRootConsole;
    SceneManager gSceneManager;
    float deltaTime = 0.f;
};
