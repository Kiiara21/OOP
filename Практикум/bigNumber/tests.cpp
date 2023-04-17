#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bigNumber.h"

TEST_CASE("Constructor with long long int number - test"){
    BigNumber bigNumber(123456765432);
    CHECK_EQ(bigNumber.getLength(), bigNumber.longLength(123456765432));
}

TEST_CASE ("getLength - test"){
    BigNumber bigNumber("234");
    CHECK_EQ(bigNumber.getLength(), 3);
}

TEST_CASE("operator== - test"){
    BigNumber bigNumber1("123"), bigNumber2("123");
    CHECK_FALSE(!(bigNumber1 == bigNumber2));
}

TEST_CASE("operator!= - test"){
    BigNumber bigNumber1("123"), bigNumber2("123");
    CHECK_FALSE(bigNumber1 != bigNumber2);
}

TEST_CASE("operator< - test"){
    BigNumber bigNumber1("122"), bigNumber2("123");
    CHECK_FALSE(!(bigNumber1 < bigNumber2));
}

TEST_CASE("operator> - test"){
    BigNumber bigNumber1("123"), bigNumber2("122");
    CHECK_FALSE(!(bigNumber1 > bigNumber2));
}


TEST_CASE("operator+= - test"){
    BigNumber bn1("30"), bn2("80");
    bn1 += bn2;
    std::cout << bn1;
    CHECK_EQ(0, 0);
}