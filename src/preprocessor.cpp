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
