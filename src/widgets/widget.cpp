#include "lvgl/lvgl.h"
#include "widget.h"
#include "object.h"

using namespace std;

std::shared_ptr<Widget> Widget::create(SharedObject parent) {
  // shared_ptr<Object> widget =  (new Widget(parent->lvObjectPtr()))->shared_from_this();
  // return static_pointer_cast<Widget>(widget);

  return std::shared_ptr<Widget>(new Widget(parent->lvObjectPtr()));
}
