package com.codearms.maoqiqi.jni

class JNIDemo {

    companion object {
        init {
            System.loadLibrary("jni")
        }
    }

    external fun stringFromJNI(): String

    external fun dynamicMethod(name: String): String
}