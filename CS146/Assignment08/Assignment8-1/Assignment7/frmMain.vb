Public Class frmMain
    ' Structure used in assignment 7
    Structure StudData
        Dim studAbrv As String
        Dim studName As String
        Dim studQuiz1 As Integer
        Dim studQuiz2 As Integer
        Dim studQuiz3 As Integer
        Dim studQuiz4 As Integer
        Dim studProject As Double
        Dim studLetterGrade As String
        Dim finalGrade As Double
    End Structure

    'declaring array of structure
    Dim studData_A(29) As StudData

    'function to calculate student grade
    Function CalcStudGrade(q1 As Integer, q2 As Integer, q3 As Integer, q4 As Integer, proj As Double) As Double
        Dim quizPortion As Double = (((q1 + q2 + q3 + q4) / 100) * 0.5) * 100
        Dim projPortion As Double = ((proj / 100) * 0.5) * 100
        Return quizPortion + projPortion
    End Function

    'function to calculate letter grade
    Function CalcStudLetterGrade(finalgrade As Double) As String
        Dim returnedGrade As String = ""
        Select Case finalgrade
            Case Is >= 95
                returnedGrade = "A"
            Case Is >= 90
                returnedGrade = "A-"
            Case Is >= 87
                returnedGrade = "B+"
            Case Is >= 84
                returnedGrade = "B"
            Case Is >= 80
                returnedGrade = "B-"
            Case Is >= 77
                returnedGrade = "C+"
            Case Is >= 74
                returnedGrade = "C"
            Case Is >= 70
                returnedGrade = "C-"
            Case Is >= 67
                returnedGrade = "D+"
            Case Is >= 64
                returnedGrade = "D"
            Case Is >= 60
                returnedGrade = "D-"
            Case Is >= 0
                returnedGrade = "F"
        End Select
        Return returnedGrade
    End Function

    Private Sub btnMainLoad_Click(sender As Object, e As EventArgs) Handles btnMainLoad.Click
        lstOutput.Items.Clear()
        Dim gradeSum As Double = 0
        Dim gradeAvg As Double = 0
        Dim gradeProjSum As Double = 0
        Dim gradeProjAvg As Double = 0

        lstOutput.Items.Add(String.Format("{0, 53}", "Ole Country School"))
        lstOutput.Items.Add(String.Format("{0, 50}", "Grade System"))
        lstOutput.Items.Add("")
        'The Tutor told me to de that since there is no way to center text in listbox
        Dim outputFormat As String = "{0,-5} {1,-25} {2,-4} {3,-4} {4,-4} {5,-10} {6,-10} {7,-14} {8,-10}"
        Dim outputFormat2 As String = "{0,-23} {1,-7} {2,-4} {3,-4} {4,-4} {5,-10} {6,-10} {7,-10} {8,-10}"
        lstOutput.Items.Add(String.Format(outputFormat2, "Student", "Quiz:", "1", "2", "3", "4", "Project", "Grade", "Letter"))
        lstOutput.Items.Add("--------------------------------------------------------------------------------------")

        Dim studFile() As String = IO.File.ReadAllLines("class.txt")
        Dim recordCnt = studFile.Count
        'Dim arrayData(6) As String -- No need for this one since we are using LINQ

        'I didn't get what column you meant by last name, so I I sorted via second column
        Dim query = From line In studFile
                    Let data = line.Split(" "c)
                    Let studAbrv = data(0)
                    Let studName = data(1)
                    Let studQuiz1 = CInt(data(2))
                    Let studQuiz2 = CInt(data(3))
                    Let studQuiz3 = CInt(data(4))
                    Let studQuiz4 = CInt(data(5))
                    Let studProject = CDbl(data(6))
                    Let finalGrade = CalcStudGrade(studQuiz1, studQuiz2, studQuiz3, studQuiz4, studProject)
                    Let studLetterGrade = CalcStudLetterGrade(finalGrade)
                    Let outputLine = String.Format(outputFormat, studAbrv, studName, CStr(studQuiz1), CStr(studQuiz2), CStr(studQuiz3), CStr(studQuiz4), CStr(studProject), CStr(finalGrade), studLetterGrade)
                    Order By studName Ascending
                    Select {outputLine, studProject, finalGrade, studAbrv, studName, studQuiz1, studQuiz2, studQuiz3, studQuiz4, studLetterGrade}


        Dim i_A As Integer = 0
        For Each dataLine In query
            'this does the sorting and outputting job
            studData_A(i_A).studAbrv = dataLine(3)
            studData_A(i_A).studName = dataLine(4)
            studData_A(i_A).studQuiz1 = CInt(dataLine(5))
            studData_A(i_A).studQuiz2 = CInt(dataLine(6))
            studData_A(i_A).studQuiz3 = CInt(dataLine(7))
            studData_A(i_A).studQuiz4 = CInt(dataLine(8))
            studData_A(i_A).studProject = CDbl(dataLine(1))
            studData_A(i_A).finalGrade = CDbl(dataLine(2))
            studData_A(i_A).studLetterGrade = dataLine(9)
            gradeProjSum += dataLine(1)
            gradeSum += dataLine(2)
            lstOutput.Items.Add(dataLine(0))
            i_A += 1
        Next

        'redimming to save memory consumption.
        ReDim Preserve studData_A(i_A - 1)

        'I was confused in which average should I calculate, so I used what I thought you might asked about.
        gradeAvg = (gradeSum / (recordCnt))
        gradeProjAvg = (gradeProjSum / recordCnt)

        lstOutput.Items.Add("")
        lstOutput.Items.Add(String.Format("{0, 53}", "The Avg of Grades = " & gradeAvg.ToString("N2")))
        lstOutput.Items.Add(String.Format("{0, 57}", "The Avg of Project Grades = " & gradeProjAvg.ToString("N2")))

    End Sub

    Private Sub btnSearch_Click(sender As Object, e As EventArgs) Handles btnSearch.Click
        Dim lastName As String = txtSearch.Text
        Dim lineNum As Integer = SearchLastName(lastName.ToUpper)

        If lineNum <> -1 Then
            'By saying line X it means students among students grades and not the whole listbox list. 
            'I can make it show among whole elements just by adding + 5 to lineNum.
            MessageBox.Show("Student " & lastName & " Could Be Found in line " & lineNum & " and element " & lineNum + 5 & " of the Grades Data")
        Else
            MessageBox.Show("Student " & lastName & " Could Not Be Found In Grade Data List ")
        End If

    End Sub

    'a function that searches and returns line number of searched string, returns -1 if not found.
    Function SearchLastName(lastName As String) As Integer
        Dim result As Integer = -1
        Dim lineNum As Integer = 0

        For i As Integer = 0 To studData_A.GetUpperBound(0)
            lineNum += 1
            Dim studNameInArray As String = studData_A(i).studName.ToUpper
            If studData_A(i).studName.ToUpper = CStr(lastName.ToUpper) Then
                result = lineNum
            End If
        Next

        Return result
    End Function

    Private Sub frmMain_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub
End Class
