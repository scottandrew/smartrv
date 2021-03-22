#include "lvgl/lvgl.h"
#include "image.h"

std::shared_ptr<Image> Image::create(std::string path, SharedObject parent) {
  //std::shared_ptr<Image> image = shared_ptr(new Image(parent->lvObjectPtr)::make_shared<Image>(parent->lvObjectPtr());
  auto image = std::shared_ptr<Image>(new Image(parent->lvObjectPtr()));

  lv_img_set_src(image->lvObjectPtr(), path.c_str() );

 return image;
}