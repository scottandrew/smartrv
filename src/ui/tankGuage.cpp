#include "tankGuage.h"
//#include "flexLayout.h"

#define TANKGALLONS 40.0
#define GUAGE_SIZE 220

std::shared_ptr<TankGuage> TankGuage::create(SharedObject parent, std::string title) {
  return SharedTankGuage(new TankGuage(parent->lvObjectPtr(), title));
}

TankGuage::TankGuage(lv_obj_t *parent, std::string title) : Arc(parent), title(title) {}

void TankGuage::layout() {
//   lv_obj_set_auto_realign(lvObjectPtr(), true);
//  setFit(LV_FIT_TIGHT);

  //setLayout(FlexLayout::RowCenter());
  lv_obj_clear_flag(lvObjectPtr(), LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE);
  setAdjustable(false);
  setBackgroundArcWidth(8);
  setIndicatorWidth(12);
  setPaddingAllSides(LV_PART_INDICATOR, LV_STATE_DEFAULT, -1);
  setBorderWidth(LV_PART_INDICATOR, LV_STATE_DEFAULT, 0);
  setSize(GUAGE_SIZE, GUAGE_SIZE);
  setPaddingAllSides(LV_PART_MAIN, LV_STATE_DEFAULT, 4);
  removeStyle(LV_PART_KNOB, LV_STATE_ANY);

  percentageLabel = Label::create(shared_from_this());
  percentageLabel->setFont((lv_font_t*)&lv_font_montserrat_36);
  percentageLabel->setTextAlignment(LV_TEXT_ALIGN_CENTER);
  percentageLabel->align(LV_ALIGN_CENTER, 0, -25);
// percentageLabel->setWidth(250);
  gallonsRemaingLevel = Label::create(shared_from_this());
  gallonsRemaingLevel->setFont((lv_font_t*)&lv_font_montserrat_14);
  gallonsRemaingLevel->setTextAlignment(LV_TEXT_ALIGN_CENTER);
   gallonsRemaingLevel->setPaddingTop(LV_PART_MAIN, LV_STATE_DEFAULT, 0);
   // gallonsRemaingLevel->alignTo(percentageLabel, LV_ALIGN_BOTTOM_LEFT, 0, 15);
// gallonsRemaingLevel->setWidth(250);
  gallonsRemaingLevel->align(LV_ALIGN_CENTER, 0, 12);

  tanKTypeLabel = Label::create(shared_from_this());
  tanKTypeLabel->setFont((lv_font_t*)&lv_font_montserrat_18);
  tanKTypeLabel->setTextAlignment(LV_TEXT_ALIGN_CENTER);
  tanKTypeLabel->align(LV_ALIGN_BOTTOM_MID, 0, -20);
  tanKTypeLabel->setText(title.c_str());
  //tanKTypeLabel->setPaddingAllSides(LV, LV_STATE_DEFAULT, 0);

  // lv_obj_set_auto_realign(percentageLabel->lvObjectPtr(), true);
  // lv_obj_set_auto_realign(gallonsRemaingLevel->lvObjectPtr(), true);
  // lv_obj_set_auto_realign(tanKTypeLabel->lvObjectPtr(), true);

  // tanKTypeLabel->setText(title.c_str());
  setValue(0);

  // setBackgroundColor(LV_CONT_PART_MAIN, LV_STATE_DEFAULT, Color::Red());
}

void TankGuage::setValue(int16_t value) {
  char percent[5] = "";
  char remaining[60] = "";
  sprintf(percent, "%d%%", value);

  int gallonsRemaining = floor(TANKGALLONS * ((100 - value) / 100.0));
  sprintf(remaining, "%d gal\nremaining", gallonsRemaining);


  percentageLabel->setText(percent);

  // percentageLabel1->setText(percent);
   gallonsRemaingLevel->setText(remaining);

  // depending on the level we change colors.
  if (value < warningLevel) {
    setBackgroundArcColor(goodBackground);
    setIndicatorColor(goodIndicator);
  } else if (value < crticalLevel) {
    setBackgroundArcColor(warningBackground);
    setIndicatorColor(warningIndicator);
  } else {
    setBackgroundArcColor(criticalBackground);
    setIndicatorColor(criticalIndicator);
  }

    Arc::setValue(value);
}
