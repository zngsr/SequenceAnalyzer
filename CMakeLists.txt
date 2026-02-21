cmake_minimum_required(VERSION 3.10)

project(SequenceAnalyzer)

# Set C++20 Standard (for high-performance DNA data processing)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory for header files
include_directories(include)

# Explicitly define source files with their respective paths
set(SOURCES
    src/main.cpp
    src/DNASequence.cpp
    src/FastaReader.cpp
    src/ReportWriter.cpp
)

# Generate the executable file
add_executable(SequenceAnalyzer ${SOURCES})