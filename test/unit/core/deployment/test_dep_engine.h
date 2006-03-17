#ifndef TEST_DEP_ENGINE_H
#define TEST_DEP_ENGINE_H

#undef NULL
#include <CuTest.h>

void Testaxis2_dep_engine_free(CuTest *tc);
void Testaxis2_dep_engine_create(CuTest *tc);
void Testaxis2_dep_engine_create_with_repos_name(CuTest *tc);
void Testaxis2_dep_engine_load(CuTest *tc);

#endif /* TEST_DEP_ENGINE_H*/
