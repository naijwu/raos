#pragma once
#include "raos_types.h"

RAOS_Mat4   raos_mat4_identity(void);
RAOS_Mat4   raos_mat4_mul(const RAOS_Mat4* A, const RAOS_Mat4* B);
RAOS_Mat4   raos_mat4_from_pose(const RAOS_Pose* P);
RAOS_Mat4   raos_mat4_from_mat4(const RAOS_Mat4* M);

RAOS_Vec3   raos_vec3_add(RAOS_Vec3 a, RAOS_Vec3 b);
RAOS_Vec3   raos_vec3_sub(RAOS_Vec3 a, RAOS_Vec3 b);
raos_scalar raos_vec3_norm(RAOS_Vec3 a);

RAOS_Quat   raos_quat_mul(RAOS_Quat a, RAOS_Quat b);
RAOS_Quat   raos_quat_normalize(RAOS_Quat a);

raos_scalar raos_deg2rad(raos_scalar d);
raos_scalar raos_rad2deg(raos_scalar r);