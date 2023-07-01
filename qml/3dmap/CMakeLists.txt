qt_add_library(DDDmap STATIC)
set_target_properties(DDDmap PROPERTIES AUTOMOC ON)
target_link_libraries(DDDmap PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${Qt_VERSION_MAJOR}::Quick3D
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

file(GLOB LIST_QML_RESOURCES "gfx/*.png" "gfx/*.jpg" "gfx/*.jpeg" "gfx/*.gif" "gfx/*.mp4")
set(QML_RESOURCES "")
foreach(QML_FILE ${LIST_QML_RESOURCES})
    get_filename_component(QML_NAME ${QML_FILE} NAME)
    set(QML_RESOURCE "gfx/${QML_NAME}")
    list(APPEND QML_RESOURCES ${QML_RESOURCE})
endforeach()
qt_add_big_resources(BFSOURCES "bigFiles.qrc")

qt6_add_qml_module(DDDmap
    URI DDDmap
    VERSION 1.0
    RESOURCE_PREFIX /DDDmap
    QML_FILES
    ${QML_UTILITIES}
    RESOURCES
    ${QML_RESOURCES}
)
