
#include <sstream>

#include "gtest/gtest.h"

#include "kalexer.h"

const int EQUAL_CHAR('='); // ASCII value 61

// Testing fixture for the lexer.
class Lexer: public ::testing::Test {
public:
    std::stringstream buffer;
};

TEST_F(Lexer, read_eof_token) {
    ASSERT_EQ(KaToken::EndOfFile, KaLexer::nextToken(buffer));
}

TEST_F(Lexer, read_def_token) {
    buffer << "def foobar(x)";
    ASSERT_EQ(KaToken::Definition, KaLexer::nextToken(buffer));
}

TEST_F(Lexer, read_extern_token) {
    buffer << "extern babar();";
    ASSERT_EQ(KaToken::Extern, KaLexer::nextToken(buffer));
}

TEST_F(Lexer, skip_trailing_whitespaces) {
    buffer << "     def jazzy(player, year)";
    ASSERT_EQ(KaToken::Definition, KaLexer::nextToken(buffer));
}

TEST_F(Lexer, recognizes_identifier_token) {
    buffer << "variable = 12.5";
    ASSERT_EQ(KaToken::Identifier, KaLexer::nextToken(buffer));
}

TEST_F(Lexer, recognizes_float_number) {
    buffer << "12.7";
    ASSERT_EQ(KaToken::Number, KaLexer::nextToken(buffer));
}

TEST_F(Lexer, not_take_into_account_commented_line) {
    buffer << "  #   def stuff" << std::endl
           << "extern get_name(a, x)" << std::endl;
    ASSERT_EQ(KaToken::Extern, KaLexer::nextToken(buffer));
}

TEST_F(Lexer, not_identified_char_must_return_unknown_token) {
    buffer << "= 13.37";
    ASSERT_EQ(KaToken::Unknown, KaLexer::nextToken(buffer));
}

TEST_F(Lexer, DISABLED_consecutive_call_return_the_well_serie_of_tokens) {
    buffer << "babar = 23.0";
    ASSERT_EQ(KaToken::Identifier, KaLexer::nextToken(buffer));
    ASSERT_EQ(KaToken::Unknown, KaLexer::nextToken(buffer));
    ASSERT_EQ(KaToken::Number, KaLexer::nextToken(buffer));
}
