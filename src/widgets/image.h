#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "object.h"

class Image : public Object {
public:
  static std::shared_ptr<Image> create(std::string path, SharedObject parent);


protected:
  Image(lv_obj_t* parent):Object(lv_img_create(parent, NULL)){};
};

typedef std::shared_ptr<Image> SharedImage;

#endif