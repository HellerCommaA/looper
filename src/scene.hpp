
#pragma once

#include <SDL2/SDL.h>

#include <libtcod/libtcod.hpp>

class Scene {
   public:
    Scene() = default;
    virtual void Render(tcod::Context &, tcod::Console &) = 0;
    virtual void Update(SDL_Event &evt, const float delta) = 0;
};
