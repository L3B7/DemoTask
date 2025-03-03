package com.example.seontask;

import android.os.Bundle;
import android.util.Log;
import android.util.Pair;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    private NativeLib nativeLib;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        nativeLib = new NativeLib();
        // Log test
/*        String input = "key1=value1;key2=value2;key3=value3";
        ArrayList<Pair<String, String>> parsedData = nativeLib.parseString(input);
        Log.d("MainActivity", "Parsed data: " + parsedData);*/


        EditText inputEditText = findViewById(R.id.inputEditText);
        TextView outputTextView = findViewById(R.id.outputTextView);
        Button convertButton = findViewById(R.id.convertButton);
        convertButton.setOnClickListener(v -> {
            inputEditText.setEnabled(false);
            convertButton.setEnabled(false);
            String input = inputEditText.getText().toString();
            new Thread(() -> {
                ArrayList<Pair<String, String>> parsedData = new ArrayList<>();
                StringBuilder output = new StringBuilder();
                try{
                    parsedData = nativeLib.parseString(input);
                } catch (Exception e) {
                    Log.e("MainActivity", "Error parsing input", e);
                    output.append("Error parsing input: ").append(e.getMessage()).append("\n");
                }
                if(parsedData.isEmpty()) {
                    output.append("No data parsed\n");
                }else {
                    for (Pair<String, String> pair : parsedData) {
                        output.append(pair.first).append(" = ").append(pair.second).append("\n");
                    }
                }

                runOnUiThread(() -> {
                    outputTextView.setText(output.toString());
                    inputEditText.setEnabled(true);
                    convertButton.setEnabled(true);
                });
            }).start();
        });




    }
}
