/****************************************************************************
Copyright (c) 2015-2016 Chukong Technologies Inc.
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import android.app.Activity;
import android.os.Bundle;
import org.cocos2dx.lib.Cocos2dxActivity;
import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

import android.os.Build;
import android.view.WindowManager;
import android.view.WindowManager.LayoutParams;
import android.widget.Toast;

import com.kwizzad.adsbase.AdOpportunity;
import com.kwizzad.rta.AdCallback;
import com.kwizzad.rta.KwizzadRta;
import com.kwizzad.rta.debug.KwizzadDebugActivity;
import com.kwizzad.rta.show.AdParams;

public class AppActivity extends Cocos2dxActivity {

    private static KwizzadRta rta;
    private static Activity activityRef; //not the best idea to keep activity in static field, but for example app it is ok

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.setEnableVirtualButton(false);
        super.onCreate(savedInstanceState);
        // Workaround in https://stackoverflow.com/questions/16283079/re-launch-of-activity-on-home-button-but-only-the-first-time/16447508
        if (!isTaskRoot()) {
            // Android launched another instance of the root activity into an existing task
            //  so just quietly finish and go away, dropping the user back into the activity
            //  at the top of the stack (ie: the last state of this task)
            // Don't need to finish it again since it's finished in super.onCreate .
            return;
        }
        // Make sure we're running on Pie or higher to change cutout mode
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            // Enable rendering into the cutout area
            WindowManager.LayoutParams lp = getWindow().getAttributes();
            lp.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            getWindow().setAttributes(lp);
        }
        // DO OTHER INITIALIZATION BELOW
        activityRef = this;
        initRta();
        loadRta();
    }

    private void initRta() {
        rta = KwizzadRta.Companion.create(this, "de.tvsmiles.app/rta_android");
        rta.identifyUser("cocos2d.example:3452462");
        rta.onCreate(this);
    }

    private void loadRta() {
        rta.addAdCallback(new AdCallback() {
            @Override
            public void onAdAvailable(boolean preloaded) {
                CBridge.notifyAdPreloadedState(preloaded);
            }

            @Override
            public void onAdFailedToLoad(@NotNull Throwable throwable) {
                showLog(throwable.getMessage());
            }

            @Override
            public void onAdOpened(@NotNull AdOpportunity adOpportunity) {
                showLog("onAdOpened: " + adOpportunity.toString());
            }

            @Override
            public void onAdFinished(@NotNull AdOpportunity adOpportunity) {
                showLog("onAdFinished: " + adOpportunity.toString());
            }

            @Override
            public void onAdError(@Nullable AdOpportunity adOpportunity, @NotNull Throwable throwable) {
                showLog("onAdError: " + adOpportunity.toString() + "\n" + throwable.getMessage());
            }

            @Override
            public void onAdCancelled(@NotNull AdOpportunity adOpportunity) {
                showLog("onAdCancelled: " + adOpportunity.toString());
            }
        });
        rta.load(this, "premium");
    }

    private void showLog(String str) {
        Toast.makeText(this, str, Toast.LENGTH_LONG).show();
    }


    private static void showRta() {
        rta.showAd(activityRef, new AdParams());
    }

    public static void showDebug() {
        KwizzadDebugActivity.Companion.show(activityRef, rta);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        rta.onDestroy(this);
        rta = null;
        activityRef = null;
    }
}
