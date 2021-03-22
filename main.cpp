
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" \
                            issue*/
#include "lvgl/lvgl.h"
#include "src/simulator/simulation.h"
#include "lvgl/examples/lv_examples.h"
#include "src/app.h"

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int main(int argc, char **argv)
{
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  /*Initialize LVGL*/
  lv_init();

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init();

  App app;

  app.run();
//  lv_example_calendar_1();
//  lv_example_btnmatrix_2();
//  lv_example_table_2();
//  lv_example_chart_6();
//  lv_example_colorwheel_1();
//  lv_example_meter_2();
//  lv_example_tabview_1();
//  lv_example_scroll_3();
//  lv_example_list_1();
//  lv_example_msgbox_1();
//  lv_example_dropdown_2();
//  lv_example_win_1();

//  lv_demo_keypad_encoder();
//  lv_demo_stress();
  // lv_example_list_1();
 // lv_example_flex_5();

  while(1) {
      /* Periodically call the lv_task handler.
       * It could be done in a timer interrupt or an OS task too.*/
      lv_timer_handler();
      usleep(5 * 1000);
  }

  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/



// /**
//  * A task to measure the elapsed time for LVGL
//  * @param data unused
//  * @return never return
//  */
// static int tick_thread(void *data) {
//     (void)data;

//     while(1) {
//         SDL_Delay(5);   /*Sleep for 5 millisecond*/
//         lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
//     }

//     return 0;
// }