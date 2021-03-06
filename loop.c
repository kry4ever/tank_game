#include "loop.h"

int startLoop(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY* display, bool (*draw)()){
  int FPS = 60;
  bool redraw = true;

  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  *timer = al_create_timer(1 / FPS);
  if(!(*timer)){
    fprintf(stderr, "failed to create timer!\n");
    return -1;
  }


  event_queue = al_create_event_queue();
  if(!event_queue) {
    fprintf(stderr, "failed to create event_queue!\n");
    al_destroy_display(display);
    al_destroy_timer(*timer);
    return -1;
  }

  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(*timer));

  al_start_timer(*timer);
  while(1){
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    if(ev.type == ALLEGRO_EVENT_TIMER) {
      redraw = true;
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
      puts("close");
      break;
    }

    if(redraw && al_is_event_queue_empty(event_queue)) {
      redraw = false;
      draw();
    }
  }

  //  al_destroy_timer(timer);
  //al_destroy_display(display);
    al_destroy_event_queue(event_queue);

  return 0;
}
