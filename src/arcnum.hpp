#ifndef ARCNUM_HPP
#define ARCNUM_HPP

#include <core/events/event.hpp>

void on_start();
void on_update();
bool on_event(std::shared_ptr<ac::event> event);

void register_functions();

#endif