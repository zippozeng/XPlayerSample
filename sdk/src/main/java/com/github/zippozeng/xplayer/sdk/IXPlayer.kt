package com.github.zippozeng.xplayer.sdk

/**
 * Created by zippo on 2023/7/15.
 * Date: 2023/7/15
 * Time: 16:49
 */
interface IXPlayer {

    fun setDataSource(path: String)
    fun isLooping(): Boolean
    fun setLooping(looping: Boolean)
    fun prepare();
    fun start()
    fun stop()
    fun pause()
}