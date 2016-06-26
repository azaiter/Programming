'******************************************************************
' AUTHOR: Abdulrahman Zaiter 
'
' COURSE TITLE: Visual Basic.NET Programming
'
' COURSE NUMBER: CS146
'
' PROF NAME: Matt Giddings
'
' ASSIGNMENT NUMBER: #4
'
' DUE DATE: 10-05-2015
'
' POSSIBLE POINTS: 20 Points
'
' PURPOSE:
'
'      a program that converts change (quarters, dimes, nickels and pennies) into whole
'      dollars And the cents remaining. the program will be reading this information
'      from a file (Change.txt)
'
'*******************************************************************

Public Class frmMain
    Private Sub btnCalc_Click(sender As Object, e As EventArgs) Handles btnCalc.Click
		'outputting intial data
		lstResults.Items.Clear()
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", "Quarters", "Dimes", "Nickels", "Pennies", "-->", "Dollars", "Cents"))
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", "--------", "-----", "-------", "-------", "   ", "-------", "-----"))
        'declaring input stream
        Dim inputFile As IO.StreamReader = IO.File.OpenText("Change.txt")
        ' declaring variables and inputing from stream / outputting on final stage
        Dim quarters As Integer
        Dim dimes As Integer
        Dim nickels As Integer
        Dim pennies As Integer
        Dim totalCents As Integer
        Dim outDollar As Integer
        Dim outCents As Integer
		'entry 1 start
        quarters = CInt(inputFile.ReadLine)
        dimes = CInt(inputFile.ReadLine)
        nickels = CInt(inputFile.ReadLine)
        pennies = CInt(inputFile.ReadLine)
        totalCents = (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)
        outDollar = totalCents \ 100
        outCents = totalCents Mod 100
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", quarters, dimes, nickels, pennies, "-->", outDollar, outCents))
		'entry 1 end
		'entry 2 start
        quarters = CInt(inputFile.ReadLine)
        dimes = CInt(inputFile.ReadLine)
        nickels = CInt(inputFile.ReadLine)
        pennies = CInt(inputFile.ReadLine)
        totalCents = (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)
        outDollar = totalCents \ 100
        outCents = totalCents Mod 100
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", quarters, dimes, nickels, pennies, "-->", outDollar, outCents))
		'entry 2 end
		'entry 3 start
        quarters = CInt(inputFile.ReadLine)
        dimes = CInt(inputFile.ReadLine)
        nickels = CInt(inputFile.ReadLine)
        pennies = CInt(inputFile.ReadLine)
        totalCents = (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)
        outDollar = totalCents \ 100
        outCents = totalCents Mod 100
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", quarters, dimes, nickels, pennies, "-->", outDollar, outCents))
		'entry 3 end
		'entry 4 start
        quarters = CInt(inputFile.ReadLine)
        dimes = CInt(inputFile.ReadLine)
        nickels = CInt(inputFile.ReadLine)
        pennies = CInt(inputFile.ReadLine)
        totalCents = (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)
        outDollar = totalCents \ 100
        outCents = totalCents Mod 100
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", quarters, dimes, nickels, pennies, "-->", outDollar, outCents))
		'entry 4 end
		'entry 5 start
        quarters = CInt(inputFile.ReadLine)
        dimes = CInt(inputFile.ReadLine)
        nickels = CInt(inputFile.ReadLine)
        pennies = CInt(inputFile.ReadLine)
        totalCents = (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)
        outDollar = totalCents \ 100
        outCents = totalCents Mod 100
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", quarters, dimes, nickels, pennies, "-->", outDollar, outCents))
		'entry 5 end
		'entry 6 start
        quarters = CInt(inputFile.ReadLine)
        dimes = CInt(inputFile.ReadLine)
        nickels = CInt(inputFile.ReadLine)
        pennies = CInt(inputFile.ReadLine)
        totalCents = (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)
        outDollar = totalCents \ 100
        outCents = totalCents Mod 100
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", quarters, dimes, nickels, pennies, "-->", outDollar, outCents))
		'entry 6 end
		'entry 7 start
        quarters = CInt(inputFile.ReadLine)
        dimes = CInt(inputFile.ReadLine)
        nickels = CInt(inputFile.ReadLine)
        pennies = CInt(inputFile.ReadLine)
        totalCents = (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)
        outDollar = totalCents \ 100
        outCents = totalCents Mod 100
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", quarters, dimes, nickels, pennies, "-->", outDollar, outCents))
		'entry 7 end
		'entry 8 start
        quarters = CInt(inputFile.ReadLine)
        dimes = CInt(inputFile.ReadLine)
        nickels = CInt(inputFile.ReadLine)
        pennies = CInt(inputFile.ReadLine)
        totalCents = (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)
        outDollar = totalCents \ 100
        outCents = totalCents Mod 100
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", quarters, dimes, nickels, pennies, "-->", outDollar, outCents))
		'entry 8 end
		'entry 9 start
        quarters = CInt(inputFile.ReadLine)
        dimes = CInt(inputFile.ReadLine)
        nickels = CInt(inputFile.ReadLine)
        pennies = CInt(inputFile.ReadLine)
        totalCents = (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)
        outDollar = totalCents \ 100
        outCents = totalCents Mod 100
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", quarters, dimes, nickels, pennies, "-->", outDollar, outCents))
		'entry 9 end
		'entry 10 start
        quarters = CInt(inputFile.ReadLine)
        dimes = CInt(inputFile.ReadLine)
        nickels = CInt(inputFile.ReadLine)
        pennies = CInt(inputFile.ReadLine)
        totalCents = (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)
        outDollar = totalCents \ 100
        outCents = totalCents Mod 100
        lstResults.Items.Add(String.Format("{0,14} {1,14} {2,14} {3,14} {4,14} {5,14} {6,14}", quarters, dimes, nickels, pennies, "-->", outDollar, outCents))
		'entry 10 end
		
		End Sub
End Class
