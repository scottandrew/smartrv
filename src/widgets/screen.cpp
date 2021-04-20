#include "screen.h"
#include "lvgl/lvgl.h"
#include "widget.h"
#include <memory>

using namespace std;

shared_ptr<Screen> Screen::create() { return shared_ptr<Screen>(new Screen()); }

Screen::Screen() : Object(lv_obj_create(NULL)) {}

void Screen::load() { lv_scr_load(lvObjectPtr()); }

shared_ptr<Screen> Screen::current() {
  try {
    lv_obj_t *screen = lv_scr_act();
    // lets attempt to get the weak ptr.

    if (screen->user_data != NULL) {
      shared_ptr<Object> object =
          ((Object *)screen->user_data)->shared_from_this();

      return static_pointer_cast<Screen>(object);
    }
  } catch (...) {
  }

  return shared_ptr<Screen>();
}