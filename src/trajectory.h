#pragma once
#include "raos_types.h"
#include "raos_errors.h"

typedef struct {
  RAOS_Action actions[RAOS_MAX_ACTIONS];
  uint16_t count;
} RAOS_Trajectory;

// options
typedef struct {
  raos_scalar max_blend; // corner blend (seconds)
  uint8_t cartesian_blends; // flag to allow pose blending
} RAOS_TrajPlanOpts;

typedef struct {
  RAOS_TrajState state;
  uint16_t current_index;
  uint32_t started_ms;
} RAOS_TrajStatus;

// adds valid timing to passed actions
RAOS_Result raos_plan_trajectory(
  RAOS_Handle* h,
  const RAOS_Trajectory* in_traj,
  const RAOS_TrajPlanOpts* opt,
  RAOS_Trajectory* out_traj
);

// updates status to start, gets raos ready to step
RAOS_Result raos_start_trajectory(RAOS_Handle* h, const RAOS_Trajectory* traj);

RAOS_Result raos_stop_trajectory(RAOS_Handle* h);
RAOS_Result raos_pause_trajectory(RAOS_Handle* h);
RAOS_Result raos_resume_trajectory(RAOS_Handle* h);

// advances tick
RAOS_Result raos_step(RAOS_Handle* h);

// gets status (via RAOS_TrajStatus)
RAOS_Result raos_status(const RAOS_Handle* h);