cmake_minimum_required(VERSION 3.16)

project(SMGG VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(tests FALSE)

find_package(Qt6 REQUIRED COMPONENTS Gui Core Qml Quick Quick3D)

if(tests)
    enable_testing()

    add_definitions(-DGTEST_LANGUAGE_CXX20)

    find_package(Threads REQUIRED)

    if ($ENV{GOOGLETEST_DIR})
        set(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
    else ()
        if (NOT "C:/Users/Jacob/source/repos/googletest" STREQUAL "")
            message(WARNING "Using googletest src dir specified at Qt Creator wizard")
        endif ()
        set(GOOGLETEST_DIR "C:/Users/Jacob/source/repos/googletest")
    endif ()
    if (EXISTS ${GOOGLETEST_DIR})
        set(GTestSrc ${GOOGLETEST_DIR}/googletest)
        set(GMockSrc ${GOOGLETEST_DIR}/googlemock)
    elseif (UNIX AND EXISTS /usr/src/gtest)
        set(GTestSrc /usr/src/gtest)
        message(WARNING "Using gtest from system")
        if (EXISTS /usr/src/gmock)
            set(GMockSrc /usr/src/gmock)
        endif ()
    else ()
        message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
    endif ()

    set(GTestFiles ${GTestSrc}/src/gtest-all.cc)
    set(GTestIncludes ${GTestSrc} ${GTestSrc}/include)
    if (NOT ${GMockSrc} STREQUAL "")
        list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
        list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
    endif ()

    include_directories(${GTestIncludes})

    file(GLOB_RECURSE CPPEXEFILES "src/*.cpp")

    file(GLOB_RECURSE TESTSCPPFILES "tests/*.cpp")

    add_executable(${PROJECT_NAME} ${TESTSCPPFILES}
        ${GTestFiles} ${CPPEXEFILES} main.cpp)

    target_link_libraries(${PROJECT_NAME} PRIVATE
        Threads::Threads
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::Qml
        Qt${Qt_VERSION_MAJOR}::Quick3D)

    add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

else()
    file(GLOB_RECURSE CPPEXEFILES "src/*.cpp")

    qt_add_executable(${PROJECT_NAME}
        ${CPPEXEFILES} main.cpp
    )

    target_sources(${PROJECT_NAME} PRIVATE ${BFSOURCES})

    add_subdirectory(qml)
    add_subdirectory(gfx)
    add_subdirectory(external)


    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER smgg2.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )

    target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::Qml
        Qt${Qt_VERSION_MAJOR}::Quick3D
        SMGG2Qmlplugin
        WelcomeMenuplugin
        Utilitiesplugin
        Guiplugin
        DDDmapplugin)

    install(TARGETS ${PROJECT_NAME}
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

endif()
