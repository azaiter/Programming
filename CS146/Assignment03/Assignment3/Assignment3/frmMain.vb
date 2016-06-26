'******************************************************************
' AUTHOR: Abdulrahman Zaiter 
'
' COURSE TITLE: Visual Basic.NET Programming
'
' COURSE NUMBER: CS146
'
' PROF NAME: Matt Giddings
'
' ASSIGNMENT NUMBER: #3
'
' DUE DATE: 09-28-2015
'
' POSSIBLE POINTS: 20 Points
'
' PURPOSE:
'
'      The program will be an application that accepts two inputs (integer values) then performs the following
'      math operations. Addition, Subtraction, Division, Multiplication, Integer Division, Mod, String
'      Concatenation, And the string length of each input And output
'
'*******************************************************************

Public Class frmMain
    'declaring variables and some needed intial data.
    Dim inputFirst As String = 1
    Dim inputSecond As String = 1
    Dim outputAdd As Double
    Dim outputSub As Double
    Dim outputMul As Double
    Dim outputDiv As Double
    Dim outputIntDiv As Double
    Dim outputMod As Double
    Dim outputConcat As Double

    Private Sub frmMain_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        txtInput1.Text = 1
        txtInput2.Text = 1
    End Sub

    Private Sub txtInput1and2_KeyUp(sender As Object, e As EventArgs) Handles txtInput1.KeyUp, txtInput2.KeyUp
        doTheMath()
    End Sub

    Function doTheMath()
        lstLog.Items.Clear()
        lstLog.Items.Add("Declaring Variables ...")
        ' Checking Strings to Avoid Exceptions
        If Not String.IsNullOrWhiteSpace(txtInput1.Text) Then
            inputFirst = txtInput1.Text
        End If
        If Not String.IsNullOrWhiteSpace(txtInput2.Text) Then
            inputSecond = txtInput2.Text
        End If
        txtInput1L.Text = inputFirst.Length
        txtInput2L.Text = inputSecond.Length
        lstLog.Items.Add("Evaluating Expressions ...")
        outputAdd = CDbl(inputFirst) + CDbl(inputSecond)
        lstLog.Items.Add("Addition = " & outputAdd)
        outputSub = CDbl(inputFirst) - CDbl(inputSecond)
        lstLog.Items.Add("Substraction = " & outputSub)
        outputMul = CDbl(inputFirst) * CDbl(inputSecond)
        lstLog.Items.Add("Multiplication = " & outputMul)
        outputDiv = CDbl(inputFirst) / CDbl(inputSecond)
        lstLog.Items.Add("Division = " & outputDiv)
        'int division on zero causes exception. can be solved by using normal division only on that case.
        If inputSecond = 0 Then
            outputIntDiv = CInt(inputFirst) / CInt(inputSecond)
        Else
            outputIntDiv = CInt(inputFirst) \ CInt(inputSecond)
        End If
        lstLog.Items.Add("Int Division = " & outputIntDiv)
        outputMod = CDbl(inputFirst) Mod CDbl(inputSecond)
        lstLog.Items.Add("Mod = " & outputMod)
        outputConcat = CDbl(inputFirst) & CDbl(inputSecond)
        lstLog.Items.Add("Concat = " & outputConcat)
        lstLog.Items.Add("Successfully Declared Variables and Evaluated Expressions.")
        lstLog.Items.Add("Viewing Data to TextBoxes ...")
        txtOutputAdd.Text = outputAdd
        txtOutputSub.Text = outputSub
        txtOutputMul.Text = outputMul
        txtOutputDiv.Text = outputDiv
        txtOutputIntDiv.Text = outputIntDiv
        txtOutputMod.Text = outputMod
        txtOutputConcat.Text = outputConcat
        lstLog.Items.Add("Successfully Viewed Data to TextBoxes.")
        lstLog.Items.Add("Adding Lenght to TextBoxes ...")
        txtOutputAddL.Text = CStr(outputAdd).Length
        txtOutputSubL.Text = CStr(outputSub).Length
        txtOutputMulL.Text = CStr(outputMul).Length
        txtOutputDivL.Text = CStr(outputDiv).Length
        txtOutputIntDivL.Text = CStr(outputIntDiv).Length
        txtOutputModL.Text = CStr(outputMod).Length
        txtOutputConcatL.Text = CStr(outputConcat).Length
        lstLog.Items.Add("Successfully Added Lenght to TextBoxes.")
        lstLog.Items.Add("Everything Went Smooth So Far.")
    End Function
End Class
