#ifndef BAR_H
#define BAR_H

#include "object.h"

class Bar: public Object {
protected:
  Bar(lv_obj_t* parent): Object(lv_bar_create(parent)){};

public:
  static std::shared_ptr<Bar> create(SharedObject parent);

  void setValue(int16_t value, lv_anim_enable_t animate);
  int16_t getValue();

  void setStartValue(int16_t value, lv_anim_enable_t animate);
  int16_t getStartValue();

  void setRange(int16_t min, int16_t max);
  int16_t getMinValue();
  int16_t getMaxValue();

  // void setType(lv_bar_type_t type);
  // lv_bar_type_t getBarType();
};

#endif
