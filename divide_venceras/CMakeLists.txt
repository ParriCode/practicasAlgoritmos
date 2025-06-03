# Define the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(AlgoritmosDA)

# Set C standard (you can adjust this to your version of C)
set(CMAKE_C_STANDARD 23)

# Define the source files for the project
set(SOURCES
    main.c
    algorithms/mergesort.c
    algorithms/ternaria.c
    algorithms/moreset.c
    algorithms/ejercicio4.c
    algorithms/ejercicio5.c
    algorithms/ejercicio6.c
    algorithms/ejercicio7.c
    disjoint/disjoint.c
  #  disjoint/prdisjoint.c
    fvector/fvector.c
    heap_aristas/depuracion.c
    heap_aristas/heap_aristas.c
    #heap_aristas/prueba_heap_aristas.c
    imatriz2d/imatriz2d.c
    #imatriz2d/prueba_imatriz2d.c
    ivector/ivector.c
   # ivector/prueba_ivector.c
    vdin/vdin.c

  #  vdin/prvdin.c
)

# Define the header files for the project (not strictly needed for compilation but useful for IDEs)
set(HEADERS
    algorithms/mergesort.h
    algorithms/ternaria.h
    algorithms/moreset.h
    algorithms/ejercicio4.h
    algorithms/ejercicio5.h
    algorithms/ejercicio6.h
    algorithms/ejercicio7.h
    disjoint/disjoint.h
    fvector/fvector.h
    heap_aristas/depuracion.h
    heap_aristas/heap_aristas.h

    imatriz2d/imatriz2d.h
    ivector/ivector.h
    vdin/vdin.h
)

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# If you want to specify certain compile flags, you can do that as well
# For example:
# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)