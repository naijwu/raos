#pragma once
#include "raos_types.h"
#include "raos_errors.h"

// build transforms via the given DH params
RAOS_Mat4 raos_dh_matrix(const RAOS_DHParam* p, raos_scalar q_i);

RAOS_Result raos_vaildate_jointdef(const RAOS_JointDef* def);
RAOS_Result raos_validate_config(const RAOS_RobotConfig* config);