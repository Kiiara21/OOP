#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "nVector.h" 

TEST_CASE("size getter"){
    Nvector nv;
    nv.push(1);
    CHECK_EQ(nv.getSize(), 1);
}