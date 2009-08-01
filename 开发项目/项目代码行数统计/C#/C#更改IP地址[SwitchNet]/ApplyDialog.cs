using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SwitchNet
{
    public partial class ApplyDialog : Form
    {
        private FormNetConfig formNetConfig;

        public ApplyDialog(FormNetConfig mainForm)
        {
            InitializeComponent();

            this.formNetConfig = mainForm;

            loadDialog();
        }

        private void loadDialog()
        {
            clearLabel();
            buttonOK.Enabled = false;

            ApplySetting(formNetConfig._CurrentNICProfile);
        }

        private void clearLabel()
        {
            labelProfileName.Text = null;
            labelSetNICName.Text = null;
        }

        private void loadLabel()
        {
            labelProfileName.Text = formNetConfig._CurrentProfile.Name;
            labelSetNICName.Text = formNetConfig._CurrentNICProfile.Name;
        }

        private void ApplySetting(NICProfile nicProfile)
        {
            loadLabel();

            CurrentInfoUpdate();

            // Invole the profile manager to apply the profile
            NICProfileManager manager = new NICProfileManager(nicProfile);

            manager.OnStatusUpdate += new StatusUpdate(manager_OnStatusUpdate);

            manager.Run();

            buttonOK.Enabled = true;
        }

        private void manager_OnStatusUpdate(string message)
        {
            textBoxStatus.AppendText(message);
        }

        private void StatusUpdate(string message)
        {
            textBoxStatus.AppendText(message);
        }

        private void CurrentInfoUpdate()
        {
            string message = null;

            message += "Current Network Configuration:";

            if (!formNetConfig._CurrentNICProfile.UseDHCP)
                message = CurrentIPInfo(message);
            else
                message += "\r\nObtain an IP address automatically.";
            if (!formNetConfig._CurrentNICProfile.UseDNSAuto)
                message = CurrentDNSInfo(message);
            else
                message += "\r\nObtain DNS server address automatically.";

            message += "\r\n\r\n";

            StatusUpdate(message);
        }

        private string CurrentIPInfo(string message)
        {
            message += "\r\nIP Address:\t" + formNetConfig._CurrentNICProfile.IP;
            message += "\r\nSubnet Mask:\t" + formNetConfig._CurrentNICProfile.Subnet;
            message += "\r\nDefault Gateway:\t" + formNetConfig._CurrentNICProfile.Gateway;

            return message;
        }

        private string CurrentDNSInfo(string message)
        {
            message += "\r\nPreferred DNS:\t" + formNetConfig._CurrentNICProfile.DNSPreferred;
            message += "\r\nAltermate DNS\t" + formNetConfig._CurrentNICProfile.DNSAltermate;

            return message;
        }


        #region private button Events

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        #endregion
    }
}
