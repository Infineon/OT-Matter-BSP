/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Suspend/Disable the OS thread preemption capability.
 */
void wiced_platform_os_preemption_suspend(void);

/**
 * \brief Resume/Enable the OS thread preemption capability.
 */
void wiced_platform_os_preemption_resume(void);

#ifdef __cplusplus
} /* extern "C" */
#endif
