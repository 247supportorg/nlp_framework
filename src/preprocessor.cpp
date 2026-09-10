#include "nlp/preprocessor.h"

#include <algorithm>
#include <cctype>

namespace nlp {

std::string Preprocessor::lowercase(const std::string& text) const {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });
    return result;
}

std::string Preprocessor::remove_punctuation(const std::string& text) const {
    std::string result;
    result.reserve(text.size());

    for (unsigned char c : text) {
        if (std::isalnum(c) || std::isspace(c)) {
            result.push_back(static_cast<char>(c));
        }
    }

    return result;
}

std::string Preprocessor::normalize(const std::string& text) const {
    return remove_punctuation(lowercase(text));
}

}  // namespace nlp
