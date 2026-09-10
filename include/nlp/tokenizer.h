#pragma once

#include <string>
#include <vector>

namespace nlp {

class Tokenizer {
public:
    virtual ~Tokenizer() = default;
    virtual std::vector<std::string> tokenize(const std::string& text) const = 0;
};

class WhitespaceTokenizer : public Tokenizer {
public:
    std::vector<std::string> tokenize(const std::string& text) const override;
};

}  // namespace nlp
