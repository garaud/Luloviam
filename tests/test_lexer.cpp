
#include <sstream>

#include "gtest/gtest.h"

#include "kalexer.h"

// Testing fixture for the lexer.
class Lexer: public ::testing::Test {
public:
   std::stringstream buffer;
};

TEST_F(Lexer, read_eof_token) {
   ASSERT_EQ(KaLexer::get(buffer), KaToken::EndOfFile);
}

TEST_F(Lexer, read_def_token) {
   buffer << "def foobar(x)";
   ASSERT_EQ(KaLexer::get(buffer), KaToken::DefToken);
}

TEST_F(Lexer, read_extern_token) {
   buffer << "extern babar();";
   ASSERT_EQ(KaLexer::get(buffer), KaToken::ExternToken);
}

TEST_F(Lexer, skip_trailing_whitespaces) {
   buffer << "     def jazzy(player, year)";
   ASSERT_EQ(KaLexer::get(buffer), KaToken::DefToken);
}

TEST_F(Lexer, DISABLED_recognizes_float_number) {
   buffer << "12.7";
   ASSERT_EQ(KaLexer::get(buffer), KaToken::NumberToken);
}

TEST(FuncUtils, split_line_into_word) {
   std::string line("just three  words");
   std::vector<std::string> words = split_into_word(line);
   ASSERT_EQ(3, words.size());
}

TEST(FuncUtils, well_recognize_float_number_in_a_string) {
   std::string str_number("14.702");
   ASSERT_TRUE(is_float(str_number));
}

