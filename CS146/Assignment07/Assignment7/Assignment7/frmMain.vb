Public Class frmMain
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

    Dim studData_A(29) As StudData
    Private Sub frmMain_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'The Tutor told me to de that since there is no way to center text in listbox
        Dim gradeSum As Double = 0
        Dim gradeAvg As Double = 0
        Dim gradeProjSum As Double = 0
        Dim gradeProjAvg As Double = 0
        lstOutput.Items.Add(String.Format("{0, 53}", "Ole Country School"))
        lstOutput.Items.Add(String.Format("{0, 50}", "Grade System"))
        lstOutput.Items.Add("")
        Dim outputFormat As String = "{0,-5} {1,-25} {2,-4} {3,-4} {4,-4} {5,-10} {6,-10} {7,-14} {8,-10}"
        Dim outputFormat2 As String = "{0,-23} {1,-7} {2,-4} {3,-4} {4,-4} {5,-10} {6,-10} {7,-10} {8,-10}"
        lstOutput.Items.Add(String.Format(outputFormat2, "Student", "Quiz:", "1", "2", "3", "4", "Project", "Grade", "Letter"))
        lstOutput.Items.Add("--------------------------------------------------------------------------------------")
        Dim studFile() As String = IO.File.ReadAllLines("class.txt")
        Dim recordCnt = studFile.Count
        Dim lineData As String 'holds each line data
        Dim arrayData(6) As String
        For i As Integer = 0 To (recordCnt - 1)
            lineData = studFile(i)
            arrayData = lineData.Split(" "c)
            studData_A(i).studAbrv = arrayData(0)
            studData_A(i).studName = arrayData(1)
            studData_A(i).studQuiz1 = CInt(arrayData(2))
            studData_A(i).studQuiz2 = CInt(arrayData(3))
            studData_A(i).studQuiz3 = CInt(arrayData(4))
            studData_A(i).studQuiz4 = CInt(arrayData(5))
            studData_A(i).studProject = CDbl(arrayData(6))
            studData_A(i).finalGrade = CalcStudGrade(studData_A(i).studQuiz1, studData_A(i).studQuiz2, studData_A(i).studQuiz3, studData_A(i).studQuiz4, studData_A(i).studProject)
            studData_A(i).studLetterGrade = CalcStudLetterGrade(studData_A(i).finalGrade)
            lstOutput.Items.Add(String.Format(outputFormat, studData_A(i).studAbrv, studData_A(i).studName, CStr(studData_A(i).studQuiz1), CStr(studData_A(i).studQuiz2), CStr(studData_A(i).studQuiz3), CStr(studData_A(i).studQuiz4), CStr(studData_A(i).studProject), CStr(studData_A(i).finalGrade), studData_A(i).studLetterGrade))
            gradeProjSum += studData_A(i).studProject
            gradeSum += studData_A(i).finalGrade
        Next
        ' because there is no further explaination in the assignment, I made two averages of grades
        ' first one is the avg of grades out of 25, and the second one out of 100
        gradeAvg = (gradeSum / (recordCnt))
        gradeProjAvg = (gradeProjSum / recordCnt)
        lstOutput.Items.Add("")
        lstOutput.Items.Add(String.Format("{0, 53}", "The Avg of Grades = " & gradeAvg.ToString("N2")))
        lstOutput.Items.Add(String.Format("{0, 57}", "The Avg of Project Grades = " & gradeProjAvg.ToString("N2")))
    End Sub
    Function CalcStudGrade(q1 As Integer, q2 As Integer, q3 As Integer, q4 As Integer, proj As Double) As Double
        Dim quizPortion As Double = (((q1 + q2 + q3 + q4) / 100) * 0.5) * 100
        Dim projPortion As Double = ((proj / 100) * 0.5) * 100
        Return quizPortion + projPortion
    End Function
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
End Class
