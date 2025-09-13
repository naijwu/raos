#include "platform.h"

#ifdef ARDUINO
#include <Arduino.h>
#else
  static uint32_t millis() { return 0; } 
  static void delay(uint32_t ms) { }
#endif

static RAOS_TimeNowMsFn time_fn = nullptr;
static RAOS_SleepMsFn   sleep_fn = nullptr;

// for manual override (no need)
void raos_platform_set_time_now(RAOS_TimeNowMsFn fn) {
  time_fn = fn;
}
void raos_platform_set_sleep(RAOS_SleepMsFn fn) {
  sleep_fn = fn;
}

// fallbacks otherwise 
uint32_t raos_time_now_ms(void) {
  if (time_fn) {
    return time_fn();
  }
  return millis();
}

void raos_sleep_ms(uint32_t ms) {
  if (sleep_fn) {
    sleep_fn(ms);
  } else {
    delay(ms);
  }
}