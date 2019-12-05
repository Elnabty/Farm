package com.example.App_v0p1;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;
import android.util.Log;
import java.util.ArrayList;
import android.content.res.Configuration;
import android.support.design.widget.TabLayout;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.widget.TextView;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.HashMap;

public class App_v0p1 extends AppCompatActivity implements OnFragmentInteractionListener{
    private SectionsPagerAdapter mSectionsPagerAdapter;

    private ViewPager mViewPager;
     private Hashtable<Integer,TextView> textViews = new Hashtable<Integer,TextView>();
     private Hashtable<Integer, ThingSpeakRead> thingSpeakReadBlocks = new Hashtable<>();

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        //Uncomment the following line to specify a custom App Title
        //toolbar.setTitle("My custom Title");
        setSupportActionBar(toolbar);

        // Create a FragmentPagerAdapter that returns individual fragments
        mSectionsPagerAdapter = new SectionsPagerAdapter(getSupportFragmentManager());

        // Set up the ViewPager with the sections adapter.
        mViewPager = (ViewPager) findViewById(R.id.container);
        mViewPager.setAdapter(mSectionsPagerAdapter);
        mViewPager.setOffscreenPageLimit(SectionsPagerAdapter.getNumTabs()-1);

        TabLayout tabLayout = (TabLayout) findViewById(R.id.tabs);
        tabLayout.setupWithViewPager(mViewPager);

        thisClass = this;
     }

    private App_v0p1 thisClass;
    private final Thread BgThread = new Thread() {
    @Override
    public void run() {
            String argv[] = new String[] {"MainActivity","App_v0p1"};
            naMain(argv, thisClass);
        }
    };

    public void flashMessage(final String inMessage) {
        runOnUiThread(new Runnable() {
              public void run() {
                    Toast.makeText(getBaseContext(), inMessage, Toast.LENGTH_SHORT).show();
              }
        });
    }

    protected void onDestroy() {
         naOnAppStateChange(6);
        Iterator it = thingSpeakReadBlocks.entrySet().iterator();
        while (it.hasNext()) {
            HashMap.Entry pair = (HashMap.Entry)it.next();
            ThingSpeakRead tsR  = (ThingSpeakRead) pair.getValue();
            tsR.cancelTimer();
        }
         super.onDestroy();
         System.exit(0); //to kill all our threads.
    }

   //Methods for ThingSpeak Write block
   public void initThingSpeakReadConnection(int channelID, String readAPIKey, int field) {
       if (!thingSpeakReadBlocks.containsKey(channelID)) {
            ThingSpeakRead thingSpeakWrite = new ThingSpeakRead(channelID,readAPIKey, field, this,mSectionsPagerAdapter);
            thingSpeakWrite.setChannelID(channelID);
            thingSpeakWrite.setReadAPIKey(readAPIKey);
            thingSpeakReadBlocks.put(channelID, thingSpeakWrite);
       } else{
             ThingSpeakRead tsR = thingSpeakReadBlocks.get(channelID);
             if (tsR != null) {
                  tsR.addField(field);
             }
       }
   }
   public float[] readThingSpeakData(int channelid, int field) {
       ThingSpeakRead thingSpeakRead = thingSpeakReadBlocks.get(channelid);
       if( thingSpeakRead != null){
           float[] f =  thingSpeakRead.readData(channelid, field);
           return f;
       }else
           return new float[]{0,0};   }

	@Override
    public void onFragmentCreate(String name) {

    }

    @Override
    public void onFragmentStart(String name) {
        switch (name) {
            case "Info":
               break;
            case "App":
                registerDataDisplays();
                if (!BgThread.isAlive()) {
                    BgThread.start();
                }
                break;
            default:
                break;
    }
    }

    @Override
    public void onFragmentResume(String name) {
        switch (name) {
            case "App":
                break;
            default:
                break;
        }
    }

    @Override
    public void onFragmentPause(String name) {
    }
    @Override
    protected void onResume() {
         super.onResume();
         if (BgThread.isAlive())
             naOnAppStateChange(3);
    }

    @Override
    protected void onPause() {
        if (BgThread.isAlive())
            naOnAppStateChange(4);
        super.onPause();
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }

    public void registerDataDisplays() {
    // bind text views for data display block;
    for (int i = 1; i <= 3; i++) {
            TextView textView = (TextView) findViewById(
            getResources().getIdentifier("DataDisplay" + i, "id", getPackageName()));
            textViews.put(i, textView);
        }
    }
    public void displayText(int id, byte[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, short[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, int[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, long[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, float[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, double[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    private void updateTextViewById(final int id, final String finalStringToDisplay) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                try {
                    textViews.get(id).setText(finalStringToDisplay);
                } catch (Exception ex) {
                    Log.e("App_v0p1.updateTextViewById", ex.getLocalizedMessage());
                }
            }
        });
    }
    private native int naMain(String[] argv, App_v0p1 pThis);
    private native void naOnAppStateChange(int state);
    static {
        System.loadLibrary("App_v0p1");
    }

}
