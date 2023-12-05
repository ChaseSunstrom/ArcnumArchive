#include "arcnum.h"

// ===============================================================================
// GAME FUNCTIONS:

void game_main(void)
{
	game game =
	{
		.window = window_new()
	};

	game_loop(game);
}

void game_loop(game game)
{
	while (window_is_running(game.window))
	{
		window_update(game.window);
	}
}

// ===============================================================================