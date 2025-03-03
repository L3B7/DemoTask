# DemoTask

## Considerations:
### Project Structure:
Simplest build option would be to have the native source files inside the android project, and set it up with gradle to build the lib for us there.
However, the task description suggests a decoupled layout (for using the lib in other env.s as well). 
### Data Structure:
First assumed that k-v pairs should work well in a map, but the issue of duplicates (and the expected return order that keeps the order of input) suggests array of pairs might be better.
## Build script
cmake -DCMAKE_TOOLCHAIN_FILE=%ANDROID_NDK%\build\cmake\android.toolchain.cmake ^ -DANDROID_ABI=x86_64 ^ -DANDROID_PLATFORM=android-21 ^ -DCMAKE_BUILD_TYPE=Release ^ -DCMAKE_C_COMPILER=%CC% ^ -DCMAKE_CXX_COMPILER=%CXX% ^ ../../../DemoTask/cppLib/