cmake_minimum_required(VERSION 3.5)
project(project_casino VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

add_executable(project_casino src/main.cpp)

target_compile_features(project_casino INTERFACE cxx_std_11)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(project_casino INTERFACE
  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
  "$<${msvc_cxx}:-W3>"
)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_PREFIX_PATH "Dependencies/x64-windows")

find_package(Threads)
find_package(ZLIB REQUIRED)
find_package(OpenSSL REQUIRED)
target_link_libraries(project_casino PRIVATE ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto wsock32 ws2_32)

target_include_directories(project_casino PUBLIC
                           "${PROJECT_BINARY_DIR}/includes")