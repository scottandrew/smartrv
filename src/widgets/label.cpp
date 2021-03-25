#include "lvgl/lvgl.h"
#include "label.h"

using namespace std;

 std::shared_ptr<Label> Label::create(SharedObject parent) {
  return shared_ptr<Label>(new Label(parent->lvObjectPtr()));
 }

std::shared_ptr<Label> Label::create(SharedObject parent, std::string text) {
  auto label = Label::create(parent);

  label->setString(text);
  return label;
}

void Label::setString(string text) {
  setText(text.c_str());
}

string Label::getString() {
  const char* text = getText();

  return text ? string(text) : string();
}

void Label::setText(const char* text) {
  lv_label_set_text(lvObjectPtr(), text);
}

const char* Label::getText() {
  return lv_label_get_text(lvObjectPtr());
}

void Label::setFont(lv_font_t* font) {
  Object::setFont(LV_PART_MAIN, LV_STATE_DEFAULT, font);
}

void Label::setTextAlignment(lv_text_align_t alignment) {
  return Object::setTextAlignment(LV_PART_MAIN, LV_STATE_DEFAULT, alignment);
}