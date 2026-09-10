cmake_minimum_required(VERSION 3.15)
project(nlp_framework VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(nlp_framework
    src/preprocessor.cpp
    src/tokenizer.cpp
    src/vocabulary.cpp
)

target_include_directories(nlp_framework PUBLIC include)

add_executable(nlp_example examples/basic_usage.cpp)
target_link_libraries(nlp_example PRIVATE nlp_framework)

enable_testing()
add_subdirectory(tests)
