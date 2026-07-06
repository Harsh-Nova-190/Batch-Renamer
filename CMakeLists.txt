cmake_minimum_required(VERSION 3.21)

project(NovaBytesBatchRenamer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "F:/Software/QT6/6.11.1/msvc2022_64/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(NovaBytesBatchRenamer

    src/app/main.cpp

    src/ui/MainWindow.cpp
    include/ui/MainWindow.h
    
    src/core/ThemeManager.cpp
    include/core/ThemeManager.h
 
    include/widgets/DropArea.h
    src/widgets/DropArea.cpp

    resources/NovaBytesResources.qrc
 
    include/widgets/FileTable.h
    src/widgets/FileTable.cpp
 "src/core/FileManager.cpp" "include/core/FileManager.h" "include/models/FileItem.h" "src/core/RenameEngine.cpp" "include/core/RenameEngine.h" "include/widgets/RenamePanel.h" "src/widgets/RenamePanel.cpp" "include/models/RenameOptions.h" "include/core/RenameExecutor.h" "src/core/RenameExecutor.cpp")

target_include_directories(NovaBytesBatchRenamer PRIVATE include)

target_link_libraries(NovaBytesBatchRenamer PRIVATE Qt6::Widgets)

