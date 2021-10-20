#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <SDL2/SDL.h>
#include <optional>
#include <vector>

#include "Button.h"
#include "Icon.h"

class Playback
{
public:
    Playback(const SDL_Rect& rect, SDL_Renderer* renderer);

    void setRect(const SDL_Rect& rect);

    void render();

    // Button identifiers
    enum class ButtonId : int
    {
        PlayPause = 1,
        Restart,
        FrameBack,
        FrameForward,
    };

    // Handles event. The button pressed is returned, if any are pressed
    void handleEvent(SDL_Event& e);

private:
    // Computes button positions
    void computePositions();

    // TODO combine with `ButtonData` from Menu.h
    struct ButtonData
    {
        ButtonId id;
        std::string name;

        ButtonData(ButtonId id, const std::string& name)
            : id(id)
            , name(name)
        {
        }
    };

    SDL_Rect rect_;
    Rectangle background_;
    std::vector<Icon> buttons_;
    SDL_Renderer* renderer_;
};

#endif // PLAYBACK_H