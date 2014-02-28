
#include <string>

#include "str_utils.h"

enum class KaToken {
        EndOfFile = -1,
        IdentifierToken = -10,
        DefToken = -11,
        ExternToken = -12,
        NumberToken = -20,
        Unknown = -99,
};


//! Lexer class.
class KaLexer {
public:
    static KaToken nextToken(std::istream& data) {
        while (!data.eof()) {
            std::string line;
            std::getline(data, line);
            if (line.empty())
                continue;
            str_container words = split_into_word(line);
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
                return KaToken::Unknown;
            }
        };
        return KaToken::EndOfFile;
    }
};
