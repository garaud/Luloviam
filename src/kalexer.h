
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

typedef std::istream_iterator<std::string> sentence_iterator;
typedef std::vector<std::string> str_container;

struct KaToken {
    enum {
        EndOfFile = -1,
        DefToken = 10,
        ExternToken = 20,
        NumberToken = 30,
    };
};

std::vector<std::string> split_into_word(const std::string& line) {
   str_container words;
   std::istringstream stream_line(line);
   std::copy(sentence_iterator(stream_line),
                sentence_iterator(),
                std::back_inserter<str_container>(words));
   return words;
}

//! Lexer class.
class KaLexer {
public:
    static int get(std::istream& data) {
       while (!data.eof()) {
          std::string sentence;
          std::getline(data, sentence);
          str_container words = split_into_word(sentence);
          for (auto identifier : words) {
             if (identifier == "def")
                return KaToken::DefToken;
             if (identifier == "extern")
                return KaToken::ExternToken;
          }
       };
       return KaToken::EndOfFile;
    }
};
