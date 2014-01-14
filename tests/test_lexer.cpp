
#include <sstream>

#include "gtest/gtest.h"

#include "kalexer.h"

TEST(Lexer, read_eof_token) {
   std::stringstream buffer;
   ASSERT_EQ(KaLexer::get(buffer), KaToken::EndOfFile);
}

TEST(Lexer, read_def_token) {
   std::stringstream buffer;
   buffer << "def foobar(x)";
   ASSERT_EQ(KaLexer::get(buffer), KaToken::DefToken);
}

TEST(Lexer, read_extern_token) {
   std::stringstream buffer;
   buffer << "extern babar();";
   ASSERT_EQ(KaLexer::get(buffer), KaToken::ExternToken);
}
