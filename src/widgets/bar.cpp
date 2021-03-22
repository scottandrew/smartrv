#include "bar.h"

using namespace std;

shared_ptr<Bar> Bar::create(SharedObject parent) {
  return shared_ptr<Bar>(new Bar(parent->lvObjectPtr()));
}

void Bar::setValue(int16_t value, lv_anim_enable_t animate = LV_ANIM_OFF) {
  lv_bar_set_value(lvObjectPtr(), value, animate);
}

int16_t Bar::getValue() {
  return lv_bar_get_value(lvObjectPtr());
}

void Bar::setStartValue(int16_t value, lv_anim_enable_t animate = LV_ANIM_OFF) {
  lv_bar_set_start_value(lvObjectPtr(), value, animate);
}

int16_t Bar::getStartValue() {
  return lv_bar_get_start_value(lvObjectPtr());
}

void Bar::setRange(int16_t min, int16_t max) {
  return lv_bar_set_range(lvObjectPtr(), min, max);
}

int16_t Bar::getMinValue() {
  return lv_bar_get_min_value(lvObjectPtr());
}

int16_t Bar::getMaxValue() {
  return lv_bar_get_max_value(lvObjectPtr());
}

void Bar::setType(lv_bar_type_t type) {
  return lv_bar_set_type(lvObjectPtr(), type);
}

lv_bar_type_t Bar::getBarType() {
  return lv_bar_get_type(lvObjectPtr());
}
