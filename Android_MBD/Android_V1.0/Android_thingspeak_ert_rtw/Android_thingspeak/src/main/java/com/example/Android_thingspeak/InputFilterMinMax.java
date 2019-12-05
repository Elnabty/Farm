package com.example.Android_thingspeak;

import android.text.InputFilter;
import android.text.Spanned;
import android.util.Log;

/**
 * Copyright 2017 The MathWorks, Inc.
 */

public class InputFilterMinMax implements InputFilter {

    private static final int uint8_max = 255;
    private static final int uint8_min = 0;
    private static final int int8_max = Byte.MAX_VALUE;
    private static final int int8_min = Byte.MIN_VALUE;
    private static final int uint16_max = 65535;
    private static final int uint16_min = 0;
    private static final int int16_max = Short.MAX_VALUE;
    private static final int int16_min = Short.MIN_VALUE;
    private static final double uint32_max = 4294967295.0;
    private static final int uint32_min = 0;
    private static final int int32_max = Integer.MAX_VALUE;
    private static final int int32_min = Integer.MIN_VALUE;
    private static final double single_max = Float.POSITIVE_INFINITY;
    private static final double single_min = Float.NEGATIVE_INFINITY;
    private static final String TAG = "InputFilterMinMax";
    private int dataType;

    public InputFilterMinMax(int dataType) {
        this.dataType = dataType;
    }

    @Override
    public CharSequence filter(CharSequence source, int start, int end, Spanned dest, int dstart, int dend) {
        try {
            String replacement = source.subSequence(start, end).toString();
            String newVal = dest.subSequence(0, dstart).toString() + replacement + dest.subSequence(dend, dest.length()).toString();
            Double input = Double.parseDouble(newVal);

            if (Double.isInfinite(input))
                Log.w(TAG, "Entered value is out of range.");
            else if (isInRange(input))
                return null;
            else
                return "";
        } catch (NumberFormatException nfe) {
            Log.w(TAG, nfe.getLocalizedMessage());
        }
        return "";
    }

    private boolean isInRange(double c) {
        switch (this.dataType) {
            case 1:
                return c >= uint8_min && c <= uint8_max;
            case 2:
                return c >= int8_min && c <= int8_max;
            case 3:
                return c >= uint16_min && c <= uint16_max;
            case 4:
                return c >= int16_min && c <= int16_max;
            case 5:
                return c >= uint32_min && c <= uint32_max;
            case 6:
                return c >= int32_min && c <= int32_max;
            case 7:
                return c > single_min && c < single_max;
            case 8:
                return c > Double.NEGATIVE_INFINITY && c < Double.POSITIVE_INFINITY;
            default:
                return false;
        }
    }
}