using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml.Serialization;
using System.Xml;
using System.Net;

namespace SwitchNet
{
    public partial class FormNetConfig : Form
    {
        public FormNetConfig()
        {
            InitializeComponent();
        }

        #region Private Variables and properties
        
        /// <summary>
        /// Contain the Profile List
        /// </summary>
        internal System.Collections.ArrayList _Profiles = new System.Collections.ArrayList();

        /// <summary>
        /// Return current profile name
        /// </summary>
        private string _ProfileName
        {
            get
            {
                return comboBoxProfiles.SelectedItem as string;
            }
        }

        /// <summary>
        /// Return current profile
        /// </summary>
        internal Profile _CurrentProfile
        {
            get
            {
                // find the profile for the currently selected profile
                foreach (Profile profile in _Profiles)
                    if (profile.ProfileName.Equals(_ProfileName))
                        return profile;

                return null;
            }
        }

        /// <summary>
        /// Return current NIC profile
        /// </summary>
        internal NICProfile _CurrentNICProfile
        {
            get
            {
                // find the NIC Profile for the currently selected NIC name
                foreach (NICProfile profile in _CurrentProfile.NICProfiles)
                    if (profile.Name.Equals(_NICName))
                        return profile;

                // not found, create a new NIC Profile
                NICProfile newProfile = new NICProfile(comboBoxNIC.Text);
                _CurrentProfile.NICProfiles.Add(newProfile);

                return newProfile;
            }
        }

        /// <summary>
        /// Return current NIC name
        /// </summary>
        private string _NICName
        {
            get
            {
                return comboBoxNIC.SelectedItem as string;
            }
        }
        
        #endregion
        

        #region private Methods

        #region peivate load Methods

        /// <summary>
        /// Load the Switch Net Configuration
        /// </summary>
        private void loadApp()
        {
            loadProfiles();
        }

        /// <summary>
        /// Load profiles from XML file
        /// </summary>
        private void loadProfiles()
        {
            _Profiles = ConfigurationHelper.LoadConfig();

            // populate the profile drop down list
            comboBoxProfiles.Items.Clear();
            foreach (Profile profile in _Profiles)
            {
                comboBoxProfiles.Items.Add(profile.ProfileName);
            }
            if (comboBoxProfiles.Items.Count > 0)
                comboBoxProfiles.SelectedIndex = 0;

            loadProfile(_CurrentProfile);
        }

        /// <summary>
        /// Load profile settings
        /// </summary>
        /// <param name="profile"></param>
        private void loadProfile(Profile profile)
        {
            if (isProfileExist())
            {
                loadExistNICs();

                buttonOK.Enabled = true;
            }
            else
            {
                btnDeleteEnable();
            }
        }

        /// <summary>
        /// Load NIC from profile which selected
        /// </summary>
        private void loadExistNICs()
        {
            ArrayList nicProfiles = _CurrentProfile.NICProfiles;

            if (nicProfiles.Count == 0)
                noNICAtAll();

            comboBoxNIC.Items.Clear();

            foreach (NICProfile nic in nicProfiles)
            {
                comboBoxNIC.Items.Add(nic.Name);
            }

            loadNICPart2();
        }

        /// <summary>
        /// If no NIC do this
        /// </summary>
        private void noNICAtAll()
        {
            //MessageBox.Show("No NIC could be found!", "Error!",MessageBoxButtons.OK, MessageBoxIcon.Error);

            groupBoxConfig.Enabled = false;
            buttonApply.Enabled = false;
        }

        /// <summary>
        /// Load the current Network settings
        /// </summary>
        private void loadNICs()
        {
            //Get current NIC names
            ArrayList nicNames = NetworkManagement.GetNICNames();

            comboBoxNIC.Items.Clear();
           
            foreach (string name in nicNames)
            {
                comboBoxNIC.Items.Add(name);
            }

            loadNICPart2();
        }

        /// <summary>
        /// Load NIC if correct
        /// </summary>
        private void loadNICPart2()
        {
            if (comboBoxNIC.Items.Count > 0)
            {
                comboBoxNIC.SelectedIndex = 0;
                panelDetails.Enabled = true;
            }

            if (isProfileExist())
            {
                loadExistNIC();
            }
            else
            {
                loadEmptyNIC();
            }
        }


        private bool isProfileExist()
        {
            if (ConfigurationHelper.OpenOK && _Profiles.Count >0)
            {
                return true;
            }
            return false;
        }

