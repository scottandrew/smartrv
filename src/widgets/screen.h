#ifndef SCREEN_H
#define SCREEN_H

#include "lvgl/lvgl.h"
#include "widget.h"

class Screen: public Object {

  protected:
      Screen();

  public:
    static std::shared_ptr<Screen> create();

  public:
    void load();

    static std::shared_ptr<Screen> current();
};

typedef std::shared_ptr<Screen> SharedScreen;

#endif