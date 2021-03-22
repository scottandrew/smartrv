#include "button.h"
#include "label.h"
#include <iostream>
#include <string>

using namespace std;

shared_ptr<Button> Button::create(SharedObject parent) {
  return shared_ptr<Button>(new Button(parent->lvObjectPtr()));
}

void Button::registerClick(function<void(Object*)> handler) {
  Object::registerCallback(LV_EVENT_CLICKED, handler);
}

void Button::setString(std::string text) {
  label = Label::create(shared_from_this(), text);
}
