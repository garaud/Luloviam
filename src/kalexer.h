
#include <string>

struct KaToken {
    enum {
        EndOfFile = -1,
        DefToken = 10,
    };
};

//! Lexer class.
class KaLexer {
public:
    static int get(std::istream& data) {
       char last_char;
       std::string identifier;
       while (!data.eof()) {
          data.get(last_char);
          identifier += last_char;
          if (identifier == "def")
             return KaToken::DefToken;
       };
       return KaToken::EndOfFile;
    }
};
