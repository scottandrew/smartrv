#include "object.h"
#include <iostream>

using namespace std;

Object::Object(lv_obj_t *anObject) {
  object = anObject;

  auto callback = [](lv_obj_t *obj, lv_event_t event) -> void {
    try {
      auto data = lv_obj_get_event_dsc(obj, 0);
      Object *eventObject = (Object *)data->user_data;

      if (event == LV_EVENT_DELETE) {
        data->user_data = NULL;
        return;
      }
      eventObject->events.at(event)(eventObject);
    } catch (...) {
    }
  };

  lv_obj_add_event_cb(object, callback, this);
}

Object::~Object() { lv_obj_del(object); }

void Object::setSize(lv_coord_t width, lv_coord_t height) {
  lv_obj_set_size(object, width, height);
}

void Object::setWidth(lv_coord_t width) { lv_obj_set_width(object, width); }

void Object::align(Object *to, lv_align_t alignment, lv_coord_t xOffset,
                   lv_coord_t yOffset) {
  lv_obj_align(object, to ? to->object : NULL, alignment, xOffset, yOffset);
}

void Object::setBackgroundColor(uint8_t part, lv_state_t state, Color color) {
  lv_obj_set_style_bg_color(object, part, state, color.lvColor());
}

void Object::setLineColor(uint8_t part, lv_state_t state, Color color) {
  lv_obj_set_style_line_color(object, part, state, color.lvColor());
}

void Object::setBorderColor(uint8_t part, lv_state_t state, Color color) {
  lv_obj_set_style_border_color(object, part, state, color.lvColor());
}

void Object::setLineWidth(uint8_t part, lv_state_t state, lv_coord_t width) {
  lv_obj_set_style_line_width(object, part, state, width);
}

void Object::setPaddingAllSides(uint8_t part, lv_state_t state,
                                lv_coord_t padding) {
  lv_obj_set_style_pad_all(object, part, state, padding);
}

void Object::setPaddingLeft(uint8_t part, lv_state_t state,
                            lv_coord_t padding) {
  lv_obj_set_style_pad_left(object, part, state, padding);
}

void Object::setPaddingRight(uint8_t part, lv_state_t state,
                             lv_coord_t padding) {
  lv_obj_set_style_pad_right(object, part, state, padding);
}

void Object::setPaddingTop(uint8_t part, lv_state_t state, lv_coord_t padding) {
  lv_obj_set_style_pad_top(object, part, state, padding);
}

void Object::setPaddingBottom(uint8_t part, lv_state_t state,
                              lv_coord_t padding) {
  lv_obj_set_style_pad_bottom(object, part, state, padding);
}

void Object::setBorderWidth(uint8_t part, lv_state_t state, lv_coord_t width) {
  lv_obj_set_style_border_width(object, part, state, width);
}

void Object::setFont(uint8_t part, lv_state_t state, lv_font_t *font) {
  lv_obj_set_style_text_font(object, part, state, font);
}

void Object::setTextAlignment(uint8_t part, lv_state_t state, lv_text_align_t alignment) {
  lv_obj_set_style_text_align(object, part, state, alignment);
}
