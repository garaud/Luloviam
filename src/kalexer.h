
#include <string>

struct KaToken {
    enum {
        EndOfFile = -1,
    };
};

class KaLexer {
public:
    static int get(const std::string& input) {
        return -1;
    }
};
