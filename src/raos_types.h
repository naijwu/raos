#pragma once
#include <stddef.h>
#include <stdint.h>
#include "raos_config.h"

#if defined(RAOS_USE_DOUBLE)
  // by default, we'll be using float to save memory
  typedef double raos_scalar;
#else
  typedef float raos_scalar;
#endif

// Vector type
typedef struct {
  raos_scalar x;
  raos_scalar y;
  raos_scalar z;
} RAOS_Vec3;

// Unit quaternion to represent tool's orientation
typedef struct {
  raos_scalar w;
  raos_scalar x;
  raos_scalar y;
  raos_scalar z;
} RAOS_Quat;

// 4x4 column-major (array of arrays of column cells) matrix
typedef struct {
  raos_scalar m[16];
} RAOS_Mat4; 

// Revolut joint has a fixed distance (d), changing theta (theta0)
// Prismatic joint has a changing distance, fixed theta
typedef enum {
  RAOS_JOINT_REVOLUT = 0,
  RAOS_JOINT_PRISMATIC = 1
} RAOS_JointType;

// standard Denavit-Hartenberg params
typedef struct {
  raos_scalar a; // link length along x (metres)
  raos_scalar alpha; // link twist about x (radians)
  raos_scalar d; // offset along z (metres)
  raos_scalar theta0; // fixed angle offset (radians)
  RAOS_JointType type; // revolut or prismatic (via RAOS_JointType) 
} RAOS_DHParam;

// mechanical limits on a joint
typedef struct {
  raos_scalar min;
  raos_scalar max;
  raos_scalar vmax;
  raos_scalar amax;
} RAOS_JointLimit;

// an internal definition of a joint
typedef struct {
  RAOS_DHParam dh;
  RAOS_JointLimit lim;
} RAOS_JointDef;

// full description
typedef struct {
  uint8_t dof;
  RAOS_JointDef joints[RAOS_MAX_DOF];
  RAOS_Mat4 base_T_world; // the arm's base in the world
  RAOS_Mat4 tool_T_offset; // tool offset from end effector
} RAOS_RobotConfig;

// Where the tool is in the world
typedef struct {
  RAOS_Vec3 p; // in meters
  RAOS_Quat q; 
} RAOS_Pose; 

// type of dispatchable actions
typedef enum {
  RAOS_ACT_MOVE_TO_POSE = 0, // cartesian space arm movement
  RAOS_ACT_MOVE_TO_JOINTS = 1, // joint space arm movement
  RAOS_ACT_TOOL_ACTION = 2, // non movement action
  RAOS_ACT_WAIT_MS = 3 // delay type action
} RAOS_ActionKind;

// movement via Cartesian waypoints
typedef struct {
  RAOS_Pose target;
  raos_scalar seconds;
} RAOS_MovePose;

// movement via joint-space
typedef struct {
  uint8_t dof;
  raos_scalar q[RAOS_MAX_DOF];
  raos_scalar seconds;
} RAOS_MoveJoints;

// tool action dispatch
typedef struct {
  uint8_t code;
  uint32_t param;
} RAOS_ToolAct;

// action dispatch
typedef struct {
  RAOS_ActionKind kind;
  union {
    RAOS_MovePose movePose;
    RAOS_MoveJoints moveJoints;
    RAOS_ToolAct tool;
    uint32_t wait_ms;
  } as;
} RAOS_Action;

// state of trajectory (arm movement)
typedef enum {
  RAOS_TRAJ_IDLE = 0,
  RAOS_TRAJ_RUNNING,
  RAOS_TRAJ_PAUSED,
  RAOS_TRAJ_STOPPED
} RAOS_TrajState;