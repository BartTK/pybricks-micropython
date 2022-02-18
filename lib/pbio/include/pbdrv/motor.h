// SPDX-License-Identifier: MIT
// Copyright (c) 2018-2020 The Pybricks Authors

/**
 * @addtogroup MotorDriver Driver: Motor
 * @{
 */

#ifndef _PBDRV_MOTOR_H_
#define _PBDRV_MOTOR_H_

#include <stdint.h>

#include <pbdrv/config.h>
#include <pbdrv/ioport.h>
#include <pbio/config.h>
#include <pbio/error.h>
#include <pbio/port.h>

/**
 * Motor constants across devices
 */
#define PBDRV_MAX_DUTY (10000)

#if PBDRV_CONFIG_MOTOR

/**
 * Instructs the motor to coast freely.
 * @param [in]  port    The motor port
 * @return              ::PBIO_SUCCESS if the call was successful,
 *                      ::PBIO_ERROR_INVALID_PORT if port is not a valid port
 *                      ::PBIO_ERROR_NO_DEV if port is valid but motor is not connected
 *                      ::PBIO_ERROR_IO if there was an I/O error
 */
pbio_error_t pbdrv_motor_coast(pbio_port_id_t port);

/**
 * Sets the PWM duty cycle for the motor. Setting a duty cycle of 0 will "brake" the motor.
 * @param [in]  port        The motor port
 * @param [in]  duty_cycle  The duty cycle -10000 to 10000
 * @return                  ::PBIO_SUCCESS if the call was successful,
 *                          ::PBIO_ERROR_INVALID_PORT if port is not a valid port
 *                          ::PBIO_ERROR_INVALID_ARG if duty_cycle is out of range
 *                          ::PBIO_ERROR_NO_DEV if port is valid but motor is not connected
 *                          ::PBIO_ERROR_IO if there was an I/O error
 */
pbio_error_t pbdrv_motor_set_duty_cycle(pbio_port_id_t port, int16_t duty_cycle);

#else

static inline pbio_error_t pbdrv_motor_coast(pbio_port_id_t port) {
    return PBIO_ERROR_NOT_SUPPORTED;
}
static inline pbio_error_t pbdrv_motor_set_duty_cycle(pbio_port_id_t port, int16_t duty_cycle) {
    return PBIO_ERROR_NOT_SUPPORTED;
}

#endif

#endif // _PBDRV_MOTOR_H_

/** @} */
