
#pragma once

#include "scene.hpp"

class Game : public Scene {
   public:
    virtual ~Game() {}
    virtual void Render(tcod::Context &, tcod::Console &) override;
    virtual void Update(SDL_Event &evt, const float delta) override;
};
