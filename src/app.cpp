#include "app.h"
#include "widgets/button.h"
#include "widgets/screen.h"
#include "widgets/image.h"
#include "widgets/arc.h"
#include <iostream>
#include "theme/color.h"

using namespace std;

LV_IMG_DECLARE(png_decoder_test);

App::App() : on(false) {}

App::~App() {}

void App::run() {
  screen = Screen::create();
  screen->load();

    tankGuage = TankGuage::create(screen, "Fresh Water");
    tankGuage->layout();

    shared_ptr<Slider> slider = Slider::create(screen);
    slider->setSize(200, 20);
    slider->align(screen.get(), LV_ALIGN_CENTER, 0, 0);

    weak_ptr<TankGuage> weak_guage = weak_ptr<TankGuage>(tankGuage);

    slider->registerValueChanged([weak_guage](Object* object) -> void {
      Slider* slider = static_cast<Slider *>(object);
      auto guage = weak_guage.lock();

      if (guage && slider) {
        guage->setValue(slider->getValue());
      }

    });

    this->slider = slider;

//   auto aWidget = Button::create(screen);
// //
//   aWidget->setSize(100, 50);
//   aWidget->align(NULL, LV_ALIGN_CENTER, 0, 0);
//   aWidget->setString("jehllo world");
// //
//  image = Image::create("images/battery.png", screen);
//  image->align(NULL, LV_ALIGN_CENTER, 50, 50);
//
 //  button = aWidget;

  // weak_ptr<GPIO> weakGPIO = redLed;

//  aWidget->registerClick([&state = this->on, weakGPIO]() -> void {
//    bool newState = !state;
//    weakGPIO.lock()->write(newState ? 1 : 0);
//    state = newState;
//  });
}
