#define CTEST_MAIN

#include <ctest.h>
#include <stdio.h>
#include <cstring>
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

CTEST(find_word, FIND_MOD_0_TRUE)
{
    bool result = false;
    string a = "";
    
    string b = find_word(4, 0);
    if (a == b){
        result = true;
    }

    ASSERT_TRUE(result);
}

CTEST(find_word, FIND_MOD_0_FALSE)
{
    bool result = false;
    string a = "дом";
    
    string b = find_word(4, 0);
    if (a == b){
        result = true;
    }

    ASSERT_FALSE(result);
}

CTEST(find_word, FIND_MOD_1_TRUE)
{
    bool result = false;
    string a = "";
    
    string b = find_word(4, 1);
    if (a == b){
        result = true;
    }

    ASSERT_TRUE(result);
}

CTEST(find_word, FIND_MOD_1_FALSE)
{
    bool result = false;
    string a = "house";
    
    string b = find_word(4, 1);
    if (a == b){
        result = true;
    }

    ASSERT_FALSE(result);
}

CTEST(str_to_char, STR_TO_CHAR_TRUE)
{
    bool result = false;
    string s = "a";
    char a = 'a';
    
    char* b = str_to_char(s);
    if (a == b[0]){
        result = true;
    }

    ASSERT_TRUE(result);
}

CTEST(str_to_char, STR_TO_CHAR_FALSE)
{
    bool result = false;
    string s = "a";
    char a = 'b';
    
    char* b = str_to_char(s);
    if (a == b[0]){
        result = true;
    }

    ASSERT_FALSE(result);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
