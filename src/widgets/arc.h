//
//  arc.hpp
//  Hello_LVGL
//
//  Created by Scott Andrew on 3/2/21.
//

#ifndef arc_hpp
#define arc_hpp

#include "object.h"

class Arc: public Object {
protected:
    Arc(lv_obj_t* parent): Object(lv_arc_create(parent, NULL)){};

public:
    static std::shared_ptr<Arc> create(SharedObject parent);

    void setEndAngle(uint16_t angle);
    void setBackgroundAngle(uint16_t startAngle, uint16_t endAngle);

    void setValue(int16_t value);
    void setAdjustable(bool adjustable);

    // style helpers..
    void setBackgroundArcWidth(lv_coord_t width);
    void setIndicatorWidth(lv_coord_t width);

    void setBackgroundArcColor(Color& color);
    void setIndicatorColor(Color& color);
};

typedef std::shared_ptr<Arc> SharedArc;

#endif /* arc_hpp */
