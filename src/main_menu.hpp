
#pragma once

#include "scene.hpp"

class MainMenu : public Scene {
   public:
    virtual ~MainMenu() {}
    virtual void Render(tcod::Context &, tcod::Console &) override;
    virtual void Update(SDL_Event &evt, const float delta) override;
};
