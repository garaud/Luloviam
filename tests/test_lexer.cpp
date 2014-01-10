
#include "gtest/gtest.h"

#include "kalexer.h"

TEST(Lexer, read_eof_token) {
    ASSERT_EQ(KaLexer::get("EOF"), KaToken::EndOfFile);
}
