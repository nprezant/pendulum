#ifndef PENDULUM_BUTTONDATA_H
#define PENDULUM_BUTTONDATA_H

#include <string>

#include "Hotkey.h"
#include "Slider.h"

template<typename ButtonId>
struct ButtonData
{
    ButtonId id;
    std::string name;
    std::vector<Hotkey> hotkeys;

    ButtonData(
        ButtonId id,
        const std::string& name,
        const std::vector<Hotkey>& hotkeys)
        : id(id)
        , name(name)
        , hotkeys(hotkeys)
    {
    }

    ButtonData(ButtonId id, const std::string& name, const Hotkey& hotkey)
        : ButtonData(id, name, std::vector<Hotkey>{ hotkey })
    {
    }

    ButtonData(ButtonId id, const std::string& name)
        : ButtonData(id, name, std::vector<Hotkey>())
    {
    }
};

template<typename SliderId>
struct SliderData
{
    SliderId id;
    std::string label;
    Slider::Range range;
    double initialValue;

    SliderData(
        SliderId id,
        const std::string& label,
        const Slider::Range& range,
        double initialValue)
        : id(id)
        , label(label)
        , range(range)
        , initialValue(initialValue)
    {
    }

    SliderData(
        SliderId id,
        const std::string& label,
        const Slider::Range& range,
        int initialValue)
        : id(id)
        , label(label)
        , range(range)
        , initialValue(static_cast<double>(initialValue))
    {
    }
};

#endif // PENDULUM_BUTTONDATA_H
