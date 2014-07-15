
#include <vector>
#include <algorithm>
#include <iterator>


const int DECIMAL_SEP('.');
const int MINUS('-');


typedef std::istream_iterator<std::string> sentence_iterator;
typedef std::vector<std::string> str_container;


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

bool is_comment(const std::string& word) {
    if (word.front() == '#')
        return true;
    return false;
}

void skipline(std::istream& buf) {
    std::string useless;
    std::getline(buf, useless);
}

std::string next_word(std::istream& stream) {
    std::string word;
    stream >> word;
    return word;
}

bool is_alnum(const std::string& word) {
    for (auto letter : word) {
        if (!std::isalnum(letter))
            return false;
    }
    return true;
}
