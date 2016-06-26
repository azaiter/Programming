Public Class frmMain

    Private Sub btnSayHello_Click(sender As Object, e As EventArgs) Handles btnSayHello.Click
        'My First Attempt before the lecture.
        'If txtInput.Text = "" Then
        'txtOutput.Text = ""
        'Else
        'txtOutput.Text = "Hello " & txtInput.Text
        'End If
        ' The Logic is : what if you typed a name and then typed nothing ... it will show nothing. but the code given in the lecture doesn't not do the trick .
        If Not String.IsNullOrWhiteSpace(txtInput.Text) Then
            txtOutput.Text = "Hello " & txtInput.Text & " !"
        End If
    End Sub
End Class
