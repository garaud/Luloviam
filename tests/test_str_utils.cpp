
#include <string>

#include "gtest/gtest.h"

#include "str_utils.h"


TEST(FuncUtils, next_word) {
    std::istringstream buf("just # three  words\n");
    std::string first = next_word(buf);
    std::string comment = next_word(buf);
    std::string second = next_word(buf);
    std::string third = next_word(buf);
    ASSERT_EQ("just", first);
    ASSERT_EQ("#", comment);
    ASSERT_EQ("three", second);
    ASSERT_EQ("words", third);
    ASSERT_EQ("", next_word(buf));
}

TEST(FuncUtils, skipline) {
    std::istringstream buf("just # three  words\nSecond line");
    next_word(buf);
    skipline(buf);
    std::string word = next_word(buf);
    ASSERT_EQ("Second", word);
}

TEST(FuncUtilsIsAlNum, recognize_alnum_word) {
    std::string word = "nameJohn12";
    ASSERT_TRUE(is_alnum(word));
}

TEST(FuncUtilIsFloat, well_recognize_float_number_in_a_string) {
    std::string str_number("14.702");
    ASSERT_TRUE(is_float(str_number));
}

TEST(FuncUtilIsFloat, handle_signed_float) {
    std::string str_number("-12.05");
    ASSERT_TRUE(is_float(str_number));
}

TEST(FuncUtilIsFloat, dont_recognize_malformed_str_float) {
    std::string str_number("45.-05");
    ASSERT_TRUE(!is_float(str_number));
    str_number = "123.45.78";
    ASSERT_TRUE(!is_float(str_number));
}
