
#include "main_menu.hpp"

#include <iostream>

#include "app.hpp"
#include "color.hpp"
#include "config.hpp"

void MainMenu::Render(tcod::Context &ctx, tcod::Console &root) {
    tcod::print(root, {0, 0}, "Hello menu", Color::WHITE, std::nullopt);
}

void MainMenu::Update(SDL_Event &evt, const float delta) {
    switch (evt.type) {
        case SDL_KEYDOWN:
            switch (evt.key.keysym.sym) {
                case SDLK_w:
                    std::cout << "W pressed" << std::endl;
                    App::Instance().SetActiveScene(Config::Scene::Game);
                default:
                    break;
            }
        default:
            break;
    }
}
