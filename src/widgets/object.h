#ifndef OBJECT_H
#define OBJECT_H

#include <functional>
#include <map>
#include <memory>
#include <vector>

#include "../theme/color.h"
#include "lvgl/lvgl.h"

class Object : public std::enable_shared_from_this<Object> {
private:
  ;
  std::map<int, std::function<void(Object *)>> events;
  lv_obj_t *object;

protected:
  void registerCallback(lv_event_code_t message,
                        std::function<void(Object *)> callback) {
    events[message] = callback;
  }

  Object(lv_obj_t *anObject);
  virtual ~Object();

public:
  lv_obj_t *lvObjectPtr() { return object; }

  void setSize(lv_coord_t width, lv_coord_t height);
  void setWidth(lv_coord_t width);

  lv_coord_t getWidth();

  void align(lv_align_t alignment, lv_coord_t xOffset, lv_coord_t yOffset);
  void alignTo(std::shared_ptr<Object> to, lv_align_t align, lv_coord_t xOffset,
               lv_coord_t yOffset);

  void removeStyle(lv_part_t part, lv_state_t state, lv_style_t *style = NULL);

  // local style helpers.
  void setBackgroundColor(lv_part_t part, lv_state_t state, Color color);
  void setLineColor(lv_part_t part, lv_state_t state, Color color);
  void setLineWidth(lv_part_t part, lv_state_t state, lv_coord_t width);
  void setBorderColor(lv_part_t part, lv_state_t state, Color color);

  void setPaddingAllSides(lv_part_t part, lv_state_t state, lv_coord_t padding);
  void setPaddingLeft(lv_part_t part, lv_state_t state, lv_coord_t padding);
  void setPaddingRight(lv_part_t part, lv_state_t state, lv_coord_t padding);
  void setPaddingTop(lv_part_t part, lv_state_t state, lv_coord_t padding);
  void setPaddingBottom(lv_part_t part, lv_state_t state, lv_coord_t padding);
  void setBorderWidth(lv_part_t part, lv_state_t state, lv_coord_t padding);
  void setFont(lv_part_t part, lv_state_t state, lv_font_t *font);
  void setTextAlignment(lv_part_t part, lv_state_t state,
                        lv_text_align_t alignment);

  // flex support
  void setFlexFlow(lv_flex_flow_t flow);
  void setFlexPlace(lv_flex_place_t main_place, lv_flex_place_t cross_place,
                    lv_flex_place_t track_cross_place);
};

typedef std::shared_ptr<Object> SharedObject;

#endif