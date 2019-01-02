cmake_minimum_required(VERSION 2.8)

set(PROJECTNAME BlockchainDemo)
project(${PROJECTNAME})
message("==== Projectname: ${PROJECTNAME}")

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Wpedantic -Wold-style-cast \
    -Winit-self -Wno-unused -Wshadow \
    -Wno-parentheses -Wlogical-op -Wredundant-decls \
    -Wcast-align -Wsign-promo -Wmissing-include-dirs \
    -Woverloaded-virtual -Wctor-dtor-privacy")

include_directories(${PROJECT_SOURCE_DIR}/src
                    ${PROJECT_SOURCE_DIR}/src/JSON
                    ${PROJECT_SOURCE_DIR}/src/SHA256)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

message("==== Source dir: ${CMAKE_SOURCE_DIR}")

file(
    GLOB_RECURSE BLOCKCHAINDEMO_SOURCES
    RELATIVE ${CMAKE_SOURCE_DIR}
    src/*.cpp
    src/*.h
    src/JSON/*.hpp
    src/SHA256/*.h 
    src/SHA256/*.cpp 
)

message("==== BlockchainDemo sources: ${BLOCKCHAINDEMO_SOURCES}")

add_executable(BlockchainDemo ${BLOCKCHAINDEMO_SOURCES})
# target_link_libraries(BlockchainDemo Boost::program_options Boost::filesystem)