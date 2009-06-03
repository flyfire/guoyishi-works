using System;
using System.Collections;
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

public partial class ResultPages : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        try
        {
            if (!PreviousPage.IsValid)
            {
                LabelResult.Text = "Error in previous page.";
                return;
            }

            RegistrationInformation ri = PreviousPage.RegistrationInformation;

            LabelResult.Text = String.Format("{0} {1} selected the event {2}",
                ri.FirstName, ri.FirstName, ri.SelectedEvent);

            //DropDownList dropDownListEvents =
            //    (DropDownList)PreviousPage.FindControl("DropDownListEvents");

            //string selectedEvent = dropDownListEvents.SelectedValue;

            //string firstName =
            //    ((TextBox)PreviousPage.FindControl("TextBoxFirstName")).Text;
            //string lastName =
            //    ((TextBox)PreviousPage.FindControl("TextBoxLastName")).Text;
            //string email =
            //    ((TextBox)PreviousPage.FindControl("TextBoxEmail")).Text;

            //LabelResult.Text = String.Format("{0} {1} selected the event {2}.",
            //    firstName, lastName, selectedEvent);
        }
        catch
        {
            LabelResult.Text = "The originating page must contain " +
                "textFirstName, textLastName, textEmail controls";
        }
    }
}
