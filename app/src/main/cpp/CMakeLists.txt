# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# CMake 最低版本
cmake_minimum_required(VERSION 3.4.1)

# 变量
set(str "Hello JNI")
message(${str})

# 内置常亮
message(${CMAKE_CURRENT_LIST_DIR})
message(${CMAKE_CURRENT_LIST_FILE})

# 声明并命名项目
project("jni")

# 创建并命名库,将其设置为STATIC或SHARED,并提供其源代码的相对路径。
# 您可以定义多个库,CMake会为您构建它们。
# Gradle会自动将共享库与您的APK 打包。
# 1.指定库的名称
# 2.将库设置为共享库
# 3.提供源文件的相对路径
add_library(jni SHARED native-lib.cpp)

# 为了让CMake能够在编译时找到头文件,指定本机头文件的路径
include_directories(src/main/cpp/include/)

# 搜索指定的预生成库并将路径存储为变量
# 1.设置路径变量的名称
# 2.指定您希望CMake查找的NDK库的名称
find_library(log-lib log)

# 指定CMake应链接到目标库的库。可以链接多个库,例如在此生成脚本中定义的库、预生成的第三方库或系统库。
# 1.指定目标库
# 2.将目标库链接到NDK中包含的日志库
target_link_libraries(jni ${log-lib})