/*
 *   Copyright 2003-2004 The Apache Software Foundation.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include <openssl/evp.h>
#include <openssl_cipher_ctx.h>
#include <openssl_constants.h>
#include <oxs_sign_ctx.h>
#include <axis2_util.h>

/**
  * @file openssl_sign.h 
  * @brief 
  */
#ifndef OPENSSL_SIGN_H
#define OPENSSL_SIGN_H

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup
 * @ingroup
 * @{
 */

AXIS2_EXTERN int AXIS2_CALL
openssl_sign(const axis2_env_t *env,
        oxs_sign_ctx_t *sign_ctx,
        oxs_buffer_t *input_buf,
        oxs_buffer_t *output_buf);


/** @} */
#ifdef __cplusplus
}
#endif

#endif    /* OPENSSL_SIGN_H */