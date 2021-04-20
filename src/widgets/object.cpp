#include "object.h"
#include <iostream>
#include "lvgl/lvgl.h"

using namespace std;

Object::Object(lv_obj_t *anObject) {
  object = anObject;
  object->user_data = this;

  auto callback = [](lv_event_t *event) -> void {
    try {
      Object *eventObject = (Object *)event->target->user_data;

      if (event->code == LV_EVENT_DELETE) {
        event->target = NULL;
        return;
      }

      eventObject->events.at(event->code)(eventObject);
    } catch (...) {
    }
  };

  lv_obj_add_event_cb(object, callback, LV_EVENT_ALL, this);
}

Object::~Object() { lv_obj_del(object); }

void Object::removeStyle(lv_part_t part, lv_state_t state, lv_style_t *style) {
  lv_obj_remove_style(object, style,  part | state);
}

void Object::setSize(lv_coord_t width, lv_coord_t height) {
  lv_obj_set_size(object, width, height);
}

void Object::setWidth(lv_coord_t width) { lv_obj_set_width(object, width); }

void Object::align(lv_align_t alignment, lv_coord_t xOffset,
                   lv_coord_t yOffset) {
  lv_obj_align(object, alignment, xOffset, yOffset);
}

void Object::alignTo(SharedObject to, lv_align_t align, lv_coord_t xOffset,
                     lv_coord_t yOffset) {
  lv_obj_align_to(object, to->lvObjectPtr(), align, xOffset, yOffset);
}
void Object::setBackgroundColor(lv_part_t part, lv_state_t state, Color color) {
  lv_obj_set_style_bg_color(object, color.lvColor(), part | state);
}

void Object::setLineColor(lv_part_t part, lv_state_t state, Color color) {
  lv_obj_set_style_line_color(object,  color.lvColor(), part | state);
}

void Object::setBorderColor(lv_part_t part, lv_state_t state, Color color) {
  lv_obj_set_style_border_color(object, color.lvColor(), part | state);
}

void Object::setLineWidth(lv_part_t part, lv_state_t state, lv_coord_t width) {
  lv_obj_set_style_line_width(object, width, part |state);
}

void Object::setPaddingAllSides(lv_part_t part, lv_state_t state,
                                lv_coord_t padding) {
  lv_obj_set_style_pad_all(object, padding, part | state);
}

void Object::setPaddingLeft(lv_part_t part, lv_state_t state,
                            lv_coord_t padding) {
  lv_obj_set_style_pad_left(object, padding, part | state);
}

void Object::setPaddingRight(lv_part_t part, lv_state_t state,
                             lv_coord_t padding) {
  lv_obj_set_style_pad_right(object, padding, part | state);
}

void Object::setPaddingTop(lv_part_t part, lv_state_t state, lv_coord_t padding) {
  lv_obj_set_style_pad_top(object, padding, part | state);
}

void Object::setPaddingBottom(lv_part_t part, lv_state_t state,
                              lv_coord_t padding) {
  lv_obj_set_style_pad_bottom(object, padding, part | state);
}

void Object::setBorderWidth(lv_part_t part, lv_state_t state, lv_coord_t width) {
  lv_obj_set_style_border_width(object, width,part | state);
}

void Object::setFont(lv_part_t part, lv_state_t state, lv_font_t *font) {
  lv_obj_set_style_text_font(object, font, part | state);
}

void Object::setTextAlignment(lv_part_t part, lv_state_t state,
                              lv_text_align_t alignment) {
  lv_obj_set_style_text_align(object, alignment, part | state);
}

lv_coord_t Object::getWidth() { return lv_obj_get_width(object); }

// flex support
void Object::setFlexFlow(lv_flex_flow_t flow) {
  return lv_obj_set_flex_flow(object, flow);
}

void Object::setFlexPlace(lv_flex_place_t main_place,
                          lv_flex_place_t cross_place,
                          lv_flex_place_t track_cross_place) {
  lv_obj_set_flex_place(object, main_place, cross_place, track_cross_place);
}