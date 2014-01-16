
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

TEST_F(Lexer, recognizes_float_number) {
   buffer << "12.7";
   ASSERT_EQ(KaLexer::get(buffer), KaToken::NumberToken);
}
