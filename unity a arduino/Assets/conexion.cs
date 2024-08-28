using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.IO.Ports;

public class conexion : MonoBehaviour
{

    public InputField m;

    SerialPort arduinoPort = new SerialPort("COM 8");
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

    public void btn ()
    {
        SendMessagetoArduino(m.text);
    }
    public void ClosePort()
    {
        arduinoPort.Close();  
    }
}
