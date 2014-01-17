
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

struct KaToken {
    enum {
        EndOfFile = -1,
        DefToken = 10,
        ExternToken = 20,
        NumberToken = 30,
    };
};

std::vector<std::string> split_into_word(const std::string& line) {
   std::vector<std::string> words;
   std::istringstream stream_line(line);
   std::copy(std::istream_iterator<std::string>(stream_line),
             std::istream_iterator<std::string>(),
             std::back_inserter<std::vector<std::string> >(words));
   return words;
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
