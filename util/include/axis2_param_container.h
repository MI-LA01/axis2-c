/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AXIS2_PARAM_CONTAINER_H
#define AXIS2_PARAM_CONTAINER_H

/** @defgroup axis2_param_container Parameter Container
 * @ingroup axis2_descript
 * @{
 */

/**
 * @file axis2_param_container.h
 * @brief Axis2 Param container interface
 */

#include <axis2_utils.h>
#include <axis2_error.h>
#include <axis2_utils_defines.h>
#include <axis2_env.h>
#include <axutil_allocator.h>
#include <axis2_string.h>
#include <axis2_array_list.h>
#include <axis2_hash.h>

/*#include <axiom_element.h>*/
#include <axis2_qname.h>
#include <axis2_param.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * each type which is passed as a param value to a parameter, must have this
     * type of function implemented. When the param value is set this function
     * should also be assigned to param free function
     */
    typedef void (AXIS2_CALL *
    AXIS2_PARAM_VALUE_FREE)(void *param, 
        const axis2_env_t *env);

    typedef struct axis2_param_container axis2_param_container_t;

    /**
     * Creates param container struct
     * @return pointer to newly created param container
     */
    AXIS2_EXTERN axis2_param_container_t * AXIS2_CALL
    axis2_param_container_create(const axis2_env_t *env);

    /**
     * Free param_container passed as void pointer. This will be
     * cast into appropriate type and then pass the cast object
     * into the param_container structure's free method
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_param_container_free_void_arg(void *param_container,
        const axis2_env_t *env);

    /** De-allocate memory
       * @return status code
       */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_param_container_free(axis2_param_container_t *param_container,
        const axis2_env_t *env);

    /** Add a param
      * @param param param to be added
      * @return status code
      */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_param_container_add_param(axis2_param_container_t *param_container,
        const axis2_env_t *env,
        axis2_param_t *param);

    /** To get a param in a given description
      * @param name param name
      * @return param
      */
    AXIS2_EXTERN axis2_param_t * AXIS2_CALL
    axis2_param_container_get_param(axis2_param_container_t *param_container,
        const axis2_env_t *env,
        const axis2_char_t *name);


    /** To get all the params in a given description
     * @return all the params contained
     */
    AXIS2_EXTERN axis2_array_list_t * AXIS2_CALL
    axis2_param_container_get_params(axis2_param_container_t *param_container,
        const axis2_env_t *env);

    /** To check whether the paramter is locked at any level
     * @param param_name name of the param
     * @return whether param is locked
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_param_container_is_param_locked(axis2_param_container_t *param_container,
        const axis2_env_t *env,
        const axis2_char_t *param_name) ;


    /** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_PARAM_CONTAINER_H */
