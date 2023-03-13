#include <jni.h>
#include <string>

// 相比于静态注册,动态注册不必在每次运行调用Native方法都去进行方法查找,所以相对来说动态注册的性能更高一些。

// 前两个参数还是固定的
jstring dynamicMethod(JNIEnv *env, jobject jobj, jstring jname) {
    return env->NewStringUTF("hello from C++ string");
}

// Java中的函数名 函数签名信息 Native的函数指针
static const JNINativeMethod nativeMethod[] = {{"dynamicMethod", "(Ljava/lang/String;)Ljava/lang/String;", (void *) (dynamicMethod)},};

// 类库加载时自动调用
JNIEXPORT jint

JNICALL JNI_OnLoad(JavaVM *vm, void *reversed) {
    JNIEnv *env = NULL;
    // 初始化JNIEnv
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_FALSE;
    }
    // 找到需要动态动态注册的Jni类
    jclass jniClass = env->FindClass("com/codearms/maoqiqi/jni/JNIDemo");
    if (nullptr == jniClass) {
        return JNI_FALSE;
    }
    // 动态注册
    env->RegisterNatives(jniClass, nativeMethod, sizeof(JNINativeMethod) / sizeof(nativeMethod));
    // 返回JNI使用的版本
    return JNI_VERSION_1_6;
}

extern "C" JNIEXPORT jstring

JNICALL Java_com_codearms_maoqiqi_jni_JNIDemo_stringFromJNI(JNIEnv *env, jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}