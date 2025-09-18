cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(KMPSearch VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compiler flags for better debugging and warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Add the executable
add_executable(kmp_search kmp_search.cpp)

# Set output directory
set_target_properties(kmp_search PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Create build and bin directories
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/build)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add custom target for running the program
add_custom_target(run
    COMMAND kmp_search
    DEPENDS kmp_search
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMMENT "Running KMP Search Algorithm Demo"
)

# Add custom target for running tests
add_custom_target(test_kmp
    COMMAND kmp_search --test
    DEPENDS kmp_search
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMMENT "Running KMP Search Algorithm Tests"
)

# Add custom target for memory check (requires valgrind)
find_program(VALGRIND_EXECUTABLE valgrind)
if(VALGRIND_EXECUTABLE)
    add_custom_target(memcheck
        COMMAND ${VALGRIND_EXECUTABLE} --leak-check=full --show-leak-kinds=all $<TARGET_FILE:kmp_search>
        DEPENDS kmp_search
        COMMENT "Running memory check with valgrind"
    )
endif()

# Add custom target for static analysis (requires cppcheck)
find_program(CPPCHECK_EXECUTABLE cppcheck)
if(CPPCHECK_EXECUTABLE)
    add_custom_target(static_analysis
        COMMAND ${CPPCHECK_EXECUTABLE} --enable=all --std=c++17 ${CMAKE_CURRENT_SOURCE_DIR}/kmp_search.cpp
        COMMENT "Running static analysis with cppcheck"
    )
endif()

# Add custom target for code formatting (requires clang-format)
find_program(CLANG_FORMAT_EXECUTABLE clang-format)
if(CLANG_FORMAT_EXECUTABLE)
    add_custom_target(format
        COMMAND ${CLANG_FORMAT_EXECUTABLE} -i ${CMAKE_CURRENT_SOURCE_DIR}/kmp_search.cpp
        COMMENT "Formatting code with clang-format"
    )
endif()

# Add installation rules
install(TARGETS kmp_search
    RUNTIME DESTINATION bin
    COMPONENT applications
)

# Add custom target for clean build
add_custom_target(rebuild
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    COMMENT "Clean and rebuild"
)

# Print configuration information
message(STATUS "Project: ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Output directory: ${CMAKE_BINARY_DIR}/bin")

# Print available custom targets
message(STATUS "Available custom targets:")
message(STATUS "  run           - Build and run the program")
message(STATUS "  test_kmp      - Build and run tests")
message(STATUS "  rebuild       - Clean and rebuild")
if(VALGRIND_EXECUTABLE)
    message(STATUS "  memcheck      - Run memory check with valgrind")
endif()
if(CPPCHECK_EXECUTABLE)
    message(STATUS "  static_analysis - Run static analysis with cppcheck")
endif()
if(CLANG_FORMAT_EXECUTABLE)
    message(STATUS "  format        - Format code with clang-format")
endif()

# Enable testing
enable_testing()

# Add a test
add_test(
    NAME KMPAlgorithmTest
    COMMAND kmp_search --test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Set test properties
set_tests_properties(KMPAlgorithmTest PROPERTIES
    PASS_REGULAR_EXPRESSION "All tests passed!"
    FAIL_REGULAR_EXPRESSION "Some tests failed"
)

# Add a simple run test
add_test(
    NAME KMPAlgorithmRun
    COMMAND kmp_search
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set_tests_properties(KMPAlgorithmRun PROPERTIES
    PASS_REGULAR_EXPRESSION "KMP String Matching Algorithm Demo"
)