cmake_minimum_required(VERSION 3.11)

include(../cmake/raylib.cmake)
include(../cmake/raylib_cpp.cmake)

include(../cmake/nlohmann_json.cmake)

project(Custodia VERSION 0.1.0 LANGUAGES CXX)

include(../cmake/doxygen.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(${PROJECT_NAME} main.cpp "Sprite/Sprite.h" "Sprite/Sprite.cpp" "Player/Nemo.h" "Player/Nemo.cpp" "Level/UI.h" "Level/UI.cpp" "Level/Level.h" "Level/Level.cpp" 
 "Combat/GameCharacter.h" "Combat/GameCharacter.cpp" "Combat/Player.h" "Combat/Player.cpp" "Combat/Mumy.h" "Combat/Mumy.cpp" "Level/GameAudio.cpp" Level/Map.cpp Level/Map.h Level/TextureManager.cpp Level/TextureManager.h Level/Inventory.cpp Level/Inventory.h INCLUDES.h Level/Item.cpp Level/Item.h Level/Armor.cpp Level/Armor.h Level/dArr.h Level/Potion.cpp Level/Potion.h Level/Collision.cpp Level/Collision.h Level/Tile.cpp Level/Tile.h Combat/Shadow.cpp Combat/Shadow.h Combat/Pharaoh.cpp Combat/Pharaoh.h)

# Add config.h.in file
configure_file(config.h.in config.h)

target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

# Link to libraries
target_link_libraries(${PROJECT_NAME} raylib nlohmann_json::nlohmann_json)

# Copy assets to assets path
add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_LIST_DIR}/../cmake/copy-assets.cmake"
        )
add_dependencies(${PROJECT_NAME} copy_assets)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()

# CPack instructions
# call e.g. cpack -G ZIP -C Debug to create a binary distribution
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${PROJECT_NAME}_Bundle")
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/assets" DESTINATION "${PROJECT_NAME}_Bundle")
