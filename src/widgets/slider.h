#ifndef __SLIDER_H
#define __SLIDER_H

#include "object.h"

class Slider: public Object {
  protected:
    Slider(lv_obj_t* parent): Object(lv_slider_create(parent)){};

public:
    static std::shared_ptr<Slider> create(SharedObject parent);
    void registerValueChanged(std::function<void(Object*)> handler);

    int16_t getValue();
};

typedef std::shared_ptr<Slider> SharedSlider;

#endif