        /// <summary>
        /// Load NIC from current NIC profile
        /// </summary>
        private void loadExistNIC()
        {
            NICProfile nicProfile = _CurrentNICProfile;

            if (nicProfile.UseDHCP)
            {
                ipAddressControlIP.Clear();
                ipAddressControlSubnet.Clear();
                ipAddressControlGateway.Clear();

                radioButtonObtainIPAuto.Checked = true;
                radioButtonSetIP.Checked = false;
            }
            else
            {
                ipAddressControlIP.SetAddressString(nicProfile.IP);
                ipAddressControlSubnet.SetAddressString(nicProfile.Subnet);
                ipAddressControlGateway.SetAddressString(nicProfile.Gateway);

                radioButtonObtainIPAuto.Checked = false;
                radioButtonSetIP.Checked = true;

                radioButtonObtainDNSAuto.Checked = false;
                radioButtonSetDNS.Checked = true;
            }
            
            if (nicProfile.UseDNSAuto)
            {
                ipAddressControlDNSPreferred.SetAddressString(null);
                ipAddressControlDNSAltermate.SetAddressString(null);

                if (nicProfile.UseDHCP)
                {
                    radioButtonObtainDNSAuto.Checked = true;
                    radioButtonSetDNS.Checked = false;
                }
            }
            else
            {
                ipAddressControlDNSPreferred.SetAddressString(nicProfile.DNSPreferred);
                ipAddressControlDNSAltermate.SetAddressString(nicProfile.DNSAltermate);

                radioButtonObtainDNSAuto.Checked = false;
                radioButtonSetDNS.Checked = true;
            }

            btnLoadEnable();
        }

        /// <summary>
        /// Load selected NIC
        /// </summary>
        private void loadSelectedNIC()
        {
            loadAddress(_NICName);
        }

        #region private load Address Methods

        /// <summary>
        /// Load IP and DNS
        /// </summary>
        /// <param name="NICName"></param>
        private void loadAddress(string NICName)
        {
            try
            {
                loadIPAddress(NICName);
                loadDNSAddress(NICName);
            }
            catch (Exception e)
            {
                MessageBox.Show("[Error]: The NIC is not using!\r\n[Message]: " + e.Message,
                    "Error", MessageBoxButtons.OK);
            }

        }

        /// <summary>
        /// Load IP
        /// </summary>
        /// <param name="NICName"></param>
        private void loadIPAddress(string NICName)
        {
            if (!NetworkManagement.DHCPEnabled(NICName))
            {
                try
                {

                    string[] IPAddresses = NetworkManagement.GetIPAddress(NICName);
                    string[] SubnetAddresses = NetworkManagement.GetIPSubnetAddress(NICName);
                    string[] DefaultIPGatewayAddresses = NetworkManagement.GetDefaultIPGatewayAddress(NICName);


                    ipAddressControlIP.SetAddressString(IPAddresses[0]);
                    ipAddressControlSubnet.SetAddressString(SubnetAddresses[0]);
                    ipAddressControlGateway.SetAddressString(DefaultIPGatewayAddresses[0]);

                    radioButtonSetIP.Checked = true;
                }

                catch (NullReferenceException)
                {
                    throw;
                }
            }
            else
            {
                //MessageBox.Show("[TEST] -- MaiForm -- loadIPAddress -- DHCPEnabled!");
                radioButtonObtainIPAuto.Checked = true;
            }
        }

        /// <summary>
        /// Load DNS
        /// </summary>
        /// <param name="NICName"></param>
        private void loadDNSAddress(string NICName)
        {
            string[] DNSServerAddress = null;
            try
            {
                DNSServerAddress = NetworkManagement.GetDNSServerAddress(NICName);
            }

            catch (Exception)
            {
                throw;
            }

            finally
            {
                if (DNSServerAddress.LongLength > 1)
                {
                    ipAddressControlDNSPreferred.SetAddressString(DNSServerAddress[0]);
                    ipAddressControlDNSAltermate.SetAddressString(DNSServerAddress[1]);
                }
                else if (DNSServerAddress.LongLength == 1)
                {
                    ipAddressControlDNSPreferred.SetAddressString(DNSServerAddress[0]);
                    ipAddressControlDNSAltermate.Clear();
                }
                else
                {
                    ipAddressControlDNSPreferred.Clear();
                    ipAddressControlDNSAltermate.Clear();
                }
            }
        }

        #endregion

