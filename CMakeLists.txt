
# Choose a version older than your smart phone.
# Version number same as standalone-toolchain.
# 這個版本號不能比你的手機新，否則產生的 apk 連安裝都辦不到
# 要跟 standalone-toolchain 寫的版本一樣
set(MY_TOOLCHAIN_API_LEVEL "android-15")

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/android/android.toolchain.cmake")

set(name "HelloAndroidNative")

project(${name})

cmake_minimum_required(VERSION 2.8)

# Debug mode have not to sign the apk file.
# Release 版需要設置簽名，Debug 版可以直接安裝，比較方便
set(CMAKE_BUILD_TYPE Debug)

include("${PROJECT_SOURCE_DIR}/cmake/android/create_apk.cmake" REQUIRED)


set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsigned-char")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffor-scope")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffunction-sections")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdata-sections")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffast-math")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsign-promo")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wstrict-null-sentinel")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -funroll-all-loops")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpeel-loops")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftree-vectorize")


include_directories($ENV{ANDROID_NDK_HOME}/sources/android/native_app_glue)
include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCES
	src/main.cpp
)


list(APPEND SOURCES "$ENV{ANDROID_NDK_HOME}/sources/android/native_app_glue/android_native_app_glue.c")

add_library(${name} SHARED ${SOURCES})

target_link_libraries(${name}
	log
	android
	#GL
	#GLESv2
	#GLESv1_CM
	#EGL
)

set_target_properties(${name} PROPERTIES COMPILE_DEFINITIONS "ANDROID")


# create_apk(
#     程式名稱
#     package 名字，必須是你手機中獨一無二的名字
#     apk 當然是要放在 binary 資料夾
#     不清楚為何沒有丟到 binary 資料夾
#     原本 Android Java 專案根目錄下的結構，現在是佈置在這裡
#     資源擺放這裡
# )
create_apk(
	${name}
	"opensource.native.example"
	"${CMAKE_BINARY_DIR}/apk"
	"${CMAKE_SOURCE_DIR}/libs"
	"${CMAKE_SOURCE_DIR}/android"
	"${CMAKE_SOURCE_DIR}/assets"
	"${MY_TOOLCHAIN_API_LEVEL}"
)
