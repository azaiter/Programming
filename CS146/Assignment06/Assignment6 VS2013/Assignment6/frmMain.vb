Public Class frmMain
    Private Sub btnSubmit_Click(sender As Object, e As EventArgs) Handles btnSubmit.Click
        lstOut.Items.Clear()
        'declaring input stream
        Dim inputFile As IO.StreamReader = IO.File.OpenText("palindromes.txt")
        Dim numFound As Integer
        Dim numNotFound As Integer
        'doing main loop
        Do While Not inputFile.EndOfStream()
            Dim lineInfo As String = inputFile.ReadLine
            Dim lineClean = StripOutChrNum(lineInfo).ToUpper
            Dim lineCleanRvrs = GiveReverse(StripOutChrNum(lineInfo)).ToUpper
            'For Debugging
            'lstOut.Items.Add(lineClean & "->" & lineCleanRvrs)
            If lineClean = lineCleanRvrs Then
                lstOut.Items.Add(Chr(34) & lineInfo & Chr(34) & " is a palindrome")
                numFound += 1
            Else
                lstOut.Items.Add(Chr(34) & lineInfo & Chr(34) & " not a palindrome")
                numNotFound += 1
            End If
        Loop
        lstOut.Items.Add("Found: " & numFound)
        lstOut.Items.Add("Not Found: " & numNotFound)
    End Sub

    'function that returns only characters and numbers of a string
    Function StripOutChrNum(inputData As String) As String
        Dim inputDataLower As String = inputData.ToLower
        Dim tmp1 As String = ""
        Dim tmp2 As String = ""
        For i As Integer = 0 To (inputDataLower.Length - 1)
            tmp1 = inputDataLower.Substring(i, 1)
            If (tmp1 >= "a" And tmp1 <= "z") Or (tmp1 >= "0" And tmp1 <= "9") Then
                tmp2 &= tmp1
            End If
        Next
        Return tmp2
    End Function

    'function that returns the reverese of a string
    Function GiveReverse(inputData As String) As String
        Dim infoL As Integer
        Dim tmp As String = ""
        infoL = inputData.Length
        For i As Integer = (infoL - 1) To 0 Step -1
            tmp &= inputData.Substring(i, 1)
        Next
        Return tmp
    End Function
End Class