        /// <summary>
        /// Empty IP Control
        /// </summary>
        private void loadEmptyNIC()
        {
            radioButtonObtainIPAuto.Checked = true;
            radioButtonObtainDNSAuto.Checked = true;

            ipAddressControlIP.Clear();
            ipAddressControlSubnet.Clear();
            ipAddressControlGateway.Clear();
            ipAddressControlDNSPreferred.Clear();
            ipAddressControlDNSAltermate.Clear();
        }

        #endregion

        /// <summary>
        /// Set Button Enable
        /// </summary>
        private void btnDeleteEnable()
        {
            if (comboBoxProfiles.Items.Count < 1)
            {
                EnableItems(false);
            }
            else
            {
                EnableItems(true);
            }
        }

        /// <summary>
        /// btnDeleteEnable items
        /// </summary>
        /// <param name="flag"></param>
        private void EnableItems(bool flag)
        {
            comboBoxProfiles.Enabled = flag;

            buttonDelete.Enabled = flag;
            groupBoxConfig.Enabled = flag;

            buttonOK.Enabled = flag;
            buttonApply.Enabled = flag;
        }

        /// <summary>
        /// Set button Apply
        /// </summary>
        private void btnApplyEnable()
        {
            if (isCurrentNICCanBeUse())
            {
                buttonApply.Enabled = true;
            }
            else
            {
                buttonApply.Enabled = false;
            }
        }

        /// <summary>
        /// Set button Load
        /// </summary>
        private void btnLoadEnable()
        {
            if (isCurrentNICCanBeUse())
            {
                buttonLoad.Enabled = true;
            }
            else
            {
                buttonLoad.Enabled = false;
            }
        }

        /// <summary>
        /// Judge the Load Enable
        /// </summary>
        /// <returns></returns>
        private bool isCurrentNICCanBeUse()
        {
            ArrayList NICsCurrentCanBeUsed = NetworkManagement.GetNICNames();

            foreach (string nicName in NICsCurrentCanBeUsed)
            {
                if (_NICName == nicName)
                    return true;
            }

            return false;
        }

        #region private Profile Methods

        /// <summary>
        /// Show ApplyProfile Dialog
        /// </summary>
        private void applyProfile()
        {
            using (ApplyDialog newapplyDialog = new ApplyDialog(this))
            {
                newapplyDialog.ShowDialog();
                loadExistNIC();
            }
        }

        /// <summary>
        /// Save All Profiles
        /// </summary>
        private void saveProfiles()
        {
            clearEmptyNICs();

            ConfigurationHelper.SaveConfig(_Profiles);
        }

        /// <summary>
        /// Clear the Empty NICs
        /// I don't know where the from
        /// If you know Send mail to GuoYishi@Gamil.com
        /// </summary>
        private void clearEmptyNICs()
        {
            for(int i = 0; i < _Profiles.Count; ++i)
            {
                Profile profile = (Profile)_Profiles[i];
                for (int j = 0; j < ((Profile)_Profiles[i]).NICProfiles.Count; ++j)
                {
                    NICProfile nicProfile = (NICProfile)profile.NICProfiles[j];
                    if (nicProfile.Name.Length == 0)
                        profile.NICProfiles.RemoveAt(j);
                }
            }
        }

        /// <summary>
        /// Save infomation to _CurrentNICProfile
        /// </summary>
        private void saveCurrentSettings()
        {
            _CurrentNICProfile.IP = ipAddressControlIP.GetAddressString();
            _CurrentNICProfile.Subnet = ipAddressControlSubnet.GetAddressString(); 
            _CurrentNICProfile.Gateway = ipAddressControlGateway.GetAddressString();

            _CurrentNICProfile.DNSPreferred = ipAddressControlDNSPreferred.GetAddressString();
            _CurrentNICProfile.DNSAltermate = ipAddressControlDNSAltermate.GetAddressString();

            _CurrentNICProfile.UseDHCP = radioButtonObtainIPAuto.Checked;
        }

        /// <summary>
        /// Show NewProfileDialog and Create new profile
        /// </summary>
        private void createNewProfile()
        {
            using (NewProfileDialog newDialog = new NewProfileDialog(this))
            {
                if (newDialog.ShowDialog(this) == DialogResult.OK)
                {
                    Profile newProfile = new Profile(newDialog.NewProfileName);
                    _Profiles.Add(newProfile);

                    comboBoxProfiles.SelectedIndex = comboBoxProfiles.Items.Add(newProfile.ProfileName);

                    loadNICs();

                    btnDeleteEnable();
                }
            }
        }

