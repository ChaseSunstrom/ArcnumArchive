#ifndef CORE_RENDERER_H
#define CORE_RENDERER_H

#include "layer_stack.h"


// ==============================================================================
// RENDERER:     | Used for rendering and storing rendering data
// ==============================================================================
typedef struct
{
	double delta_time;
	double fixed_delta_time;
	double last_frame_time;
	double tick_time;
	layer_stack* layer_stack;
} renderer;

//===============================================================================
// RENDERER FUNCTIONS:     

renderer* renderer_new(void);
void      renderer_free(renderer* renderer);
void      renderer_render(renderer* renderer);
void      renderer_set_tick_time(renderer* renderer);
void      renderer_set_delta_time(renderer* renderer);
void      renderer_set_fixed_delta_time(renderer* renderer);
void      renderer_set_last_frame_time(renderer* renderer);
double    calculate_tick_time(void);
double    calculate_delta_time(void);
double    calculate_fixed_delta_time(void);
double    calculate_last_frame_time(void);

//===============================================================================
#endif //CORE_RENDERER_H