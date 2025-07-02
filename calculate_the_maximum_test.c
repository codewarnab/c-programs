#include "calculate_the_maximum.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_and_max(void)
{
    TEST_ASSERT_EQUAL_INT(2, calculate_and_max(5, 4));
}

void test_or_max(void)
{
    TEST_ASSERT_EQUAL_INT(3, calculate_or_max(5, 4));
}

void test_xor_max(void)
{
    TEST_ASSERT_EQUAL_INT(3, calculate_xor_max(5, 4));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_and_max);
    RUN_TEST(test_or_max);
    RUN_TEST(test_xor_max);
    return UNITY_END();
}
