set(LIB MarkdownParserLib)

find_library(libstdc++ libstdc++)

# add the executable
add_library(${LIB}
    MDRawText.cxx
    MDTitle.cxx
    MDParser.cxx
)

target_link_libraries(${LIB} 
    libstdc++
)

target_include_directories(${LIB} 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
