/**
 * @file lv_theme_basic.h
 *
 */

#ifndef SMARTRV_THEME_H
#define SMARTRV_THEME_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl/src/core/lv_theme.h"
#include "lvgl/src/core/lv_obj.h"

#if USE_SMARTRV_THEME

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the theme
 * @param disp pointer to display to attach the theme
 * @return a pointer to reference this theme later
 */
lv_theme_t * smart_rv_theme_default_init(lv_disp_t* disp);

/**********************
 *      MACROS
 **********************/

#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*SMARTRV_THEME_H*/
