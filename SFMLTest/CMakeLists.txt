# CMakeList.txt : CMake project for SFMLTest, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (SFMLTest "Main.cpp"   "game/Game.cpp" "game/Settings/keyControl.cpp" "game/Settings/Settings.h" "game/Settings/Settings.cpp" "game/Graphical/Atlas.h" "game/Graphical/Atlas.cpp" "game/Graphical/Quad.cpp" "game/Graphical/TexCordArray.h" "game/Graphical/TexCordArray.cpp" "game/Graphical/xRender.h" "game/Graphical/xRender.cpp"  "game/Graphical/Advanced/DynamicAtlas.h" "game/Graphical/Advanced/DynamicAtlas.cpp"   "game/Graphical/Advanced/SmartPointer.h" "game/Graphical/Advanced/SmartPointer.cpp" "game/Graphical/Advanced/DynamicVertexArray.h" "game/Graphical/Advanced/DynamicVertexArray.cpp" "game/Graphical/Advanced/StaticVertexArray.h" "game/Graphical/Advanced/StaticVertexArray.cpp" "game/Game/World/Chunk.h" "game/Game/World/Chunk.cpp" "game/Game/World/Tile.h" "game/Game/World/Tile.cpp" "game/Game/World/ChunkManager.h" "game/Game/World/ChunkManager.cpp" "game/TextureManager.h" "game/TextureManager.cpp" "game/State.h" "game/Game/GameState.h" "game/Menus/MenuState.h" "game/Menus/MenuState.cpp" "game/StateManager.cpp" "game/StateManager.h" "game/State.cpp")
target_compile_options(SFMLTest PUBLIC "/Zc:__cplusplus")

#target_link_libraries(SFMLTest "${CMAKE_CURRENT_SOURCE_DIR}/lib/libsfml-graphics.a")
#target_link_libraries(SFMLTest "${CMAKE_CURRENT_SOURCE_DIR}/lib/libsfml-window.a")
#target_link_libraries(SFMLTest "${CMAKE_CURRENT_SOURCE_DIR}/lib/libsfml-system.a")

#target_link_libraries(SFMLTest "${CMAKE_CURRENT_SOURCE_DIR}/lib/sfml-graphics.lib")
#target_link_libraries(SFMLTest "${CMAKE_CURRENT_SOURCE_DIR}/lib/sfml-window.lib")
#target_link_libraries(SFMLTest "${CMAKE_CURRENT_SOURCE_DIR}/lib/sfml-system.lib")

target_link_libraries(SFMLTest "${CMAKE_CURRENT_SOURCE_DIR}/lib/sfml-graphics-d.lib")
target_link_libraries(SFMLTest "${CMAKE_CURRENT_SOURCE_DIR}/lib/sfml-window-d.lib")
target_link_libraries(SFMLTest "${CMAKE_CURRENT_SOURCE_DIR}/lib/sfml-system-d.lib")

target_include_directories(SFMLTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# TODO: Add tests and install targets if needed.
