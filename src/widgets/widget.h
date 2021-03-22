#ifndef WIDGET_H
#define WIDGET_H

#include "object.h"

class Widget: public Object {
public:
  static std::shared_ptr<Widget> create(SharedObject parent);


protected:
  Widget(lv_obj_t* parent):Object(lv_obj_create(parent, NULL)){};
};

typedef std::shared_ptr<Widget> SharedWidget;

#endif