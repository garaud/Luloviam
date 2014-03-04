
#include <string>

#include "str_utils.h"

enum class KaToken {
        EndOfFile = -1,
        Identifier = -10,
        Definition = -11,
        Extern = -12,
        Number = -20,
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
                    return KaToken::Number;
                if (is_alnum(identifier)) {
                    if (identifier == "def")
                        return KaToken::Definition;
                    else if (identifier == "extern")
                        return KaToken::Extern;
                    else
                        return KaToken::Identifier;
                }
                return KaToken::Unknown;
            }
        };
        return KaToken::EndOfFile;
    }
};
