# Dir detection
file(GLOB V_GLOB LIST_DIRECTORIES true "*")
foreach(item ${V_GLOB})
        if(IS_DIRECTORY ${item})
                add_subdirectory(${item})
        endif()
endforeach()
#
file(GLOB QML_FILES "*.qml")
foreach(QML_FILE ${QML_FILES})
    get_filename_component(QML_NAME ${QML_FILE} NAME)
    set(QML_RESOURCE "${QML_NAME}")
    list(APPEND QML_UTILITIES ${QML_RESOURCE})
endforeach()
