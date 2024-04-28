
#include "game.hpp"

#include "app.hpp"
#include "color.hpp"
#include "config.hpp"

void Game::Render(tcod::Context &ctx, tcod::Console &root) {
    tcod::print(root, {0, 0}, "Hello game", Color::WHITE, std::nullopt);
}

void Game::Update(SDL_Event &evt, const float delta) {
    switch (evt.type) {
        case SDL_KEYDOWN:
            switch (evt.key.keysym.sym) {
                case SDLK_w:
                    App::Instance().SetActiveScene(Config::Scene::MainMenu);
                default:
                    break;
            }
        default:
            break;
    }
}
