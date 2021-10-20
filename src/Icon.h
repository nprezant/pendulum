#ifndef ICON_H
#define ICON_H

#include "Rectangle.h"
#include "Texture.h"
#include <SDL2/SDL.h>
#include <string>

// Similar to text, but a small image
class Icon
{
public:
    Icon(
        const SDL_Rect& rect,
        const SDL_Color& bgColor,
        const std::string& iconPath,
        SDL_Renderer* renderer);

    void setRect(const SDL_Rect& rect);
    void setIcon(const std::string& filePath);

    void darkenBackgroundNextRender();

    void render();

private:
    SDL_Rect rect_;
    Rectangle background_;
    Texture iconTexture_;
    std::string iconPath_;
    bool darkenBackgroundNextRender_;
    SDL_Renderer* renderer_;
};

#endif // ICON_H