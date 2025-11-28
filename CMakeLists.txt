cmake_minimum_required(VERSION 3.20)  # лучше сразу 3.20+, там много вкусного

# Название проекта и версия
project(MainInterface
    VERSION 1.7
    LANGUAGES CXX
    DESCRIPTION "Твой крутой кроссплатформенный проект"
)

# Стандарты C++
set(CMAKE_CXX_STANDARD 17)          # или 20/23, как хочешь
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)       # используем -std=c++17, а не -std=gnu++17

# ------------------------------------------------------------------
# Имена выходных файлов в зависимости от платформы и архитектуры
# ------------------------------------------------------------------
set(TARGET_NAME "MI")  # базовое имя без расширения

if(WIN32)
    set(EXECUTABLE_OUTPUT_NAME "${TARGET_NAME}.exe")
elseif(APPLE)
    set(EXECUTABLE_OUTPUT_NAME "${TARGET_NAME}_macos")
else()  # Linux, *BSD и т.д.
    set(EXECUTABLE_OUTPUT_NAME "${TARGET_NAME}.elf")
endif()

# Если хочешь ещё и архитектуру в имени (очень удобно при кросс-сборке)
set(EXECUTABLE_OUTPUT_NAME
    "${EXECUTABLE_OUTPUT_NAME}_${CMAKE_SYSTEM_PROCESSOR}"
)

# Создаём исполняемый файл
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/calc.cpp
    src/keygen.cpp
    src/conv.cpp
    src/functions.hpp
)

# Устанавливаем имя бинарника
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME ${EXECUTABLE_OUTPUT_NAME}
    # Для Windows можно ещё убрать консольное окно, если GUI приложение:
    # WIN32_EXECUTABLE TRUE
)

# Если нужно положить бинарник в bin/
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
