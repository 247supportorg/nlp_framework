#include "nlp/preprocessor.h"
#include "nlp/tokenizer.h"
#include "nlp/vocabulary.h"

#include <iostream>

int main() {
    const std::string text = "Hello, NLP Framework!";

    nlp::Preprocessor preprocessor;
    nlp::WhitespaceTokenizer tokenizer;
    nlp::Vocabulary vocabulary;

    const std::string normalized = preprocessor.normalize(text);
    const auto tokens = tokenizer.tokenize(normalized);

    std::cout << "Normalized: " << normalized << "\n";
    std::cout << "Tokens:";

    for (const auto& token : tokens) {
        vocabulary.add_word(token);
        std::cout << ' ' << token;
    }

    std::cout << "\nVocabulary size: " << vocabulary.size() << "\n";
    return 0;
}
