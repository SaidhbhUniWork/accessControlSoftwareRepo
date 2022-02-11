using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;

using System.Web.Script.Serialization;

namespace testInterface_v1._0
{
    public partial class Form1 : Form
    {
        class LoginDetails
        {
            public string uName;
            public string pWord;
        }

        TcpClient TcpClient;
        const int port = 54000;
        //Thread ListeningThread = null;
        LoginDetails loginDetails = new LoginDetails();

        public Form1()
        {
            InitializeComponent();

            string HostName = Dns.GetHostName();
            IPHostEntry IPInfo = Dns.GetHostEntry(HostName);

            foreach (IPAddress IP in IPInfo.AddressList)
            {
                if (IP.AddressFamily == AddressFamily.InterNetwork)
                {
                    cmb_myIP.Items.Add(IP);
                }
            }

            if (cmb_myIP.Items.Count > 0)
            {
                cmb_myIP.SelectedIndex = 0;
            }
            else
            {
                throw new Exception("No valid IP addresses located");
            }

        }

        private void Btn_Send_Click(object sender, EventArgs e)
        {
            loginDetails.uName = tb_uname.Text;
            loginDetails.pWord = tb_pword.Text;
            // Send message to the client

            JavaScriptSerializer Serializer = new JavaScriptSerializer();
            string JsonString = Serializer.Serialize(loginDetails);

            NetworkStream SendStream = TcpClient.GetStream();

            byte[] NewData = Encoding.ASCII.GetBytes(JsonString);

            SendStream.Write(NewData, 0, NewData.Length);

        }

        private void Btn_Connect_Click(object sender, EventArgs e)
        {

            TcpClient = new TcpClient();
            IPAddress IP = IPAddress.Parse(tb_otherIP.Text); // parse address from the textbox
            TcpClient.Connect(IP, port); // connecting to the ip address and port

            MessageBox.Show("Connected to : " + tb_otherIP.Text);

        }

    }
}
