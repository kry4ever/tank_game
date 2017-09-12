#include "framework.h"
#include "global.h"

bool init(ALLEGRO_DISPLAY **display) {
  //int width = 640;
  //int height = 480;

  if (!al_init()) {
    fprintf(stderr, "failed to initialize allegro!\n");
    return false;
  }

  if (!al_init_image_addon()) {
    fprintf(stderr, "failed to al_init_image_addon!\n");
    return false;
  }

  *display = al_create_display(width, height);
  if (!(*display)) {
    fprintf(stderr, "failed to al_create_display!\n");
    return false;
  }

  if (!al_init_font_addon()) {
	  fprintf(stderr, "failed to al_init_font_addon!\n");
	  return false;
  }

  al_init_ttf_addon();

  al_clear_to_color(al_map_rgb(0, 0, 0));
  al_flip_display();
  return true;
}
