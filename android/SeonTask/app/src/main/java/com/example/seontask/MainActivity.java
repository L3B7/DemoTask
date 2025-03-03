package com.example.seontask;

import android.os.Bundle;
import android.util.Log;
import android.util.Pair;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.io.File;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    private NativeLib nativeLib;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        nativeLib = new NativeLib();
        /* Log test
        String input = "key1=value1;key2=value2;key3=value3";
        ArrayList<Pair<String, String>> parsedData = nativeLib.parseString(input);
        Log.d("MainActivity", "Parsed data: " + parsedData);
         */

    }
}
