# nlp_framework

NLP For Everyone

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
