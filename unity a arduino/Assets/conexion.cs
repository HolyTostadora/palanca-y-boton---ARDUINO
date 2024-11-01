﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.IO.Ports;

public class conexion : MonoBehaviour
{
    SerialPort arduinoPort = new SerialPort("COM9", 9600); // Corrected port name format

    public string id;
    public string[] prueba;

    private void Awake()
    {
        // Set the serial port properties
        arduinoPort.Parity = Parity.None;
        arduinoPort.StopBits = StopBits.One;
        arduinoPort.DataBits = 8;
        arduinoPort.Handshake = Handshake.None;
    }

    void Start()
    {
        // Open the serial port in Start()
        try
        {
            if (!arduinoPort.IsOpen) // Check if the port is already open
            {
                arduinoPort.Open();
                Debug.Log("Serial Port Opened");
            }
        }
        catch (System.Exception e)
        {
            Debug.LogError("Failed to open serial port: " + e.Message);
        }


    }

    private void Update()
    {
        
        if(Input.GetKeyDown(KeyCode.Return))
        {
            SendMessagestoArduino(id, prueba);
        }

    }

    public void SendMessagestoArduino(string identifier, string[] messages){
    if (arduinoPort.IsOpen)
    {
        try
        {
                string msg2send = identifier + "," + string.Join(",", messages);
                arduinoPort.WriteLine(msg2send);
                Debug.Log(msg2send);
        }
        catch (System.Exception e)
        {
            Debug.LogError("Failed to send message to Arduino: " + e.Message);
        }
    }
    else
    {
        Debug.LogWarning("Serial port is not open.");
    }
    }



    public void ClosePort()
    {
        if (arduinoPort.IsOpen)
        {
            arduinoPort.Close();
            Debug.Log("Serial Port Closed");
        }
        else
        {
            Debug.LogWarning("Serial port is already closed.");
        }
    }

    private void OnApplicationQuit()
    {
        ClosePort(); // Close the port when the application quits
    }
}
