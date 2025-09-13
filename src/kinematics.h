#pragma once
#include "raos_types.h"
#include "raos_errors.h"

typedef struct {
  uint8_t dof;
  raos_scalar q[RAOS_MAX_DOF];
} RAOS_JointVec;

// options
typedef struct {
  uint16_t max_iters; // default 100
  raos_scalar tol_pos; // metres
  raos_scalar tol_rot; // radians
  raos_scalar step; 
  uint8_t prefer_elbow_up;
} RAOS_IKOptions;

typedef struct {
  uint8_t count;
  RAOS_JointVec sols[RAOS_MAX_IK_SOLUTIONS];
} RAOS_IKSolutions;

RAOS_Result raos_calculate_forward(
  const RAOS_Handle* h,
  const raos_scalar* q,
  RAOS_Pose* out_pose
);

RAOS_Result raos_calculate_forward_chain(
  const RAOS_Handle* h,
  const raos_scalar* q,
  RAOS_Mat4* out_frames,
  uint8_t* inout_len
);

RAOS_Result raos_calculate_inverse(
  const RAOS_Handle* h,
  const RAOS_Pose* target,
  const RAOS_IKOptions* opt,
  RAOS_IKSolutions* out_sols
)
