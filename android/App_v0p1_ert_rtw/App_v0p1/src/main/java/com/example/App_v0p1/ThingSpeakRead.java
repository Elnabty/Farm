package com.example.App_v0p1;

import org.json.JSONException;
import org.json.JSONObject;
import android.util.Log;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.io.IOException;
import java.net.UnknownHostException;
import java.util.ArrayList;import java.util.Hashtable;
import java.util.Timer;
import java.util.TimerTask;
import java.net.MalformedURLException;
import android.content.Context;
import android.os.AsyncTask;
import java.util.Set;
import android.text.TextUtils;
public class ThingSpeakRead {
   private static final int NUM_FIELDS = 8;
   ArrayList<Integer> mList = new ArrayList<Integer>(8);   private static final String SERVER = "http://api.thingspeak.com";
   
   private int channelID;
   private String readAPIKey;
   private SectionsPagerAdapter mSectionsPagerAdapter;
   private LogFragment mLogFragment;   String mGenericError="";

   class FieldData {
       float value;
       float ResponseCode;
       public FieldData() {
           value = 0;
           ResponseCode = 0;
       }
   }

   FieldData[]  mFielddata = new FieldData[NUM_FIELDS];
   Timer mtimer = null;
   TimerTask timerTask = null;
   URL mUrl;
   long mSampleTime;
   boolean mAsynctaskStart = false;

   class MyTimerTask extends TimerTask{
      public void run() {
          String s="";
           String inputLine;
           HttpURLConnection conn = null;
           StringBuilder response = new StringBuilder("");
           try {
                conn = (HttpURLConnection) mUrl.openConnection();
                conn.setDoInput(true);
                conn.setRequestMethod("GET");
                conn.setRequestProperty("Content-Type", "application/json");
                conn.connect();
                mAsynctaskStart = true;
                int v = conn.getResponseCode();
                if (v == HttpURLConnection.HTTP_OK) {
                    InputStreamReader streamReader = new InputStreamReader(conn.getInputStream());
                    BufferedReader reader = new BufferedReader(streamReader);
                    StringBuilder stringBuilder = new StringBuilder();
                    while ((inputLine = reader.readLine()) != null) {
                        stringBuilder.append(inputLine);
                   }
                    reader.close();
                    streamReader.close();
                    String result = stringBuilder.toString();
                    for (int i = 0; i < NUM_FIELDS; i++) {
                        String searchField = "field" + (i + 1);
                        if (result.contains(searchField)) {
                            JSONObject jObj = new JSONObject(result);
                            String totalItems = jObj.getString(searchField);
                            if (totalItems != null && !totalItems.equals("null")) {
                                mFielddata[i].value = Float.valueOf(totalItems);
                                mFielddata[i].ResponseCode = 200;
                            } else {
                                  mFielddata[i].value = 0;
                                  mFielddata[i].ResponseCode = 0;
                              }
                        }
                   }
             } else {
                 setAllFieldValues(0,v);
            }
            switch (v) {
                case HttpURLConnection.HTTP_OK:
                    s ="";
                    break;
                case HttpURLConnection.HTTP_UNAUTHORIZED:
                    s = "ThingSpeakRead : Error : HTTP Error 401: Authentication error.Check your Write API Key  and Channel id.";
                    break;
                case HttpURLConnection.HTTP_NOT_FOUND:
                    s ="ThingSpeakRead : Error : HTTP Error 404: The page you requested does not exist.Check the URL and redeploy the model.";
                    break;
                case 429:
                    s ="ThingSpeakRead  : Error : HTTP Error 429: Too many requests made to the server.Increase update interval in the block and redeploy the model.";
                    break;
                case HttpURLConnection.HTTP_BAD_REQUEST:
                    if(readAPIKey != null)
                         s = "ThingSpeakRead : Error :  Either Channel ID " + channelID + "or ReadAPIkey " + readAPIKey + " is wrong";
                    else
                         s = "ThingSpeakRead : Error :  Channel ID " + channelID + " is wrong";
                    break;
                default:
                     s ="ThingSpeakRead : Error: An unexpected error has occurred with HTTP response code " + v +".";
            }
           conn.disconnect();
           conn = null;
           } catch (java.net.UnknownHostException ex){
               setAllFieldValues(0,0);
               s = "ThingSpeakRead : Error: Unable to connect to server. Check device network connection, Server IP address and redeploy the model.";
           } catch (java.io.FileNotFoundException ex){
                setAllFieldValues(0,0);
                s = "ThingSpeakRead : Error :  Either Channel ID " + channelID + "or ReadAPIkey " + readAPIKey + " is wrong";
           } catch (Exception ex){
                setAllFieldValues(0,0);
                s = "ThingSpeakRead : Error : "+ex.getMessage();
           } finally {
                if (conn != null)
                   conn.disconnect();
           }
           if((!TextUtils.isEmpty(s))&&(!s.equals(mGenericError))) {
               mGenericError = s;
               updateLogTab(s);
          }
      }
   }

