cmake_minimum_required(VERSION 3.14)
project(BinarySearchTreeProject CXX)

# ==========================================
# 0. 컴파일 명령 내보내기
# ==========================================
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==========================================
# 1. Google Test 자동 다운로드 및 설정
# ==========================================
include(FetchContent)
message(STATUS "Fetching GoogleTest...")

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE 
)

# Windows 런타임 라이브러리 충돌 방지
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# ==========================================
# 2. 라이브러리 타겟 설정 (Header-Only)
# ==========================================
add_library(BinarySearchTreeLib INTERFACE)
add_library(AVLTreeLib INTERFACE)

target_include_directories(BinarySearchTreeLib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/BinarySearchTreeLib
)

target_include_directories(AVLTreeLib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/AVLTreeLib
)

# ==========================================
# 3. 유닛 테스트 실행 파일 설정
# ==========================================
enable_testing()

# ★ 중요: 폴더 구조를 확인하세요! (BinarySearchTreeUnitTest 폴더 안에 cpp 파일이 있어야 함)
add_executable(BinarySearchTreeUnitTest
    BinarySearchTreeUnitTest/BinarySearchTreeUnitTest.cpp
)

add_executable(AVLTreeUnitTest
    AVLTreeUnitTest/AVLTreeUnitTest.cpp
)

target_link_libraries(BinarySearchTreeUnitTest
    PRIVATE
    BinarySearchTreeLib
    GTest::gtest_main
)

target_link_libraries(AVLTreeUnitTest
    PRIVATE
    AVLTreeLib
    GTest::gtest_main
)

# ==========================================
# 4. CTest 등록
# ==========================================
include(GoogleTest)
gtest_discover_tests(BinarySearchTreeUnitTest)
gtest_discover_tests(AVLTreeUnitTest)