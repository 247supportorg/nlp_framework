// MIT License
//
// Copyright (c) 2026-2027 QB Networks
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
