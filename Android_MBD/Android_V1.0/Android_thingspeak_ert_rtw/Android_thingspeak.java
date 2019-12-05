package com.example.Android_thingspeak;

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
import android.view.View;
import android.widget.ToggleButton;
import android.widget.TextView;
import android.widget.EditText;
import java.nio.charset.Charset;
import java.util.Arrays;
import android.text.InputFilter;
import android.view.KeyEvent;
import android.view.inputmethod.EditorInfo;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.HashMap;

public class Android_thingspeak extends AppCompatActivity implements OnFragmentInteractionListener{
    private SectionsPagerAdapter mSectionsPagerAdapter;

    private ViewPager mViewPager;
     private Hashtable<Integer,Float> buttonStates = new Hashtable<Integer,Float>();
     private Hashtable<Integer,TextView> textViews = new Hashtable<Integer,TextView>();
     private Hashtable<Integer,EditText> editTexts = new Hashtable<Integer,EditText>();
     private Hashtable<Integer, Double> editTextValues = new Hashtable<>();
     private Hashtable<Integer, String> editTextCharValues = new Hashtable<>();
     private Hashtable<Integer, ThingSpeakWrite> thingSpeakBlocks = new Hashtable<>();
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

    private Android_thingspeak thisClass;
    private final Thread BgThread = new Thread() {
    @Override
    public void run() {
            String argv[] = new String[] {"MainActivity","Android_thingspeak"};
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
   public void initThingSpeakConnection(int id, int channelID, String writeAPIKey, double updateInterval) {
       ThingSpeakWrite thingSpeakWrite = new ThingSpeakWrite();
       thingSpeakWrite.setChannelID(channelID);
       thingSpeakWrite.setWriteAPIKey(writeAPIKey);
       thingSpeakWrite.setUpdateInterval(updateInterval);
       thingSpeakBlocks.put(id, thingSpeakWrite);
   }

   public int checkUpdateInterval(int id) {
       ThingSpeakWrite thingSpeakWrite = thingSpeakBlocks.get(id);
       return (thingSpeakWrite.isSafeToPost() ? 1 : 0);
   }

   public void addField(int id, int field, double value) {
       ThingSpeakWrite thingSpeakWrite = thingSpeakBlocks.get(id);
       thingSpeakWrite.addField(field, value);
   }

   public void addLocation(int id, double[] location) {
       ThingSpeakWrite thingSpeakWrite = thingSpeakBlocks.get(id);
       thingSpeakWrite.addLocation(location);
   }

   public void sendPostRequest(int id) {
       ThingSpeakWrite thingSpeakWrite = thingSpeakBlocks.get(id);
       String response = thingSpeakWrite.sendPostRequest();

       LogFragment lf =  (LogFragment) mSectionsPagerAdapter.getLogFragment();
       lf.updateLog(response);
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
                registerDataInputs();
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
                for (int i=1;i<=4;i++) {
                    registerButtonFcn(i);
                }
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
    public void registerDataInputs() {
        // bind edit texts for data input block;
        for (int i = 1; i <= 4; i++) {
            EditText editText = (EditText) findViewById(
                    getResources().getIdentifier("DataInput" + i, "id", getPackageName()));
            if (editTextValues.containsKey(i)) {
                Log.d("registerDataInputs", "id:" + i);
                editText.setText(editTextValues.get(i).toString());
            }
            if (editTextCharValues.containsKey(i)) {
                editText.setText(editTextCharValues.get(i));
            }
            String tag = (String) editText.getTag();
            int dataType = -1;
            if (tag == null) {
                dataType = -1;
            } else {
                try {
                    dataType = Integer.parseInt(tag);
                }catch (NumberFormatException nfe) {
                    Log.e("registerDataInputs", nfe.getLocalizedMessage());
                    dataType = -1;
                }
            }
            final int id = i;
            if (dataType > 0) {
                editText.setFilters(new InputFilter[]{new InputFilterMinMax(dataType)});
                editText.setOnEditorActionListener(new TextView.OnEditorActionListener() {
                    @Override
                    public boolean onEditorAction(TextView textView, int actionId, KeyEvent keyEvent) {
                        if ((actionId == EditorInfo.IME_ACTION_NEXT) || (actionId == EditorInfo.IME_ACTION_DONE) || (keyEvent != null && (keyEvent.getKeyCode() == KeyEvent.KEYCODE_ENTER))) {
                            try {
                                String text = textView.getText().toString();
                                double returnValue = Double.parseDouble(text);
                                editTextValues.put(id, returnValue);
                            } catch (Exception ignored) {
                                editTextValues.put(id, 0.0);
                            }
                        }
                        return false;
                    }
                });
            } else {
                editText.setOnEditorActionListener(new TextView.OnEditorActionListener() {
                    @Override
                    public boolean onEditorAction(TextView textView, int actionId, KeyEvent keyEvent) {
                        if ((actionId == EditorInfo.IME_ACTION_NEXT) || (actionId == EditorInfo.IME_ACTION_DONE) || (keyEvent != null && (keyEvent.getKeyCode() == KeyEvent.KEYCODE_ENTER))) {
                            editTextCharValues.put(id, textView.getText().toString());
                        }
                        return false;
                    }
                });
            }
            editTexts.put(i, editText);
        }
    }
    public void registerButtonFcn(int id) {
        String buttonid     = "button"+id;
        final ToggleButton button = (ToggleButton)findViewById(getResources().getIdentifier(buttonid, "id", getPackageName()));
        if (null == button)
            return;
        setButtonState(button);
        button.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
                setButtonState(button);
			}
		});
    }

    // update the hash table with button id and state
    public void setButtonState(ToggleButton button) {
    	if(button.isChecked()) {
            buttonStates.put(button.getId(),1.0f);
		} else {
            buttonStates.put(button.getId(),0.0f);
		}
    }

    public float getButtonState(int id) {
        String buttonid = "button"+id;
        Float buttonState = buttonStates.get(getResources().getIdentifier(buttonid, "id", getPackageName()));
        return buttonState == null?-1:buttonState.floatValue();
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
                    Log.e("Android_thingspeak.updateTextViewById", ex.getLocalizedMessage());
                }
            }
        });
    }

    public void initDataInput(final int id, final double value, final int dataType) {
        editTextValues.put(id, value);
        if (editTexts.containsKey(id)) {
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    String str = "";
                    if (dataType == 5 ) {
                        str = String.format("%.0f",value);
                    } else if (dataType == 7) {
                        str = String.format("%.6f",value);
                    } else if (dataType == 8) {
                        str = String.format("%.13f",value);
                    } else {
                        str = String.format("%d",(int)value);
                    }
                    editTexts.get(id).setText(str);
                }
            });
        }
    }

    public void initDataInput(final int id, byte[] value) {
        final String initValue = new String(value);
        editTextCharValues.put(id,initValue);
        if (editTextCharValues.containsKey(id)) {
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    editTexts.get(id).setText(initValue);
                }
            });
        }
    }


    public double getDataInputValue(int id) {
        return editTextValues.containsKey(id)? editTextValues.get(id) :0.0;
    }
    public byte[] getDataInputValue(int id, int maxSize) {
        String text = editTextCharValues.containsKey(id)?editTextCharValues.get(id):"";
        byte [] returnValue = Arrays.copyOf(text.getBytes(Charset.defaultCharset()),maxSize);
        return returnValue;
    }

    private native int naMain(String[] argv, Android_thingspeak pThis);
    private native void naOnAppStateChange(int state);
    static {
        System.loadLibrary("Android_thingspeak");
    }

}
