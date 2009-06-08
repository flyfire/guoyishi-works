<%@ Page Language="C#" AutoEventWireup="true" CodeFile="EventsManagement.aspx.cs" Inherits="Admin_EventsManagement" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
            BackColor="White" BorderColor="White" BorderStyle="Ridge" BorderWidth="2px" 
            CellPadding="3" CellSpacing="1" DataSourceID="EventsDateSource" 
            GridLines="None">
            <FooterStyle BackColor="#C6C3C6" ForeColor="Black" />
            <RowStyle BackColor="#DEDFDE" ForeColor="Black" />
            <Columns>
                <asp:BoundField DataField="Id" HeaderText="Id" InsertVisible="False" 
                    ReadOnly="True" SortExpression="Id" Visible="False" />
                <asp:BoundField DataField="Title" HeaderText="Title" SortExpression="Title" />
                <asp:BoundField DataField="Date" HeaderText="Date" SortExpression="Date" />
                <asp:BoundField DataField="Location" HeaderText="Location" 
                    SortExpression="Location" />
            </Columns>
            <PagerStyle BackColor="#C6C3C6" ForeColor="Black" HorizontalAlign="Right" />
            <SelectedRowStyle BackColor="#9471DE" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#4A3C8C" Font-Bold="True" ForeColor="#E7E7FF" />
        </asp:GridView>
        <asp:SqlDataSource ID="EventsDateSource" runat="server" 
            ConnectionString="<%$ ConnectionStrings:EventsConnectionString %>" 
            ProviderName="<%$ ConnectionStrings:EventsConnectionString.ProviderName %>" 
            SelectCommand="SELECT [Id], [Title], [Date], [Location] FROM [Events]">
        </asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
