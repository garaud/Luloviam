
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
        IdentifierToken = -10,
        DefToken = -11,
        ExternToken = -12,
        NumberToken = -20,
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

bool first_char_is_not_valid(const std::string str_number) {
    char first = str_number.front();
    if (!std::isdigit(first) && first != DECIMAL_SEP
        && first != MINUS)
        return true;
    return false;
}

bool is_float(const std::string& str_number) {
    if (more_than_one_dot(str_number))
        return false;
    if (first_char_is_not_valid(str_number))
        return false;
    for (auto num : str_number.substr(1)) {
        if (!std::isdigit(num) &&
            num != DECIMAL_SEP) {
            return false;
        }
    }
    return true;
}

bool is_commented_line(const std::string& line) {
    if (line.front() == '#')
        return true;
    return false;
}

bool is_alnum(const std::string& word) {
    for (auto letter : word) {
        if (!std::isalnum(letter))
            return false;
    }
    return true;
}



//! Lexer class.
class KaLexer {
public:
    static int nextToken(std::istream& data) {
        while (!data.eof()) {
            std::string sentence;
            std::getline(data, sentence);
            if (sentence.empty())
                continue;
            str_container words = split_into_word(sentence);
            if (is_commented_line(words.front()))
                continue;
            for (auto identifier : words) {
                if (is_float(identifier))
                    return KaToken::NumberToken;
                if (is_alnum(identifier)) {
                    if (identifier == "def")
                        return KaToken::DefToken;
                    else if (identifier == "extern")
                        return KaToken::ExternToken;
                    else
                        return KaToken::IdentifierToken;
                }
            }
        };
        return KaToken::EndOfFile;
    }
};
