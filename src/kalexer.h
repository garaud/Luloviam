
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

typedef std::istream_iterator<std::string> sentence_iterator;
typedef std::vector<std::string> word_container;

struct KaToken {
    enum {
        EndOfFile = -1,
        DefToken = 10,
        ExternToken = 20,
        NumberToken = 30,
    };
};

std::vector<std::string> split_into_word(const std::string& line) {
   word_container words;
   std::istringstream stream_line(line);
   std::copy(sentence_iterator(stream_line),
                sentence_iterator(),
                std::back_inserter<word_container>(words));
   return words;
}

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
