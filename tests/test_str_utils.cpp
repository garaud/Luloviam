
#include <string>

#include "gtest/gtest.h"

#include "str_utils.h"

TEST(FuncUtils, split_line_into_word) {
    std::string line("just three  words");
    std::vector<std::string> words = split_into_word(line);
    ASSERT_EQ(3, words.size());
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
