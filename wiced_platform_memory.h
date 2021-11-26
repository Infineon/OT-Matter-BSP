/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief       Allocate memory from the dynamic memory pool.
 *
 * @param[in]   size - size of required memory block
 *
 * @retval      address of the allocate memory block
 *
 */
void *wiced_platform_memory_allocate(uint32_t size);

/**
 * \brief       Free a memory block.
 *
 * @param[in]   p_addr - start address of the memory block to be freed
 */
void wiced_platform_memory_free(void *p_addr);

#ifdef __cplusplus
} /* extern "C" */
#endif
