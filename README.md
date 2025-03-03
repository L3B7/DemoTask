# DemoTask

## Considerations:
### Project Structure:
Simplest build option would be to have the native source files inside the android project, and set it up with gradle+cmake to build the lib for us there.
However, the task description suggests a decoupled layout (for using the lib in other env.s as well), therefore I opted to have a seperate cpp lib, created a jni wrapper that will be called from the Android env (handling type conversions), build it using android NDK for the target ABI option, then copy the so file to the proper android location.
### Data Structure:
First assumed that k-v pairs should work well in a map, but the issue of duplicates (and the expected return order that keeps the order of input) suggests array of pairs might be better. (using android.util.Pair)
### Assumptions
- Assuming the seemingly incomplete sentence "- The string will contain semicolon-separated key-value pairs in the format." refers to the format shown in the example.
- Since the library should be packaged into the apk, I assume no linking exceptions would occur.
- The native code is built to ignore badly formatted lines. This behaviour could be adjusted to return with a certain value if any line is malformed.
## Building the lib
- Have the required NDK
- set ANDROID_NDK=C:\path\to\your\android-ndk
- set the proper ABI option, and the CMakeLists.txt location as well (relative to the current build folder)
- create a build folder for the chosen ABI
- cmake -DCMAKE_TOOLCHAIN_FILE=%ANDROID_NDK%\build\cmake\android.toolchain.cmake ^ -DANDROID_ABI=<x86_64, arm64-v8a, armeabi-v7a, x86> ^ -DANDROID_PLATFORM=android-21 ^ -DCMAKE_BUILD_TYPE=Release ^ -DCMAKE_C_COMPILER=%CC% ^ -DCMAKE_CXX_COMPILER=%CXX% ^ ../../../DemoTask/cppLib/
- cmake --build .
- Move the built .so file to the appropriate location in the android project: android\SeonTask\app\src\main\jniLibs\<selected ABI option>
- (Check if the ABI option is already included in the build gradle file)
## iOS integration
The most straightforward option is to use the Objective-C++ feature. For that, we should use .mm files (marking the Objective-C++ files).
Compared to android, there is no need to create a wrapper for the features; using both C++ and Objective-C features is supported in the .mm files. There are some limitations, such as exception handling, since the keywords for that are different in the two languages, meaning we cannot combine the two languages while handling exceptions. However, since we can use C++ inside our .mm file, we could just wrap our included C++ function with exception handling in the .mm file itself.

Using a wrapper could still be useful as it helps organising the code and makes it easier to avoid mistakes regarding conversions between Obj-C and C++. This wrapper serves as the interface to call C++ functions from the Obj-C code. We can simply use #include with the neccessary cpp files in this wrapper.
