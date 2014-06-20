project(akonadiclient)

###### setup ######

include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} ${KDEPIMLIBS_INCLUDE_DIRS} ${KDE4_INCLUDES} ${QT_INCLUDE_DIR})

add_definitions(-DVERSION=\\"${VERSION}\\")

set(CMAKE_AUTOMOC TRUE)

###### target ######

set(akonadiclient_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/abstractcommand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/addcommand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/collectionresolvejob.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/collectionpathjob.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/commandfactory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/commandrunner.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/listcommand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/infocommand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/showcommand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/createcommand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/copycommand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/movecommand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/expandcommand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/errorreporter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/renamecommand.cpp
)

kde4_add_executable(akonadiclient ${akonadiclient_SRCS})
target_link_libraries(akonadiclient ${KDEPIMLIBS_AKONADI_LIBS} ${KDE4_KABC_LIBS} ${KDE4_KDECORE_LIBS} ${QT_QTCORE_LIBRARY})
set_target_properties(akonadiclient PROPERTIES ENABLE_EXPORTS TRUE)

###### version tracking ######

add_dependencies(akonadiclient vcsversion)

###### install ######

install(TARGETS akonadiclient ${INSTALL_TARGETS_DEFAULT_ARGS})
add_subdirectory(tests)