        /// <summary>
        /// Delete selected profile
        /// </summary>
        /// <param name="index">Remove index</param>
        private void profileRemoveAt(int index)
        {
            comboBoxProfiles.Items.RemoveAt(index);
            _Profiles.RemoveAt(index);
        }

        /// <summary>
        /// Delete comboBoxProfiles.SelectedIndex
        /// </summary>
        private void deleteProfile()
        {
            int count = comboBoxProfiles.Items.Count;

            switch (count)
            {
                case 0:
                    break;
                case 1:
                    profileRemoveAt(0);
                    break;
                default:
                    int index = comboBoxProfiles.SelectedIndex;
                    if (index == count - 1)
                    {
                        comboBoxProfiles.SelectedIndex = index - 1;
                    }
                    else
                    {
                        comboBoxProfiles.SelectedIndex = index + 1;
                    }
                    profileRemoveAt(index);
                    break;
            }
            btnDeleteEnable();
        }

        #endregion

        #endregion

        #region buttonEvents

        private void buttonNew_Click(object sender, EventArgs e)
        {
            createNewProfile();
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            deleteProfile();
        }

        private void buttonLoad_Click(object sender, EventArgs e)
        {
            loadSelectedNIC();
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void buttonApply_Click(object sender, EventArgs e)
        {
            saveCurrentSettings();
            applyProfile();
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            saveCurrentSettings();
            Close();
        }

        #endregion

        #region radioButton Events

        private void radioButtonSetIP_CheckedChanged(object sender, EventArgs e)
        {
            _CurrentNICProfile.UseDHCP = radioButtonObtainIPAuto.Checked;
            if (radioButtonSetIP.Checked == true)
            {
                radioButtonObtainIPAuto.Checked = false;
                radioButtonObtainDNSAuto.Checked = false;
                radioButtonObtainDNSAuto.Enabled = false;
                radioButtonSetDNS.Checked = true;
                panelIP.Enabled = true;
            }
            else
            {
                radioButtonObtainIPAuto.Checked = true;
            }
        }

        private void radioButtonSetDNS_CheckedChanged(object sender, EventArgs e)
        {
            _CurrentNICProfile.UseDNSAuto = radioButtonObtainDNSAuto.Checked;
            if (radioButtonSetDNS.Checked == true)
            {
                radioButtonObtainDNSAuto.Checked = false;
                panelDNS.Enabled = true;
            }
            else
            {
                radioButtonObtainDNSAuto.Checked = true;
            }
        }

        private void radioButtonObtainIPAuto_CheckedChanged(object sender, EventArgs e)
        {

            _CurrentNICProfile.UseDHCP = radioButtonObtainIPAuto.Checked;

            if (radioButtonObtainIPAuto.Checked == true)
            {
                radioButtonSetIP.Checked = false;
                radioButtonObtainDNSAuto.Enabled = true;
                panelIP.Enabled = false;
            }
            else
            {
                radioButtonSetIP.Checked = true;
            }
        }

        private void radioButtonObtainDNSAuto_CheckedChanged(object sender, EventArgs e)
        {
            _CurrentNICProfile.UseDNSAuto = radioButtonObtainDNSAuto.Checked;
            if (radioButtonObtainDNSAuto.Checked == true)
            {
                radioButtonSetDNS.Checked = false;
                panelDNS.Enabled = false;
            }
            else
            {
                radioButtonSetDNS.Checked = true;
            }
        }

        #endregion

        private void comboBoxProfiles_SelectedIndexChanged(object sender, EventArgs e)
        {
            loadProfile(_CurrentProfile);

            //Clear Empty NICs
            clearEmptyNICs();
        }

        private void comboBoxNIC_SelectedIndexChanged(object sender, EventArgs e)
        {
            loadExistNIC();
        }

        private void comboBoxProfiles_DropDown(object sender, EventArgs e)
        {
            //saveCurrentSettings();
        }

        private void tabPageMain_Enter(object sender, EventArgs e)
        {
            //btnDeleteEnable();
        }

        private void FormNetConfig_FormClosing(object sender, FormClosingEventArgs e)
        {
            saveProfiles();
        }

        private void FormNetConfig_Load(object sender, EventArgs e)
        {
            loadApp();

            btnDeleteEnable();
        }

        private void linkLabel_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("http://meiyou.org/");
        }

        private void tabPageAbout_Enter(object sender, EventArgs e)
        {
            buttonApply.Enabled = false;
        }

        private void tabPageConfig_Enter(object sender, EventArgs e)
        {
            btnDeleteEnable();
        }

    }
}
