#include <string>
#include <map>
#include <jni.h>
#include "custom_parser.h"

extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_app_NativeLib_parseString(JNIEnv *env, jobject, jstring input) {
    const char *utfChars = env->GetStringUTFChars(input, nullptr);
    std::string str(utfChars);
    env->ReleaseStringUTFChars(input, utfChars);

    std::map<std::string, std::string> parsedData = parseKeyValuePairs(str);

    jclass javaHashMapClass = env->FindClass("java/util/HashMap");
    jmethodID init = env->GetMethodID(javaHashMapClass, "<init>", "()V");
    jobject javaHashMap = env->NewObject(javaHashMapClass, init);

    jmethodID putMethod = env->GetMethodID(javaHashMapClass, "put", 
                      "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

    // Iterate over the map and insert key-value pairs into HashMap
    for (const auto &pair : parsedData) {
        jstring key = env->NewStringUTF(pair.first.c_str());
        jstring value = env->NewStringUTF(pair.second.c_str());
        env->CallObjectMethod(javaHashMap, putMethod, key, value);
        env->DeleteLocalRef(key);
        env->DeleteLocalRef(value);
    }

    return javaHashMap;  // Return the Java HashMap
}