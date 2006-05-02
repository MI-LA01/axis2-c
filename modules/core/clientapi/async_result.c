/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <axis2_async_result.h>
#include <axis2_const.h>
#include <axis2_hash.h>

typedef struct axis2_async_result_impl
{
    /** context base struct */
    axis2_async_result_t async_result;
    /** result message context */
    axis2_msg_ctx_t *result;
} axis2_async_result_impl_t;

/** Interface to implementation conversion macro */
#define AXIS2_INTF_TO_IMPL(async_result) ((axis2_async_result_impl_t *)async_result)


axis2_soap_envelope_t* AXIS2_CALL 
axis2_async_result_get_envelope(struct axis2_async_result *async_result, 
                                axis2_env_t **env);
                                
axis2_msg_ctx_t* AXIS2_CALL 
axis2_async_result_get_result(struct axis2_async_result *async_result, 
                              axis2_env_t **env);
                              
axis2_status_t AXIS2_CALL 
axis2_async_result_free (struct axis2_async_result *async_result, 
                         axis2_env_t **env);

axis2_async_result_t* AXIS2_CALL 
axis2_async_result_create(axis2_env_t **env, 
                          axis2_msg_ctx_t *result) 
{
    axis2_async_result_impl_t *async_result_impl = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    
    async_result_impl = AXIS2_MALLOC((*env)->allocator, 
                            sizeof(axis2_async_result_impl_t) );
    if (!async_result_impl)
    { 
        AXIS2_ERROR_SET((*env)->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;        
    }

    async_result_impl->async_result.ops = NULL;
    async_result_impl->result = NULL;
    
    if (result)
    {
        async_result_impl->result = result; /* shallow copy */
    }
    
    /* initialize ops */    
    async_result_impl->async_result.ops  = 
            AXIS2_MALLOC((*env)->allocator, sizeof(axis2_async_result_ops_t) );
    if (!async_result_impl->async_result.ops)
    {
        AXIS2_ERROR_SET((*env)->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        axis2_async_result_free(&(async_result_impl->async_result), env);
        return NULL;        
    }

    async_result_impl->async_result.ops->get_envelope = 
        axis2_async_result_get_envelope;
    
    async_result_impl->async_result.ops->get_result = 
        axis2_async_result_get_result;
    
    async_result_impl->async_result.ops->free = 
        axis2_async_result_free;

    return &(async_result_impl->async_result);
}

axis2_soap_envelope_t* AXIS2_CALL 
axis2_async_result_get_envelope(struct axis2_async_result *async_result, 
                                axis2_env_t **env)
{
    axis2_async_result_impl_t *async_result_impl = NULL;
        
    AXIS2_ENV_CHECK(env, NULL);
    
    async_result_impl = AXIS2_INTF_TO_IMPL(async_result);
    
    if (async_result_impl->result) 
    {
        return AXIS2_MSG_CTX_GET_SOAP_ENVELOPE(async_result_impl->result, env);
    } 
    
    return NULL;
}

axis2_msg_ctx_t* AXIS2_CALL 
axis2_async_result_get_result(struct axis2_async_result *async_result, 
                              axis2_env_t **env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return AXIS2_INTF_TO_IMPL(async_result)->result;
}

axis2_status_t AXIS2_CALL 
axis2_async_result_free (struct axis2_async_result *async_result, 
                         axis2_env_t **env)
{
    axis2_async_result_impl_t *async_result_impl = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    async_result_impl = AXIS2_INTF_TO_IMPL(async_result);
    
    if (async_result_impl->async_result.ops)
    {
        AXIS2_FREE((*env)->allocator, async_result_impl->async_result.ops);
        async_result_impl->async_result.ops = NULL;
    }
    
    /*if (async_result_impl->result)
    {
        AXIS2_MSG_CTX_FREE(async_result_impl->result, env);
        async_result_impl->result = NULL;
    }*/
    
    AXIS2_FREE((*env)->allocator, async_result_impl);
    async_result_impl = NULL;
    
    return AXIS2_SUCCESS;
}
