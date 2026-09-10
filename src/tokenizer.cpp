#include "nlp/tokenizer.h"

#include <sstream>

namespace nlp {

std::vector<std::string> WhitespaceTokenizer::tokenize(const std::string& text) const {
    std::vector<std::string> tokens;
    std::istringstream stream(text);
    std::string token;

    while (stream >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

}  // namespace nlp
