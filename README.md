# Hello Android Native!
This project show you how to build Android APP with C++ and CMake.  
All the comments and tutorials are almost writen in Traditional Chinese.  
I guess it couldn't bother you at all.  
這個專案示範了如何單純使用 C++ 來寫 Android 程式  
不需要寫 Java 程式碼  
也不需要 Android Studio 或 Eclipse  

### What you required
- Ubuntu(I never try to build it on Windows)
- GCC
- JRE & JDK
- ant
- Android SDK
- Android NDK
- CMake

### License
Every thing are belong to public domain, except "android.toolchain.cmake".

### Usage
1. Setup what you required.
1. Create toolchain by make-standalone-toolchain.sh that locate at NDK.
1. Modify set-env-var.sh and CMakeLists.txt to get resource.
1. $ cd HelloAndroidNative
1. $ source set-env-var.sh
1. $ mkdir build
1. $ cd build
1. $ cmake ../ -G "Unix Makefiles"
1. $ make

### Others
This project is too simple for a real Android APP.  
I recommend you read the following resource.  
https://github.com/taka-no-me/android-cmake  
https://github.com/Discordia/android-cmake-example  
