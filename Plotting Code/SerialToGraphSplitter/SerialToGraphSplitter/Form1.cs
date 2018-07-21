using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Windows.Forms;
using System.Threading;

namespace SerialToGraphSplitter
{
    public partial class Form1 : Form
    {
        private SerialPort port = new SerialPort();
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void ClosePort()
        {
            Thread.Sleep(5000);
            port.Close();
            while (true) ;
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            textTime.Text += "";
            textXAcc.Text += "";
            textYAcc.Text += "";
            textAccZ.Text += "";
            textZPower.Text += "";
            textXServo.Text += "";
            textYServo.Text += "";
            int initalTime = 0;
            port.PortName = SerialPort.GetPortNames()[0];
            port.BaudRate = 57600;
            port.Parity = Parity.None;
            //port.StopBits = StopBits.None;
            port.Open();
            Thread stopper = new Thread(ClosePort);
            //stopper.Start();
            string rawInput = "";
            Console.WriteLine("OPEENED");
            bool going = true;
            long initial = DateTime.Now.Ticks / TimeSpan.TicksPerMillisecond;

            while (DateTime.Now.Ticks / TimeSpan.TicksPerMillisecond - initial < 8000) 
            {
                rawInput += Convert.ToChar(port.ReadChar()).ToString();
                going = port.IsOpen;
            }
            port.Close();
            //string rawInput = richTextBoxInital.Text;
            string[] largeArray = rawInput.Split('^');
            // all the -1 is because there is a null addition of ^ at the end
            string[] time = new string[largeArray.Length - 1];
            string[] XAcc = new string[largeArray.Length - 1];
            string[] YAcc = new string[largeArray.Length - 1];
            string[] ZAcc = new string[largeArray.Length - 1];
            string[] XServo = new string[largeArray.Length - 1];
            string[] YServo = new string[largeArray.Length - 1];
            string[] ZPower = new string[largeArray.Length - 1];

            for(int i = 3; i < largeArray.Length - 1; i++)
            {
                if (i == 3)
                {
                    textTime.Text += "[";
                    textXAcc.Text += "[";
                    textYAcc.Text += "[";
                    textAccZ.Text += "[";
                    textZPower.Text += "[";
                    textXServo.Text += "[";
                    textYServo.Text += "[";
                    initalTime = Convert.ToInt32(largeArray[i].Split('|')[0]);
                }

                string[] splitted = largeArray[i].Split('|');
                time[i] = (Convert.ToInt32(splitted[0]) - initalTime).ToString();
                XAcc[i] = splitted[1];
                YAcc[i] = splitted[2];
                ZAcc[i] = splitted[3];
                XServo[i] = splitted[4];
                YServo[i] = splitted[5];
                ZPower[i] = splitted[6];

                
                textTime.Text += time[i];
                textXAcc.Text += XAcc[i];
                textYAcc.Text += YAcc[i];
                textAccZ.Text += ZAcc[i];
                textZPower.Text += ZPower[i];
                textXServo.Text += XServo[i];
                textYServo.Text += YServo[i];

                if(i < largeArray.Length - 2)
                {
                    textTime.Text += ",";
                    textXAcc.Text += ",";
                    textYAcc.Text += ",";
                    textAccZ.Text += ",";
                    textZPower.Text += ",";
                    textXServo.Text += ",";
                    textYServo.Text += ",";
                }


            }
            textTime.Text += "]";
            textXAcc.Text += "]";
            textYAcc.Text += "]";
            textAccZ.Text += "]";
            textZPower.Text += "]";
            textXServo.Text += "]";
            textYServo.Text += "]";
        }
    }
}
