
#include <sstream>

#include "gtest/gtest.h"

#include "kalexer.h"

TEST(Lexer, read_eof_token) {
   std::stringstream buffer;
   ASSERT_EQ(KaLexer::get(buffer), KaToken::EndOfFile);
}
