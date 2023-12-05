#ifndef ARCNUM_H
#define ARCNUM_H

#include <core/window/window.h>

// ===============================================================================
// GAME:         | Used for storing game information
// ===============================================================================
typedef struct
{
	window* window;
} game;



// ===============================================================================
// GAME FUNCTIONS:

void game_main(void);
void game_loop(game game);
void game_cleanup(game* game);

// ===============================================================================

#endif // ARCNUM_H