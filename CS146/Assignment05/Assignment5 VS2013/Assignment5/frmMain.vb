Public Class frmMain
    Private Sub btnGenIn_Click(sender As Object, e As EventArgs) Handles btnGenIn.Click
        'main event that calls all needed functions.
        lstOut.Items.Clear()
        PrintCustomerDetails(txtCusNam.Text, txtAdrs.Text, txtCSZ.Text)
        PrintOrderDetails(CInt(txtComOrd.Text), CInt(txtMonOrd.Text), CInt(txtPrntOrd.Text))
    End Sub

    Sub PrintCustomerDetails(name As String, address As String, CityStateZip As String)
        'prints invoice number, name , address and city state and zip
        lstOut.Items.Add("Invoice Number: " & GetInvoiceNum(txtCusNam.Text, txtCSZ.Text))
        lstOut.Items.Add("")
        lstOut.Items.Add("Name: " & name)
        lstOut.Items.Add("Address: " & address)
        lstOut.Items.Add("City: " & CityStateZip)
        lstOut.Items.Add("")
    End Sub

    Function GetInvoiceNum(name As String, CityStateZip As String) As String
        'returns last digits of name and last 4 from city state zip combined in one string
        Return (name.Substring(0, 3) & CityStateZip.Substring(CityStateZip.Length - 4))
    End Function

    Sub PrintOrderDetails(ComputerOrder As Integer, MonitorOrder As Integer, PrinterOrder As Integer)
        'prints num of computers,monitors,printers,cost,sales tax, and total cost
        Dim costSum As Integer = ((1250 * ComputerOrder) + (425 * MonitorOrder) + (600 * PrinterOrder))
        Dim salesTax As Double = CalcSaleTax(costSum)
        Dim totalCost As Double = costSum + salesTax
        lstOut.Items.Add("Number of Computers: " & ComputerOrder)
        lstOut.Items.Add("Number of Monitors: " & MonitorOrder)
        lstOut.Items.Add("Number of Printers: " & PrinterOrder)
        lstOut.Items.Add("")
        lstOut.Items.Add("")
        lstOut.Items.Add(String.Format("{0,13} {1,-15}", "Cost: ", costSum.ToString("C")))
        lstOut.Items.Add(String.Format("{0,13} {1,-15}", "Sales Tax: ", salesTax.ToString("C")))
        lstOut.Items.Add(String.Format("{0,13} {1,-15}", "", "-----------"))
        lstOut.Items.Add(String.Format("{0,13} {1,-15}", "Total Cost: ", totalCost.ToString("C")))
    End Sub

    Function CalcSaleTax(money As Integer) As Double
        'returns sales value.
        Return (0.06 * money)
    End Function
End Class
