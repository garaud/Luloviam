
#include <string>

struct KaToken {
    enum {
        EndOfFile = -1,
        DefToken = 10,
        ExternToken = 20,
    };
};

//! Lexer class.
class KaLexer {
public:
    static int get(std::istream& data) {
       char last_char;
       std::string identifier;
       while (!data.eof()) {
          // Skipping whitespaces flag.
          data >> std::skipws >> last_char;
          identifier += last_char;
          if (identifier == "def")
             return KaToken::DefToken;
          if (identifier == "extern")
             return KaToken::ExternToken;
       };
       return KaToken::EndOfFile;
    }
};
