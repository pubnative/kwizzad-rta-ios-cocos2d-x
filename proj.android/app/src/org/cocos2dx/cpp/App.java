package org.cocos2dx.cpp;

import android.app.Application;

import com.kwizzad.rta.KwizzadRta;

public class App extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        KwizzadRta.Companion.initialize(this);
    }
}
