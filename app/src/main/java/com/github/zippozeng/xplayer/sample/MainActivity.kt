package com.github.zippozeng.xplayer.sample

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.github.zippozeng.xplayer.sample.databinding.ActivityMainBinding
import com.github.zippozeng.xplayer.sdk.XPlayer

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    private val player = XPlayer();

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        player.setDataSource("hello world")
        player.prepare()
        player.start()
        // Example of a call to a native method
    }


}