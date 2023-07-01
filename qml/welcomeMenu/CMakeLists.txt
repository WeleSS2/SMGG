qt_add_library(WelcomeMenu STATIC)
set_target_properties(WelcomeMenu PROPERTIES AUTOMOC ON)
target_link_libraries(WelcomeMenu
    PRIVATE Qt6::Quick
)

file(GLOB_RECURSE QML_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.qml")
set(QML_UTILITIES "")
foreach(QML_FILE ${QML_FILES})
    get_filename_component(QML_DIR ${QML_FILE} DIRECTORY)
    get_filename_component(QML_NAME ${QML_FILE} NAME)
    if(QML_DIR STREQUAL "")
        set(QML_RESOURCE "${QML_NAME}")
        list(APPEND QML_UTILITIES ${QML_RESOURCE})
    else()
        set(QML_RESOURCE "${QML_DIR}/${QML_NAME}")
        list(APPEND QML_UTILITIES ${QML_RESOURCE})
    endif()
endforeach()

file(GLOB LIST_QML_RESOURCES "*.png" "*.jpg" "*.jpeg" "*.gif" "*.mp4")
set(QML_RESOURCES "")
foreach(QML_FILE ${LIST_QML_RESOURCES})
    get_filename_component(QML_NAME ${QML_FILE} NAME)
    set(QML_RESOURCE "${QML_NAME}")
    list(APPEND QML_RESOURCES ${QML_RESOURCE})
endforeach()

qt6_add_qml_module(WelcomeMenu
    URI WelcomeMenu
    VERSION 1.0
    RESOURCE_PREFIX /WelcomeMenu
    QML_FILES
    ${QML_UTILITIES}
    RESOURCES
        ${QML_RESOURCES}
)
