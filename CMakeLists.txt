cmake_minimum_required(VERSION 3.2)
project(neoterm-auth VERSION 1.3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
include_directories(${PROJECT_SOURCE_DIR})

find_library(LIB_CRYPTO crypto)

add_library(neoterm-auth SHARED neoterm-auth.c)
target_link_libraries(neoterm-auth ${LIB_CRYPTO})
install(TARGETS neoterm-auth DESTINATION lib)
install(FILES ${PROJECT_SOURCE_DIR}/neoterm-auth.h DESTINATION include)

add_executable(passwd passwd.c)
target_link_libraries(passwd neoterm-auth)
install(TARGETS passwd DESTINATION bin)

add_executable(pwlogin pwlogin.c)
target_link_libraries(pwlogin neoterm-auth)
install(TARGETS pwlogin DESTINATION bin)

add_executable(testauth testauth.c)
target_link_libraries(testauth neoterm-auth)
