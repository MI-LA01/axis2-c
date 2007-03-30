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

#include <woden_ext_element.h>

axis2_status_t AXIS2_CALL
woden_ext_element_resolve_methods(
    woden_ext_element_t *ext_element,
    const axutil_env_t *env,
    axutil_hash_t *methods)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, methods, AXIS2_FAILURE);

    ext_element->ops->free = axutil_hash_get(methods, "free",
            AXIS2_HASH_KEY_STRING);
    ext_element->ops->type = axutil_hash_get(methods, "type",
            AXIS2_HASH_KEY_STRING);

    ext_element->ops->set_ext_type =
        axutil_hash_get(methods, "set_ext_type",
                AXIS2_HASH_KEY_STRING);

    ext_element->ops->get_ext_type =
        axutil_hash_get(methods, "get_ext_type",
                AXIS2_HASH_KEY_STRING);

    ext_element->ops->set_required =
        axutil_hash_get(methods, "set_required",
                AXIS2_HASH_KEY_STRING);

    ext_element->ops->is_required =
        axutil_hash_get(methods, "is_required",
                AXIS2_HASH_KEY_STRING);

    return AXIS2_SUCCESS;
}

