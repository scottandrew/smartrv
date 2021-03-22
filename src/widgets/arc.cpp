//
//  arc.cpp
//  Hello_LVGL
//
//  Created by Scott Andrew on 3/2/21.
//
#include "lvgl/lvgl.h"
#include "arc.h"

std::shared_ptr<Arc> Arc::create(SharedObject parent) {
    return std::shared_ptr<Arc>(new Arc(parent->lvObjectPtr()));
}

void Arc::setBackgroundAngle(uint16_t startAngle, uint16_t endAngle) {
    lv_arc_set_bg_angles(lvObjectPtr(), startAngle, endAngle);
}

void Arc::setEndAngle(uint16_t angle) {
    lv_arc_set_end_angle(lvObjectPtr(), angle);
}

void Arc::setValue(int16_t value) {
    lv_arc_set_value(lvObjectPtr(), value);
}

// Local style helpers..
    // style helpers..
void Arc::setBackgroundArcWidth(lv_coord_t width) {
    lv_obj_set_style_arc_width(lvObjectPtr(), LV_PART_MAIN, LV_STATE_DEFAULT, width);
}

void Arc::setIndicatorWidth(lv_coord_t width) {
    lv_obj_set_style_arc_width(lvObjectPtr(), LV_PART_INDICATOR, LV_STATE_DEFAULT, width);
}

void Arc::setBackgroundArcColor(Color& color) {
    lv_obj_set_style_arc_color(lvObjectPtr(), LV_PART_MAIN, LV_STATE_DEFAULT, color.lvColor());
}

void Arc::setIndicatorColor(Color& color) {
    lv_obj_set_style_arc_color(lvObjectPtr(), LV_PART_INDICATOR, LV_STATE_DEFAULT, color.lvColor());
}

void Arc::setAdjustable(bool adjustable) {
  //  lv_arc_set_adjustable(lvObjectPtr(), adjustable);
}