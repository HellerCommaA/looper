
#include <SDL2/SDL.h>

#include <iostream>
#include <libtcod/libtcod.hpp>
#include <libtcod/timer.hpp>

#include "color.hpp"
#include "config.hpp"

static tcod::Context gContext;
static TCOD_ContextParams gContextParams;
static tcod::Tileset gTileset;
static tcod::Console gConsole;

static float deltaTime = 0.f;

void setup() {
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);

    gConsole = tcod::Console(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT);

    gTileset = tcod::load_tilesheet(Config::FONT_PATH, {32, 8}, tcod::CHARMAP_TCOD);

    gContextParams.tcod_version = TCOD_COMPILEDVERSION;
    gContextParams.renderer_type = TCOD_RENDERER_SDL2;
    gContextParams.tileset = gTileset.get();
    gContextParams.vsync = 0;
    gContextParams.sdl_window_flags = SDL_WINDOW_RESIZABLE;
    gContextParams.window_title = Config::WINDOW_TITLE.c_str();
    gContextParams.console = gConsole.get();

    gContext = tcod::Context(gContextParams);

    atexit(TCOD_quit);
}

void render() {
    tcod::print(gConsole, {0, 0}, "Hello world", Color::WHITE, std::nullopt);

    gContext.present(gConsole);
    gConsole.clear();
}

void update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                std::exit(EXIT_SUCCESS);
                break;
            case SDL_KEYDOWN:
                break;
            default:
                break;
        }
    }
}

void mainLoop() {
    static auto timer = tcod::Timer();
    deltaTime = timer.sync();

    render();

    update();
}

int main() {
    setup();

    while (true) mainLoop();
    return 0;
}
