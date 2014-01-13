
#include <string>

struct KaToken {
    enum {
        EndOfFile = -1,
    };
};

class KaLexer {
public:
    static int get(std::istream& data) {
       char last_char;
       while (!data.eof()) {
          data.get(last_char);
       };
       return -1;
    }
};
