#include <glfw3.h>

#include "game/user/window.h"
#include "game/game.h"

int main()
{
    GLFWwindow* window = create_window();
    game_main(window);

    return 0;
}