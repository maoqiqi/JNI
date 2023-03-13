package com.codearms.maoqiqi.jni

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.codearms.maoqiqi.jni.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private val jniDemo by lazy { JNIDemo() }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = jniDemo.stringFromJNI()
    }
}