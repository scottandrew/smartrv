#include "lvgl/lvgl.h"
#include "slider.h"

std::shared_ptr<Slider> Slider::create(SharedObject parent) {
  return std::shared_ptr<Slider>(new Slider(parent->lvObjectPtr()));
}

void Slider::registerValueChanged(std::function<void(Object*)> handler) {
  Object::registerCallback(LV_EVENT_VALUE_CHANGED, handler);
}

int16_t Slider::getValue() {
  return lv_slider_get_value(lvObjectPtr());
}