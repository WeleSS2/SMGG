qt_add_library(SMGG2Qml STATIC)
set_target_properties(SMGG2Qml PROPERTIES AUTOMOC ON)
target_link_libraries(SMGG2Qml
    PRIVATE Qt6::Quick
)

set(MAIN_QML_FILE
    main.qml
)
qt6_add_qml_module(SMGG2Qml
    URI SMGG2Q
    VERSION 1.0
    RESOURCE_PREFIX /QmlFiles
    QML_FILES
    ${MAIN_QML_FILE}
)

add_subdirectory(welcomeMenu)
add_subdirectory(utilities)
add_subdirectory(3dmap)
add_subdirectory(gui)
