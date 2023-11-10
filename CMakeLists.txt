cmake_minimum_required(VERSION 3.16)

project(ColorBuster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appColorBuster
    main.cpp
    tile.h tile.cpp
    board.h board.cpp
    score.h score.cpp
    Game.h
    gamecontroller.h gamecontroller.cpp
    tilelistmodel.h tilelistmodel.cpp
    tilesortproxymodel.h tilesortproxymodel.cpp
    ScoreView.h
)

qt_add_qml_module(appColorBuster
    URI ColorBuster
    VERSION 1.0
    QML_FILES Main.qml TileView.qml BoardView.qml GameView.qml StartScreen.qml GameScreen.qml GameOverScreen.qml
)

set_target_properties(appColorBuster PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appColorBuster
    PRIVATE Qt6::Quick
)

install(TARGETS appColorBuster
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
