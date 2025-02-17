cmake_minimum_required(VERSION 3.30)

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG main # Important: Specify a version or a commit hash here.
)
FetchContent_MakeAvailable(ftxui)

project(CRUD_Controle_de_estoque_de_firma)

set(CMAKE_CXX_STANDARD 20)

add_executable(CRUD_Controle_de_estoque_de_firma
        main.cpp
        include/ApplicationManager.h
        include/date.h
        include/TimeUtils.h
        ApplicationManager.cpp
        utils/TimeUtils.cpp
        include/Tool.h
        include/StageStructure.h
        include/Component.h
        include/StageSize.h
        include/Travel.h
        include/Mock.h
        utils/Mock.cpp
)

target_include_directories(CRUD_Controle_de_estoque_de_firma PRIVATE src/include)

target_link_libraries(CRUD_Controle_de_estoque_de_firma
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component # Not needed for this example.
)