   void setAllFieldValues(float value, float responseCode) {
       for (int i = 0; i < NUM_FIELDS; i++) {
          mFielddata[i].value = value;
          mFielddata[i].ResponseCode = responseCode;
       }
   }

   public ThingSpeakRead(int channelID, String readAPIKey, int field, Context context, SectionsPagerAdapter sectionsPagerAdapter) {
      this.channelID = channelID;
      this.readAPIKey = readAPIKey;
      this.mSectionsPagerAdapter = sectionsPagerAdapter;
      mList.add(field);
      for(int j=0;j<NUM_FIELDS;j++){
         mFielddata[j] = new FieldData();
      }
      int id = context.getResources().getIdentifier("a_"+channelID,"string",context.getPackageName());
      String sampleTime =  context.getResources().getString(id);
      float f = Float.parseFloat(sampleTime);
      f = (f*1000)/2;
      mSampleTime = (long)f;
      try {
         if (this.readAPIKey != null)
            this.mUrl = new URL(SERVER + "/channels/" + this.channelID + "/feeds/last.json?api_key=" + this.readAPIKey);
         else
            this.mUrl = new URL(SERVER + "/channels/" + this.channelID + "/feeds/last.json");
      } catch(MalformedURLException ex) {}
      mtimer = new Timer();
      mtimer.scheduleAtFixedRate(new MyTimerTask(),(long)0,mSampleTime);
   }

   private int successCount = 1;
   
   public int getChannelID() { return channelID; }
   
   public void setChannelID(int channelID) { this.channelID = channelID; }
   
   public void setReadAPIKey(String readAPIKey) { this.readAPIKey = readAPIKey; }

   public void addField(int field) { mList.add(field);
}
   public float[] readData(int channelID, int field) {
      if(field >0 &&field < 9){
         float[] f = new float[2];
         if(mFielddata[field - 1]!= null) {
            f[0] = mFielddata[field - 1].value;
            f[1] = mFielddata[field - 1].ResponseCode;
            if(f[1] == HttpURLConnection.HTTP_OK) {
                updateLogTab("ThingSpeakRead : Success: Read data from ThingSpeak server");
            }
         }
         if(mAsynctaskStart && f[1] ==0 && TextUtils.isEmpty(mGenericError)){
             updateLogTab("ThingSpeakRead : Error : " +"Channel " + channelID + " does not contain field " + field);
         }
         return f;         }
    return null;
    }

    public void cancelTimer() {
        if(mtimer != null)
            mtimer.cancel();
    }

    private synchronized void updateLogTab(String LogText) {
        if(mLogFragment == null && mSectionsPagerAdapter !=null && mSectionsPagerAdapter.getLogFragment() != null) {
           mLogFragment =  (LogFragment) mSectionsPagerAdapter.getLogFragment();
        }
        mLogFragment.updateThingSpeakLogforReadBlock(LogText);
   }

}
