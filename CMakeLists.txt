cmake_minimum_required(VERSION 3.10)
project(ContextClipboard)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/third_party
)

set(COMMON_SOURCES
    src/ClipBoardListener.cpp
    src/Classifier.cpp
    src/Database.cpp
    src/Utils.cpp
    third_party/sqlite3.c
)

# Clipboard listener
add_executable(context_clipboard
    src/main.cpp
    ${COMMON_SOURCES}
)
target_include_directories(context_clipboard PRIVATE ${PROJECT_INCLUDE_DIRS})
target_link_libraries(context_clipboard user32)

# Search tool
add_executable(clipsearch
    src/clipsearch_main.cpp
    src/Search.cpp
    src/Utils.cpp
    third_party/sqlite3.c
)
target_include_directories(clipsearch PRIVATE ${PROJECT_INCLUDE_DIRS})