#ifndef __TANKGUAGE_H
#define __TANKGUAGE_H

#include "../widgets/arc.h"
#include "../widgets/label.h"
#include "../theme/color.h"

class TankGuage: public Arc {
  private:
    SharedLabel percentageLabel;
    SharedLabel percentageLabel1;
    SharedLabel gallonsRemaingLevel;
    SharedLabel tanKTypeLabel;

    Color goodBackground = Color(37, 74, 39);
    Color goodIndicator = Color(128, 255, 134);
    Color warningBackground = Color(111, 113, 0);
    Color warningIndicator = Color(252, 255, 1);
    Color criticalBackground = Color(101, 0, 0);
    Color criticalIndicator = Color(219, 0, 1);

    int crticalLevel = 75;
    int warningLevel = 50;

    std::string title;

  protected:
    TankGuage(lv_obj_t* parent, std::string title);

  public:
    static std::shared_ptr<TankGuage> create(SharedObject pt, std::string title);

    void layout();

    void setValue(int16_t value);
};

typedef std::shared_ptr<TankGuage> SharedTankGuage;

#endif