find_library(libgtest libgtest)

# define the target name
set(TARGET MDParserTest)

# Add an executable to the project using the specified source files
add_executable(${TARGET} main.cxx)

# Specify libraries to use when linking 
target_link_libraries(${TARGET}
    PRIVATE
    libgtest
    MarkdownParserLib
)