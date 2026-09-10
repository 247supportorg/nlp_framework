#include "nlp/vocabulary.h"

namespace nlp {

int Vocabulary::add_word(const std::string& word) {
    const auto existing = word_to_id_.find(word);
    if (existing != word_to_id_.end()) {
        return existing->second;
    }

    const int id = next_id_++;
    word_to_id_[word] = id;
    id_to_word_[id] = word;
    return id;
}

int Vocabulary::get_id(const std::string& word) const {
    const auto it = word_to_id_.find(word);
    return it == word_to_id_.end() ? -1 : it->second;
}

std::string Vocabulary::get_word(int id) const {
    const auto it = id_to_word_.find(id);
    return it == id_to_word_.end() ? "" : it->second;
}

int Vocabulary::size() const {
    return next_id_;
}

}  // namespace nlp
