#ifndef __COLOR_H
#define __COLOR_H


class Color {
private:
  lv_color_t color;

public:
  static Color Red() { return Color(lv_color_red()); }
  static Color Green() { return Color(lv_color_green()); }

  Color(lv_color_t lvColor):color(lvColor) {};
  Color(uint8_t red, uint8_t green, uint8_t blue):color(lv_color_make(red, green, blue)){};
  Color(uint32_t hex):color(lv_color_hex(hex)){};

  lv_color_t& lvColor() { return color; };
};

#endif