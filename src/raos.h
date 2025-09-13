#pragma once
#include "raos_types.h"
#include "raos_errors.h"

// gives memory required
size_t raos_handle_bytes_required(void);

// initializes
RAOS_Result raos_init(void* mem, size_t bytes, RAOS_Handle** out_handle);

// set params
RAOS_Result raos_set_parameters(RAOS_Handle* h, const RAOS_RobotConfig* cfg);

// getters
uint8_t     raos_dof(const RAOS_Handle* h);
RAOS_Result raos_get_config(const RAOS_Handle* h, RAOS_RobotConfig* out_cfg);