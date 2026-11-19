cmake_minimum_required(VERSION 3.16)
project(HighStakesCasino LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(casino
    main.cpp
    Blackjack/blackjack.cpp
    main_menu.cpp
)

target_include_directories(casino PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(casino PRIVATE sfml-graphics sfml-window sfml-system)
