#ifndef BUTTON_H
#define BUTTON_H

#include "object.h"
#include "label.h"

class string;

class Button: public Object {
public:
  static std::shared_ptr<Button> create(SharedObject parent);

  void registerClick(std::function<void(Object*)> handler);
  void setString(std::string text);



protected:
  Button(lv_obj_t* parent):Object(lv_btn_create(parent)){};
  SharedLabel label;
};

typedef std::shared_ptr<Button> SharedButton;

#endif