#pragma once

#include <vector>
#include <optional>

class Viewport
{
public:

};

struct ConsoleCreationParameters
{
    std::optional<size_t> client_size;
    int character_width{ 10 };
    int character_height{ 14 };
    int width{ 20 };
    int height{ 30 };
    bool fullscreen{ false };
    bool create_default_view_and_buffer{ true };
};

class Console
{
public:

    Console() = default;

    Console(const ConsoleCreationParameters& ccp)
    {
        // single buffer and viewport created here
        // linked together and added to appropriate collections
        // image textures generated
        // grid size calculated depending on whether we want 
        // fullscreen mode
    }

    std::vector<Viewport> viewports;

    size_t charSize, gridSize;
};
