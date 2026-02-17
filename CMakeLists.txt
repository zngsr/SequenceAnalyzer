cmake_minimum_required(VERSION 3.10)

# Project Name / Proje Adı
project(SequenceAnalyzer)

# C++ Standard / C++ Standardı
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Directories (Header Files Path) / Başlık Dosyaları Yolu
include_directories(include)

# Source Files / Kaynak Dosyaları
file(GLOB SOURCES "src/*.cpp")

# Executable Target (Output File Name) / Çalıştırılabilir Dosya (Çıktı Adı)
add_executable(${PROJECT_NAME} ${SOURCES})