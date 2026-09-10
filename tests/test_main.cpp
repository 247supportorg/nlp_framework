#include "nlp/preprocessor.h"
#include "nlp/tokenizer.h"
#include "nlp/vocabulary.h"

#include <cstdlib>
#include <iostream>
#include <vector>

namespace {

bool assert_true(bool condition, const char* message) {
    if (!condition) {
        std::cerr << "Test failed: " << message << '\n';
        return false;
    }
    return true;
}

bool test_preprocessor() {
    nlp::Preprocessor preprocessor;
    return assert_true(preprocessor.normalize("Hello, World!") == "hello world", "normalize should lowercase and strip punctuation");
}

bool test_tokenizer() {
    nlp::WhitespaceTokenizer tokenizer;
    const std::vector<std::string> expected{"hello", "world"};
    return assert_true(tokenizer.tokenize("hello world") == expected, "tokenizer should split on whitespace");
}

bool test_vocabulary() {
    nlp::Vocabulary vocabulary;
    const int hello_id = vocabulary.add_word("hello");
    const int world_id = vocabulary.add_word("world");

    return assert_true(hello_id == 0, "first id should be zero") &&
           assert_true(world_id == 1, "second id should be one") &&
           assert_true(vocabulary.add_word("hello") == hello_id, "duplicate words should reuse id") &&
           assert_true(vocabulary.get_id("missing") == -1, "missing words should return -1") &&
           assert_true(vocabulary.get_word(world_id) == "world", "id lookup should return original word") &&
           assert_true(vocabulary.size() == 2, "vocabulary size should match unique words");
}

}  // namespace

int main() {
    if (!test_preprocessor() || !test_tokenizer() || !test_vocabulary()) {
        return EXIT_FAILURE;
    }

    std::cout << "All tests passed\n";
    return EXIT_SUCCESS;
}
