package com.github.zippozeng.xplayer.sdk

/**
 * Created by zippo on 2023/7/15.
 * Date: 2023/7/15
 * Time: 16:49
 */
class XPlayer : IXPlayer {

    companion object {
        init {
            System.loadLibrary("xplayer")
        }
    }

    private var mNativeContext: Long = -1

    init {
        mNativeContext = native_setup()
    }

    override fun setDataSource(path: String) {
        _setDataSource(mNativeContext, path)
    }

    override fun isLooping(): Boolean {
        return _isLooping(mNativeContext)
    }

    override fun setLooping(looping: Boolean) {
        _setLooping(mNativeContext, looping)
    }

    override fun prepare() {
        _prepare(mNativeContext)
    }

    override fun start() {
        _start(mNativeContext)
    }

    override fun stop() {
        _stop(mNativeContext)
    }

    override fun pause() {
        _pause(mNativeContext)
    }

    private external fun native_setup(): Long
    private external fun _setDataSource(nativeContext: Long, path: String)
    private external fun _prepare(nativeContext: Long)
    private external fun _start(nativeContext: Long)
    private external fun _stop(nativeContext: Long)
    private external fun _pause(nativeContext: Long)
    private external fun _seekTo(nativeContext: Long, duration: Long, mode: Int)
    private external fun _isLooping(nativeContext: Long): Boolean
    private external fun _setLooping(nativeContext: Long, looping: Boolean)
}