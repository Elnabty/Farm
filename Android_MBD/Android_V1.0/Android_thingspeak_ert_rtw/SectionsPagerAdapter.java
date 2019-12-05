package com.example.Android_thingspeak;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;


class SectionsPagerAdapter extends FragmentPagerAdapter {

  private static final int NUMTABS = 3;
   private LogFragment logFragment;

   public Fragment getLogFragment() { return logFragment; }

   public static int getNumTabs() { return NUMTABS; }

    public SectionsPagerAdapter(FragmentManager fm) {
        super(fm);
    }

   @Override
    public Fragment getItem(int position) {
        switch (position) {
			case 0:  return AppFragment.newInstance();

			case 1:  return InfoFragment.newInstance();

			case 2:  logFragment = (LogFragment)LogFragment.newInstance();
					 return logFragment;
			default: return null;
		}
	}

    @Override
    public int getCount() { return NUMTABS; }

    @Override
    public CharSequence getPageTitle(int position) {
        switch (position) {

			case 0:  return "App";

			case 1:  return "Info";

			case 2:  return "Log";

			default: return null;
		}
	}

}