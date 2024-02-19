package com.github.zippozeng.xplayer.sample

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.wrapContentSize
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import com.github.zippozeng.xplayer.sample.theme.XPlayerDemoTheme
import com.github.zippozeng.xplayer.sdk.XPlayer

class MainActivity : ComponentActivity() {

    private var player = XPlayer()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            XPlayerDemoTheme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    Greeting("Android", Modifier.wrapContentSize())
                }
            }
        }
    }

    @Composable
    fun Greeting(name: String, modifier: Modifier = Modifier) {
        Button(onClick = { play() }, modifier = modifier) {
            Text("Hello $name!")
        }
    }

    @Preview(showBackground = true)
    @Composable
    fun GreetingPreview() {
        XPlayerDemoTheme {
            Greeting("Android")
        }
    }

    private fun play() {
        player.setDataSource("/sdcard/Download/267_1689433415.mp4")
        player.prepare()
        player.start()
    }
}