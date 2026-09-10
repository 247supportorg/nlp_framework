#pragma once

#include <string>
#include <unordered_map>

namespace nlp {

class Vocabulary {
public:
    int add_word(const std::string& word);
    int get_id(const std::string& word) const;
    std::string get_word(int id) const;
    int size() const;

private:
    std::unordered_map<std::string, int> word_to_id_;
    std::unordered_map<int, std::string> id_to_word_;
    int next_id_ = 0;
};

}  // namespace nlp
