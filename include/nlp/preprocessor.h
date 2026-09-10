#pragma once

#include <string>

namespace nlp {

class Preprocessor {
public:
    std::string lowercase(const std::string& text) const;
    std::string remove_punctuation(const std::string& text) const;
    std::string normalize(const std::string& text) const;
};

}  // namespace nlp
