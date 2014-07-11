
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
        std::string word;
        while (!data.eof()) {
            word = next_word(data);
            if (is_comment(word)) {
                skipline(data);
                continue;
            }
            if (word == "") return KaToken::EndOfFile;
            if (is_float(word))
                return KaToken::Number;
            if (is_alnum(word)) {
                if (word == "def")
                    return KaToken::Definition;
                else if (word == "extern")
                    return KaToken::Extern;
                else
                    return KaToken::Identifier;
            }
            return KaToken::Unknown;
        }
        return KaToken::EndOfFile;
    }
};
