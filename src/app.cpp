
#include "app.hpp"

#include <SDL2/SDL.h>

#include <libtcod/libtcod.hpp>
#include <libtcod/timer.hpp>

#include "config.hpp"
#include "game.hpp"
#include "main_menu.hpp"

void App::Setup() {
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);

    gRootConsole = tcod::Console(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT);

    gTileset = tcod::load_tilesheet(Config::FONT_PATH, {32, 8}, tcod::CHARMAP_TCOD);

    gContextParams.tcod_version = TCOD_COMPILEDVERSION;
    gContextParams.renderer_type = TCOD_RENDERER_SDL2;
    gContextParams.tileset = gTileset.get();
    gContextParams.vsync = 0;
    gContextParams.sdl_window_flags = SDL_WINDOW_RESIZABLE;
    gContextParams.window_title = Config::WINDOW_TITLE.c_str();
    gContextParams.console = gRootConsole.get();

    gContext = tcod::Context(gContextParams);

    atexit(TCOD_quit);

    gSceneManager.AddScene("main_menu", std::make_shared<MainMenu>());
    gSceneManager.AddScene("game", std::make_shared<Game>());
    gSceneManager.SetActiveScene("main_menu");
}
void App::MainLoop() {
    static auto timer = tcod::Timer();
    deltaTime = timer.sync();

    Render();

    Update();
}

void App::Render() {
    gSceneManager.Render(gContext, gRootConsole);
    gContext.present(gRootConsole);
    gRootConsole.clear();
}
void App::Update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                std::exit(EXIT_SUCCESS);
                break;
            default:
                gSceneManager.Update(event, deltaTime);
                break;
        }
    }
}

void App::SetActiveScene(const std::string &name) { gSceneManager.SetActiveScene(name); }

void App::Run() {
    Setup();
    while (true) MainLoop();
}
