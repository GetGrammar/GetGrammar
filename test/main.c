#define CTEST_MAIN

#include <ctest.h>
#include "Grammar_logic_lib.h"

CTEST(is_repeat, INCORRECT_CURRENT_TRUE)
{
    mas = [1, 2, 3, 4];

    bool result = is_repeat(mas, 4, 5);

    ASSERT_TRUE(result);
}

CTEST(is_repeat, INCORRECT_CURRENT_FALSE)
{
    mas = [1, 2, 3, 4];

    bool result = is_repeat(mas, 4, 2);

    ASSERT_FALSE(result);
}
