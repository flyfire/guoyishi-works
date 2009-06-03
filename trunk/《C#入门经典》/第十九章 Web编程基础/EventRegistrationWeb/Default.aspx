<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
    <style type="text/css">
        .style1
        {
            width: 100%;
        }
        .style2
        {
            width: 136px;
        }
        .style3
        {
            width: 222px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <table class="style1">
            <tr>
                <td class="style2">
                    <asp:Label ID="LabelEvent" runat="server" Text="Event:"></asp:Label>
                </td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownListEvents" runat="server">
                        <asp:ListItem>SQL Server 2008 and XML</asp:ListItem>
                        <asp:ListItem>Office 2007 and XML</asp:ListItem>
                        <asp:ListItem>Introduction to ASP.NET</asp:ListItem>
                    </asp:DropDownList>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    <asp:Label ID="LabelFirstname" runat="server" Text="FirstName:"></asp:Label>
                </td>
                <td class="style3">
                    <asp:TextBox ID="TextBoxFirstName" runat="server" 
                        ontextchanged="TextBoxFirstName_TextChanged"></asp:TextBox>
                </td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                        ControlToValidate="TextBoxFirstName" ErrorMessage="Firstname is required"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    <asp:Label ID="LabelLastname" runat="server" Text="LastName:"></asp:Label>
                </td>
                <td class="style3">
                    <asp:TextBox ID="TextBoxLastName" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" 
                        ControlToValidate="TextBoxLastName" ErrorMessage="Lastname is required"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    <asp:Label ID="LabelEmail" runat="server" Text="Email:"></asp:Label>
                </td>
                <td class="style3">
                    <asp:TextBox ID="TextBoxEmail" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" 
                        ControlToValidate="TextBoxEmail" ErrorMessage="Email is required"></asp:RequiredFieldValidator>
                    <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" 
                        ControlToValidate="TextBoxEmail" Display="Dynamic" 
                        ErrorMessage="Enter a valid Email" 
                        ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*"></asp:RegularExpressionValidator>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    &nbsp;</td>
                <td class="style3">
                    <asp:Button ID="ButtonSubmit" runat="server" onclick="ButtonSubmit_Click" 
                        PostBackUrl="~/ResultPages.aspx" Text="Submit" />
                </td>
                <td>
                    &nbsp;</td>
            </tr>
        </table>
    
    </div>
    <asp:Label ID="LabelResult" runat="server" Text="[labelResult]"></asp:Label>
    </form>
</body>
</html>
