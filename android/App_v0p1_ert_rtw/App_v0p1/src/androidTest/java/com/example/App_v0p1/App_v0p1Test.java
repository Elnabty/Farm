package com.example.App_v0p1;

import android.test.ActivityInstrumentationTestCase2;

/**
 * This is a simple framework for a test of an Application.  See
 * {@link android.test.ApplicationTestCase ApplicationTestCase} for more information on
 * how to write and extend Application tests.
 * <p/>
 * To run this test, you can type:
 * adb shell am instrument -w \
 * -e class com.example.App_v0p1.App_v0p1Test \
 * com.example.App_v0p1.tests/android.test.InstrumentationTestRunner
 */
public class App_v0p1Test extends ActivityInstrumentationTestCase2<App_v0p1> {

    public App_v0p1Test() {
        super("com.example.App_v0p1", App_v0p1.class);
    }

}
