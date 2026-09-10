# nlp_framework

NLP For Everyone

## What's new

The legal basics are squared away, and the project is ready for its next stop:

- Added the MIT License for QB Networks in `LICENSE`.
- Added matching license notices to every C++ header, implementation, example, and test source file.
- Added the same licensing notice to this README without changing its rendered content.
- Added `CHANGELOG.md` so project updates stay clear and easy to scan.

## C++ NLP framework starter

This repository now includes a minimal C++17 NLP framework with:
- Text preprocessing (`Preprocessor`)
- Whitespace tokenization (`WhitespaceTokenizer`)
- Word-to-id vocabulary management (`Vocabulary`)

### Build

```bash
cmake -S . -B build
cmake --build build
```

### Test

```bash
ctest --test-dir build --output-on-failure
```

### Example

```bash
./build/nlp_example
```

## License

MIT License

Copyright (c) 2026-2027 QB Networks

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
