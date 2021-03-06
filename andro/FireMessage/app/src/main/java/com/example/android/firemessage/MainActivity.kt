package com.example.android.firemessage

import android.app.Fragment
import android.os.Bundle
import android.support.design.widget.BottomNavigationView
import android.support.v7.app.AppCompatActivity
import android.support.v7.app.AppCompatDialogFragment
import com.example.android.firemessage.fragment.MyAccountFragment
import com.example.android.firemessage.fragment.PeopleFragment
import kotlinx.android.synthetic.main.activity_main.*
import org.jetbrains.anko.Android

class MainActivity : AppCompatActivity() {



    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        replaceFragment(PeopleFragment())

        navigation.setOnNavigationItemSelectedListener{
            when (it.itemId){
                R.id.navigation_people ->{
                    replaceFragment(PeopleFragment())
                    true
                }
                R.id.navigation_my_account ->{
                    replaceFragment(MyAccountFragment())
                    true
                }
                else -> {
                    false
                }
            }
        }
    }

    private fun replaceFragment(fragment: android.support.v4.app.Fragment){
        supportFragmentManager.beginTransaction()
                .replace(R.id.fragment_layout, fragment)
                .commit()
    }
}
