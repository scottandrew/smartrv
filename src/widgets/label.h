#ifndef LABEL_H
#define LABEL_H

#include <string>
#include "object.h"

class Label : public Object
{
public:
  static std::shared_ptr<Label> create(SharedObject parent);
  static std::shared_ptr<Label> create(SharedObject parent, std::string text);

  Label(lv_obj_t* parent):Object(lv_label_create(parent)){};

  void setString(std::string text);
  std::string getString();

  void setText(const char* text);
  const char* getText();

  void setFont(lv_font_t* font);

  void setTextAlignment(lv_text_align_t alignment);
};

typedef std::shared_ptr<Label> SharedLabel;

#endif