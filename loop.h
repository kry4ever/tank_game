//#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>

int startLoop(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY* display, bool (*draw)());
