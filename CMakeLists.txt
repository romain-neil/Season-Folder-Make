cmake_minimum_required(VERSION 3.17)
project(SeasonFolderMake)

set(CMAKE_CXX_STANDARD 17)
if (CMAKE_PREFIX_PATH)
else()
    set(CMAKE_PREFIX_PATH "D:/Qt/6.2.3/msvc2019_64/lib/cmake")
endif()
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets Network)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network)

add_executable(${PROJECT_NAME} main.cpp FenPrincipale.cpp FenPrincipale.h FolderCreateThread.cpp FolderCreateThread.h core.cpp core.h aboutdialog.cpp aboutdialog.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    if (EXISTS "${CMAKE_PREFIX_PATH}/../../plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${CMAKE_PREFIX_PATH}/../../plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB ${REQUIRED_LIBS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${CMAKE_PREFIX_PATH}/../../bin/Qt${QT_VERSION}${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

#set(TS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/translations/sfm_fr.ts )
#file(GLOB_RECURSE TS_SOURCES "*.cpp" "*.h" "*.ui")
#add_custom_target(translations)

#foreach(_ts_file ${TS_FILES})
    # generate a sensible name for this translation file
  #  get_filename_component(_ts_name ${_ts_file} NAME_WE)
    # call lupdate ourselves
   # add_custom_command(
  #          OUTPUT "${_ts_file}"
   #         DEPENDS ${TS_SOURCES}
   #         COMMAND ${Qt5_LUPDATE_EXECUTABLE} -recursive ${CMAKE_CURRENT_SOURCE_DIR} -ts ${_ts_file}
   # )
    # create a target that depends on the generated files
   # add_custom_target(translate_${_ts_name} DEPENDS ${_ts_file})
    # attach the custom target for this ts file to the parent target
    #add_dependencies(translations translate_${_ts_name})
#endforeach()

# generate qm files
#qt5_add_translation(QM_FILES ${TS_FILES})
#configure_file(translations.qrc ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

#add_executable(App
#        ${QM_FILES}
#        ${CMAKE_CURRENT_BINARY_DIR}/translations.qrc
#        )