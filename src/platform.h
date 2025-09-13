#pragma once
#include <stdint.h>

typedef uint32_t  (*RAOS_TimeNowMsFn)(void);
typedef void      (*RAOS_SleepMsFn)(uint32_t);

// callbacks for platform-specific functions
typedef void      (*RAOS_WriteJointsFn)(const float* q, uint8_t dof);
typedef void      (*RAOS_ReadJointsFn)(float* q_out, uint8_t dof);
typedef void      (*RAOS_ToolActionFn)(uint8_t code, uint32_t param);

void raos_platform_set_time_now(RAOS_TimeNowMsFn fn);
void raos_platform_set_sleep(RAOS_SleepMsFn fn);
void raos_platform_set_io(RAOS_WriteJointsFn wfn, RAOS_ReadJointsFn rfn, RAOS_ToolActionFn tfn);

uint32_t  raos_time_now_ms(void);
void      raos_sleep_ms(uint32_t ms);