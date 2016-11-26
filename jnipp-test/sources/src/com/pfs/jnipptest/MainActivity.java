package com.pfs.jnipptest;

import android.os.Bundle;
import android.app.Activity;

import nothing.R;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView( R.layout.main_layout );
    }

    static {
        System.loadLibrary( "jnipp-test" );
    }
}
