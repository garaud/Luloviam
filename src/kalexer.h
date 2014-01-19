
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

typedef std::istream_iterator<std::string> sentence_iterator;
typedef std::vector<std::string> str_container;

const int DECIMAL_SEP('.');
const int MINUS('-');

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

bool more_than_one_dot(const std::string& str_number) {
   int dot_count = 0;
   for (auto num : str_number) {
      if (num == DECIMAL_SEP)
         dot_count += 1;
   }
   return dot_count > 1;
}

bool is_float(const std::string& str_number) {
   if (more_than_one_dot(str_number))
       return false;
   // First char: digit, minus or dot.
   char first = str_number.front();
   if (!std::isdigit(first) && first != DECIMAL_SEP
      && first != MINUS)
      return false;
   for (auto num : str_number.substr(1)) {
      if (!std::isdigit(num) &&
          num != DECIMAL_SEP) {
         return false;
      }
   }
   return true;
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
