cmake_minimum_required(VERSION 3.20)
project(stepik_oop_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

file(GLOB chapter_dirs RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/[0-9]*")

foreach(chapter_dir IN LISTS chapter_dirs)
    if (NOT IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${chapter_dir}")
        continue()
    endif()

    file(GLOB lesson_dirs RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/${chapter_dir}/[0-9]*")

    foreach(lesson_dir IN LISTS lesson_dirs)
        if (NOT IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${lesson_dir}")
            continue()
        endif()

        file(GLOB task_sources "${CMAKE_SOURCE_DIR}/${lesson_dir}/task_*.cpp")

        foreach(task_src IN LISTS task_sources)
            get_filename_component(task_name "${task_src}" NAME_WE)
            get_filename_component(lesson_name "${lesson_dir}" NAME)
            string(REGEX MATCH "^[0-9]+\\.[0-9]+" lesson_id "${lesson_name}")

            set(target_name "lesson_${lesson_id}_${task_name}")

            add_executable("${target_name}" "${task_src}")
        endforeach()
    endforeach()
endforeach()
