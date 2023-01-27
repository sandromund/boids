cmake_minimum_required(VERSION 3.0.0)
project(boids)

add_executable(${PROJECT_NAME} src/main.c)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_compile_options(${PROJECT_NAME} PRIVATE -g)
target_link_libraries(${PROJECT_NAME} SDL2 SDL2_gfx m)
target_sources(${PROJECT_NAME} PRIVATE src/boid.c src/vec2d.c)
