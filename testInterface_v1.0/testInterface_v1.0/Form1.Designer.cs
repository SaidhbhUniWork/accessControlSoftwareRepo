
namespace testInterface_v1._0
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lb_IP = new System.Windows.Forms.Label();
            this.tb_otherIP = new System.Windows.Forms.TextBox();
            this.tb_portNo = new System.Windows.Forms.TextBox();
            this.lbl_otherIP_header = new System.Windows.Forms.Label();
            this.lbl_otherIP_actual = new System.Windows.Forms.Label();
            this.lbl_portNO_actual = new System.Windows.Forms.Label();
            this.lbl_uname = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.tb_uname = new System.Windows.Forms.TextBox();
            this.tb_pword = new System.Windows.Forms.TextBox();
            this.cmb_myIP = new System.Windows.Forms.ComboBox();
            this.btn_listen = new System.Windows.Forms.Button();
            this.btn_sendLogins = new System.Windows.Forms.Button();
            this.btn_connect = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lb_IP
            // 
            this.lb_IP.AutoSize = true;
            this.lb_IP.Location = new System.Drawing.Point(93, 26);
            this.lb_IP.Name = "lb_IP";
            this.lb_IP.Size = new System.Drawing.Size(75, 13);
            this.lb_IP.TabIndex = 1;
            this.lb_IP.Text = "My IP Address";
            // 
            // tb_otherIP
            // 
            this.tb_otherIP.Location = new System.Drawing.Point(345, 45);
            this.tb_otherIP.Name = "tb_otherIP";
            this.tb_otherIP.Size = new System.Drawing.Size(100, 20);
            this.tb_otherIP.TabIndex = 2;
            // 
            // tb_portNo
            // 
            this.tb_portNo.Location = new System.Drawing.Point(345, 84);
            this.tb_portNo.Name = "tb_portNo";
            this.tb_portNo.Size = new System.Drawing.Size(100, 20);
            this.tb_portNo.TabIndex = 3;
            // 
            // lbl_otherIP_header
            // 
            this.lbl_otherIP_header.AutoSize = true;
            this.lbl_otherIP_header.Location = new System.Drawing.Point(345, 26);
            this.lbl_otherIP_header.Name = "lbl_otherIP_header";
            this.lbl_otherIP_header.Size = new System.Drawing.Size(82, 13);
            this.lbl_otherIP_header.TabIndex = 4;
            this.lbl_otherIP_header.Text = "Connection Info";
            // 
            // lbl_otherIP_actual
            // 
            this.lbl_otherIP_actual.AutoSize = true;
            this.lbl_otherIP_actual.Location = new System.Drawing.Point(274, 48);
            this.lbl_otherIP_actual.Name = "lbl_otherIP_actual";
            this.lbl_otherIP_actual.Size = new System.Drawing.Size(58, 13);
            this.lbl_otherIP_actual.TabIndex = 5;
            this.lbl_otherIP_actual.Text = "IP Address";
            // 
            // lbl_portNO_actual
            // 
            this.lbl_portNO_actual.AutoSize = true;
            this.lbl_portNO_actual.Location = new System.Drawing.Point(307, 87);
            this.lbl_portNO_actual.Name = "lbl_portNO_actual";
            this.lbl_portNO_actual.Size = new System.Drawing.Size(26, 13);
            this.lbl_portNO_actual.TabIndex = 6;
            this.lbl_portNO_actual.Text = "Port";
            // 
            // lbl_uname
            // 
            this.lbl_uname.AutoSize = true;
            this.lbl_uname.Location = new System.Drawing.Point(136, 211);
            this.lbl_uname.Name = "lbl_uname";
            this.lbl_uname.Size = new System.Drawing.Size(41, 13);
            this.lbl_uname.TabIndex = 7;
            this.lbl_uname.Text = "Name :";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(120, 251);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(62, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "Password : ";
            // 
            // tb_uname
            // 
            this.tb_uname.Location = new System.Drawing.Point(193, 208);
            this.tb_uname.Name = "tb_uname";
            this.tb_uname.Size = new System.Drawing.Size(100, 20);
            this.tb_uname.TabIndex = 9;
            // 
            // tb_pword
            // 
            this.tb_pword.Location = new System.Drawing.Point(193, 247);
            this.tb_pword.Name = "tb_pword";
            this.tb_pword.Size = new System.Drawing.Size(100, 20);
            this.tb_pword.TabIndex = 10;
            // 
            // cmb_myIP
            // 
            this.cmb_myIP.FormattingEnabled = true;
            this.cmb_myIP.Location = new System.Drawing.Point(96, 43);
            this.cmb_myIP.Name = "cmb_myIP";
            this.cmb_myIP.Size = new System.Drawing.Size(121, 21);
            this.cmb_myIP.TabIndex = 11;
            // 
            // btn_listen
            // 
            this.btn_listen.Location = new System.Drawing.Point(96, 80);
            this.btn_listen.Name = "btn_listen";
            this.btn_listen.Size = new System.Drawing.Size(121, 23);
            this.btn_listen.TabIndex = 12;
            this.btn_listen.Text = "Listen";
            this.btn_listen.UseVisualStyleBackColor = true;
            // 
            // btn_sendLogins
            // 
            this.btn_sendLogins.Location = new System.Drawing.Point(348, 211);
            this.btn_sendLogins.Name = "btn_sendLogins";
            this.btn_sendLogins.Size = new System.Drawing.Size(75, 23);
            this.btn_sendLogins.TabIndex = 13;
            this.btn_sendLogins.Text = "Send";
            this.btn_sendLogins.UseVisualStyleBackColor = true;
            this.btn_sendLogins.Click += new System.EventHandler(this.Btn_Send_Click);
            // 
            // btn_connect
            // 
            this.btn_connect.Location = new System.Drawing.Point(496, 41);
            this.btn_connect.Name = "btn_connect";
            this.btn_connect.Size = new System.Drawing.Size(75, 23);
            this.btn_connect.TabIndex = 14;
            this.btn_connect.Text = "Connect";
            this.btn_connect.UseVisualStyleBackColor = true;
            this.btn_connect.Click += new System.EventHandler(this.Btn_Connect_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btn_connect);
            this.Controls.Add(this.btn_sendLogins);
            this.Controls.Add(this.btn_listen);
            this.Controls.Add(this.cmb_myIP);
            this.Controls.Add(this.tb_pword);
            this.Controls.Add(this.tb_uname);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.lbl_uname);
            this.Controls.Add(this.lbl_portNO_actual);
            this.Controls.Add(this.lbl_otherIP_actual);
            this.Controls.Add(this.lbl_otherIP_header);
            this.Controls.Add(this.tb_portNo);
            this.Controls.Add(this.tb_otherIP);
            this.Controls.Add(this.lb_IP);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label lb_IP;
        private System.Windows.Forms.TextBox tb_otherIP;
        private System.Windows.Forms.TextBox tb_portNo;
        private System.Windows.Forms.Label lbl_otherIP_header;
        private System.Windows.Forms.Label lbl_otherIP_actual;
        private System.Windows.Forms.Label lbl_portNO_actual;
        private System.Windows.Forms.Label lbl_uname;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox tb_uname;
        private System.Windows.Forms.TextBox tb_pword;
        private System.Windows.Forms.ComboBox cmb_myIP;
        private System.Windows.Forms.Button btn_listen;
        private System.Windows.Forms.Button btn_sendLogins;
        private System.Windows.Forms.Button btn_connect;
    }
}

