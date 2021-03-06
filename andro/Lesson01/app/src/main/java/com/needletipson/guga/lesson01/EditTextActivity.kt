package com.needletipson.guga.lesson01

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.text.Editable
import android.text.TextWatcher
import android.widget.Button
import android.widget.EditText
import android.widget.TextView

class EditTextActivity : AppCompatActivity() {

    private lateinit var editText: EditText
    private lateinit var result: TextView
    private lateinit var copy : Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_edit_text)

        editText = findViewById(R.id.editText)
        result = findViewById(R.id.tv_result)
        copy = findViewById(R.id.btn_copy)

        copy.setOnClickListener{
            result.text = editText.text
        }

        editText.addTextChangedListener(object : TextWatcher{
            override fun afterTextChanged(p0: Editable?) {

            }

            override fun beforeTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {

            }

            override fun onTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {
                result.text = p0
            }
        })
    }
}
