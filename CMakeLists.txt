cmake_minimum_required(VERSION 3.8)
project(sonar_compute_bridge)

find_package(ament_cmake REQUIRED)

# 1. Static library path
set(RUST_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/target/debug/libsonar_compute_bridge.a")

# 2. Build Rust first
add_custom_target(sonar_rust_build ALL
    COMMAND cargo build
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    COMMENT "Building Rust engine..."
)

# 3. Create the C++ executable
add_executable(bridge_test_node src/test_bridge.cpp)

# 4. Headers
target_include_directories(bridge_test_node PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

# 5. Link with "Whole Archive" to prevent the linker from skipping Rust symbols
# We also add 'm' (math) and 'rt' (real-time) which Rust often needs
target_link_libraries(bridge_test_node 
    -Wl,--whole-archive "${RUST_LIB_PATH}" -Wl,--no-whole-archive
    pthread dl m rt
)

add_dependencies(bridge_test_node sonar_rust_build)

# Install the executable so ros2 run can find it
install(TARGETS bridge_test_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()