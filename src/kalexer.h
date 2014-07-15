
#include <string>
#include <limits>

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
            {
                current_number = std::stod(word);
                return KaToken::Number;
            }
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
    // Attributes.
    static double current_number;
};

double KaLexer::current_number = std::numeric_limits<double>::quiet_NaN();
