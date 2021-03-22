#ifndef APP_H
#define APP_H

#include "widgets/screen.h"
#include "ui/tankGuage.h"
#include "widgets/slider.h"

class App {
  private:
    SharedScreen screen;
    SharedTankGuage tankGuage;
    SharedSlider slider;


    bool on;

  public:
      App();
    ~App();

    void run();
};

#endif