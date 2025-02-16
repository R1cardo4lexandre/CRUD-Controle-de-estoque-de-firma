cmake_minimum_required(VERSION 3.30)
project(CRUD_Controle_de_estoque_de_firma)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/include)

add_executable(CRUD_Controle_de_estoque_de_firma
    src/include/ApplicationManager.h
    src/include/Database.h
    src/include/DatabaseAPI.h
    src/include/date.h
    src/include/Ferramenta.h
    src/include/Log.h
    src/include/Peca.h
    src/include/StageStructure.h
    src/include/Tamanho.h
    src/include/TimeUtils.h
    src/include/Utensilio.h
    src/include/Viagem.h
    src/utils/Database.cpp
    src/utils/DatabaseAPI_test.cpp
    src/utils/Log.cpp
    src/utils/maintest.cpp
    src/utils/TimeUtils.cpp
    src/ApplicationManager.cpp
    src/main.cpp)
