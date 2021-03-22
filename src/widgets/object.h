#ifndef OBJECT_H
#define OBJECT_H

#include <functional>
#include <map>
#include <vector>
#include <memory>

#include "lvgl/lvgl.h"
#include "../theme/color.h"

class Object: public std::enable_shared_from_this<Object> {
  private:;
    std::map<int, std::function<void(Object*)>> events;
    lv_obj_t* object;

  protected:
    void registerCallback(lv_event_t message, std::function<void(Object*)> callback) {
      events[message] = callback;
    }

    Object(lv_obj_t* anObject);
    virtual ~Object();

  public:

    lv_obj_t* lvObjectPtr() { return object; }

    void setSize(lv_coord_t width, lv_coord_t height);
    void setWidth(lv_coord_t width);

    void align(Object* to, lv_align_t alignment, lv_coord_t xOffset, lv_coord_t yOffset);

    // local style helpers.
    void setBackgroundColor(uint8_t part, lv_state_t state, Color color);
    void setLineColor(uint8_t part, lv_state_t state, Color color);
    void setLineWidth(uint8_t part, lv_state_t state, lv_coord_t width);
    void setBorderColor(uint8_t part, lv_state_t state, Color color);

    void setPaddingAllSides(uint8_t part, lv_state_t state, lv_coord_t padding);
    void setPaddingLeft(uint8_t part, lv_state_t state, lv_coord_t padding);
    void setPaddingRight(uint8_t part, lv_state_t state, lv_coord_t padding);
    void setPaddingTop(uint8_t part, lv_state_t state, lv_coord_t padding);
    void setPaddingBottom(uint8_t part, lv_state_t state, lv_coord_t padding);
    void setBorderWidth(uint8_t part, lv_state_t state, lv_coord_t padding);
    void setFont(uint8_t part, lv_state_t state, lv_font_t* font);
    void setTextAlignment(uint8_t part, lv_state_t state, lv_text_align_t alignment);
};

typedef std::shared_ptr<Object> SharedObject;

#endif