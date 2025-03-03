#include <string>
#include <vector>
#include <jni.h>
#include "custom_parser.h"

extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_app_NativeLib_parseString(JNIEnv *env, jobject, jstring input) {
    const char *utfChars = env->GetStringUTFChars(input, nullptr);
    std::string str(utfChars);
    env->ReleaseStringUTFChars(input, utfChars);

    std::vector<std::pair<std::string, std::string>> parsedData = parseKeyValuePairs(str);

    jclass javaArrayListClass = env->FindClass("java/util/ArrayList");
    jmethodID javaArrayListInit = env->GetMethodID(javaArrayListClass, "<init>", "()V");
    jobject javaArrayList = env->NewObject(javaArrayListClass, javaArrayListInit);
    jmethodID javaArrayListAdd = env->GetMethodID(javaArrayListClass, "add", "(Ljava/lang/Object;)Z");


    jclass javaPairClass = env->FindClass("android/util/Pair");
    jmethodID javaPairInit = env->GetMethodID(javaPairClass, "<init>", "(Ljava/lang/Object;Ljava/lang/Object;)V");


    for (const auto &pair : parsedData) {
        jstring key = env->NewStringUTF(pair.first.c_str());
        jstring value = env->NewStringUTF(pair.second.c_str());
        jobject javaPair = env->NewObject(javaPairClass, javaPairInit, key, value);
        env->CallBooleanMethod(javaArrayList, javaArrayListAdd, javaPair);
        env->DeleteLocalRef(key);
        env->DeleteLocalRef(value);
        env->DeleteLocalRef(javaPair);
    }


    return javaArrayList;
}