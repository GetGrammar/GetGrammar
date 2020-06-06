#define CTEST_MAIN

#include <ctest.h>
#include <stdio.h>
#include "Grammar_logic_lib.h"
#include "getgrammar_main.h"

CTEST(is_repeat, REPEAT_TRUE)
{
    int mas[4] = {1, 2, 3, 4};
    bool result = is_repeat(mas, 4);

    ASSERT_TRUE(result);
}

CTEST(is_repeat, REPEAT_FALSE)
{
    int mas[4] = {1, 2, 4, 4};
    bool result = is_repeat(mas, 4);

    ASSERT_FALSE(result);
}

CTEST(is_repeat, REPEAT_CURRENT_TRUE)
{
    int mas[4] = {1, 2, 3, 4};
    bool result = is_repeat(mas, 4, 5);

    ASSERT_TRUE(result);
}

CTEST(is_repeat, REPEAT_CURRENT_FALSE)
{
    int mas[4] = {1, 2, 3, 4};
    bool result = is_repeat(mas, 4, 4);

    ASSERT_FALSE(result);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
