cmake_minimum_required(VERSION 3.12)
project(Xonix)

set(CMAKE_CXX_STANDARD 14)

add_executable(Xonix main.cpp settings.h Menu.cpp Menu.h cmake-build-debug/Player.cpp cmake-build-debug/Player.h Game.cpp Game.h Player.cpp Player.h EnemyA.cpp EnemyA.h EnemyB.cpp EnemyB.h)