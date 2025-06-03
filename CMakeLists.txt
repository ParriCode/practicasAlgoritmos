cmake_minimum_required(VERSION 3.16)
project(practicas_algoritmos C)

# ---------- Ajustes globales ----------
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Binarios a  build/bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#INCLUIR CABECERAS NECESARIAS
if (MSVC)
    set(MATH_LIB "")
else()
    find_library(MATH_LIB_FOUND m)
    if (MATH_LIB_FOUND)
        set(MATH_LIB m)
    else()
        set(MATH_LIB "")
    endif()
endif()

# COMPILAR LAS EEDD

# Reúne recursivamente todos los .c de EEDD, EXCEPTO pruebas
file(GLOB_RECURSE EEDD_SRC CONFIGURE_DEPENDS
    EEDD/*.c)
# Excluir ficheros cuyo nombre empiece por pr, prueba o depuracion
list(FILTER EEDD_SRC EXCLUDE REGEX ".*/pr[^/]*\\.c$")
list(FILTER EEDD_SRC EXCLUDE REGEX ".*/prueba[^/]*\\.c$")
list(FILTER EEDD_SRC EXCLUDE REGEX ".*/depuracion\\.c$")

add_library(eedd STATIC ${EEDD_SRC})
# Cabeceras
target_include_directories(eedd PUBLIC ${PROJECT_SOURCE_DIR}/EEDD)



set(PRACTICE_DIRS
    dinamicos
    divide_venceras
    probabilisticos
    voraces
    vuelta_atras
)

foreach(DIR ${PRACTICE_DIRS})
    file(GLOB SRC_LIST CONFIGURE_DEPENDS ${DIR}/*.c)

    foreach(SRC ${SRC_LIST})
        get_filename_component(FNAME ${SRC} NAME_WE)
        string(REPLACE " " "_" FNAME ${FNAME})
        get_filename_component(PREFIX ${DIR} NAME)
        set(EXE_NAME "${PREFIX}_${FNAME}")

        add_executable(${EXE_NAME} ${SRC})

        # Enlaza con estructuras de datos y la librería matemática si existe
        target_link_libraries(${EXE_NAME} PRIVATE eedd ${MATH_LIB})

        # Cabeceras de EEDD
        target_include_directories(${EXE_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/EEDD)
    endforeach()
endforeach()
