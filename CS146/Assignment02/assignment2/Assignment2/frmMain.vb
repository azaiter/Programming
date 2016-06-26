Public Class frmMain
    '******************************************************************
    ' AUTHOR: Abdulrahman Zaiter 
    '
    ' COURSE TITLE: Visual Basic.NET Programming
    '
    ' COURSE NUMBER: CS146
    '
    ' PROF NAME: Matt Giddings
    '
    ' ASSIGNMENT NUMBER: #2
    '
    ' DUE DATE: 09-14-2015
    '
    ' POSSIBLE POINTS: 20 Points
    '
    ' PURPOSE:
    '
    '      The program will be simulating a chaser light sequence with 7 txtBoxes.
    '      Wehn the chaser light is red, while each light to the left and right of the chaser are colored orange. All other lights will be colored yellow
    '
    '*******************************************************************
    Private Sub FrmMain_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        txtBox1.BackColor = Color.Red
        txtBox2.BackColor = Color.Orange
        txtBox3.BackColor = Color.Yellow
        txtBox4.BackColor = Color.Yellow
        txtBox5.BackColor = Color.Yellow
        txtBox6.BackColor = Color.Yellow
        txtBox7.BackColor = Color.Orange

    End Sub

    Private Sub txtBox1_Leave(sender As Object, e As EventArgs) Handles txtBox1.Leave
        txtBox1.BackColor = Color.Orange
        txtBox2.BackColor = Color.Red
        txtBox3.BackColor = Color.Orange
        txtBox4.BackColor = Color.Yellow
        txtBox5.BackColor = Color.Yellow
        txtBox6.BackColor = Color.Yellow
        txtBox7.BackColor = Color.Yellow
    End Sub
    Private Sub txtBox2_Leave(sender As Object, e As EventArgs) Handles txtBox2.Leave
        txtBox1.BackColor = Color.Yellow
        txtBox2.BackColor = Color.Orange
        txtBox3.BackColor = Color.Red
        txtBox4.BackColor = Color.Orange
        txtBox5.BackColor = Color.Yellow
        txtBox6.BackColor = Color.Yellow
        txtBox7.BackColor = Color.Yellow
    End Sub



    Private Sub txtBox3_Leave(sender As Object, e As EventArgs) Handles txtBox3.Leave
        txtBox1.BackColor = Color.Yellow
        txtBox2.BackColor = Color.Yellow
        txtBox3.BackColor = Color.Orange
        txtBox4.BackColor = Color.Red
        txtBox5.BackColor = Color.Orange
        txtBox6.BackColor = Color.Yellow
        txtBox7.BackColor = Color.Yellow
    End Sub



    Private Sub txtBox4_Leave(sender As Object, e As EventArgs) Handles txtBox4.Leave
        txtBox1.BackColor = Color.Yellow
        txtBox2.BackColor = Color.Yellow
        txtBox3.BackColor = Color.Yellow
        txtBox4.BackColor = Color.Orange
        txtBox5.BackColor = Color.Red
        txtBox6.BackColor = Color.Orange
        txtBox7.BackColor = Color.Yellow
    End Sub



    Private Sub txtBox5_Leave(sender As Object, e As EventArgs) Handles txtBox5.Leave
        txtBox1.BackColor = Color.Yellow
        txtBox2.BackColor = Color.Yellow
        txtBox3.BackColor = Color.Yellow
        txtBox4.BackColor = Color.Yellow
        txtBox5.BackColor = Color.Orange
        txtBox6.BackColor = Color.Red
        txtBox7.BackColor = Color.Orange
    End Sub



    Private Sub txtBox6_Leave(sender As Object, e As EventArgs) Handles txtBox6.Leave
        txtBox1.BackColor = Color.Orange
        txtBox2.BackColor = Color.Yellow
        txtBox3.BackColor = Color.Yellow
        txtBox4.BackColor = Color.Yellow
        txtBox5.BackColor = Color.Yellow
        txtBox6.BackColor = Color.Orange
        txtBox7.BackColor = Color.Red
    End Sub



    Private Sub txtBox7_Leave(sender As Object, e As EventArgs) Handles txtBox7.Leave
        txtBox1.BackColor = Color.Red
        txtBox2.BackColor = Color.Orange
        txtBox3.BackColor = Color.Yellow
        txtBox4.BackColor = Color.Yellow
        txtBox5.BackColor = Color.Yellow
        txtBox6.BackColor = Color.Yellow
        txtBox7.BackColor = Color.Orange
    End Sub



End Class
