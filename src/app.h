#ifndef APP_H
#define APP_H

#include "ui/tankGuage.h"
#include "widgets/screen.h"
#include "widgets/slider.h"

class App {
private:
  SharedScreen screen;
  SharedSlider slider;

  SharedTankGuage freshWaterGuage;
  SharedTankGuage grayWaterGuage;
  SharedTankGuage blackWaterGuage;
  SharedTankGuage lpTankGuage;

  SharedWidget guageContainer;

  bool on;

public:
  App();
  ~App();

  void run();
};

#endif