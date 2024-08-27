using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class conexion : MonoBehaviour
{
    SerialPort arduinoPort = new SerialPort("COM 4");

    private void Awake()
    {
        arduinoPort.BaudRate = 9600;
        arduinoPort.Parity = Parity.None;
        arduinoPort.StopBits = StopBits.One;
        arduinoPort.DataBits = 8;
        arduinoPort.Handshake = Handshake.None;
    }

    void Start()
    {

        arduinoPort.Open();

    }

    public void SendMessagetoArduino (string msg)
    {
        arduinoPort.WriteLine(msg);
    }

    public void ClosePort()
    {
        arduinoPort.Close();  
    }
}
