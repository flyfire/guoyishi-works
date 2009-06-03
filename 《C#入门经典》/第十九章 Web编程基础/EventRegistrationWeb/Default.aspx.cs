using System;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;

public partial class _Default : System.Web.UI.Page 
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void ButtonSubmit_Click(object sender, EventArgs e)
    {
        string selectedEvent = DropDownListEvents.SelectedValue;
        string firstname = TextBoxFirstName.Text;
        string lastname = TextBoxLastName.Text;
        string email = TextBoxEmail.Text;

        LabelResult.Text = String.Format("{0} {1} selected the event {2}.",
            firstname, lastname, selectedEvent);
    }
    protected void TextBoxFirstName_TextChanged(object sender, EventArgs e)
    {

    }

    public RegistrationInformation RegistrationInformation
    {
        get
        {
            return new RegistrationInformation()
            {
                FirstName = TextBoxFirstName.Text,
                LastName = TextBoxLastName.Text,
                Email = TextBoxEmail.Text,
                SelectedEvent = DropDownListEvents.SelectedValue
            };
        }
    }
}
