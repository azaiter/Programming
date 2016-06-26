<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmMain
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.txtInput1 = New System.Windows.Forms.TextBox()
        Me.txtInput2 = New System.Windows.Forms.TextBox()
        Me.lblNum1 = New System.Windows.Forms.Label()
        Me.lblNum2 = New System.Windows.Forms.Label()
        Me.txtInput1L = New System.Windows.Forms.TextBox()
        Me.txtInput2L = New System.Windows.Forms.TextBox()
        Me.txtOutputAdd = New System.Windows.Forms.TextBox()
        Me.txtOutputSub = New System.Windows.Forms.TextBox()
        Me.txtOutputMul = New System.Windows.Forms.TextBox()
        Me.txtOutputDiv = New System.Windows.Forms.TextBox()
        Me.txtOutputIntDiv = New System.Windows.Forms.TextBox()
        Me.txtOutputMod = New System.Windows.Forms.TextBox()
        Me.txtOutputConcat = New System.Windows.Forms.TextBox()
        Me.lblAdd = New System.Windows.Forms.Label()
        Me.lblSub = New System.Windows.Forms.Label()
        Me.lblMul = New System.Windows.Forms.Label()
        Me.lblDiv = New System.Windows.Forms.Label()
        Me.lblIntDiv = New System.Windows.Forms.Label()
        Me.lblMod = New System.Windows.Forms.Label()
        Me.lblConcat = New System.Windows.Forms.Label()
        Me.txtOutputAddL = New System.Windows.Forms.TextBox()
        Me.txtOutputSubL = New System.Windows.Forms.TextBox()
        Me.txtOutputMulL = New System.Windows.Forms.TextBox()
        Me.txtOutputDivL = New System.Windows.Forms.TextBox()
        Me.txtOutputIntDivL = New System.Windows.Forms.TextBox()
        Me.txtOutputModL = New System.Windows.Forms.TextBox()
        Me.txtOutputConcatL = New System.Windows.Forms.TextBox()
        Me.lblResults = New System.Windows.Forms.Label()
        Me.lblLength = New System.Windows.Forms.Label()
        Me.lstLog = New System.Windows.Forms.ListBox()
        Me.SuspendLayout()
        '
        'txtInput1
        '
        Me.txtInput1.Location = New System.Drawing.Point(74, 6)
        Me.txtInput1.Name = "txtInput1"
        Me.txtInput1.Size = New System.Drawing.Size(100, 20)
        Me.txtInput1.TabIndex = 0
        '
        'txtInput2
        '
        Me.txtInput2.Location = New System.Drawing.Point(337, 6)
        Me.txtInput2.Name = "txtInput2"
        Me.txtInput2.Size = New System.Drawing.Size(100, 20)
        Me.txtInput2.TabIndex = 1
        '
        'lblNum1
        '
        Me.lblNum1.AutoSize = True
        Me.lblNum1.Location = New System.Drawing.Point(12, 9)
        Me.lblNum1.Name = "lblNum1"
        Me.lblNum1.Size = New System.Drawing.Size(57, 13)
        Me.lblNum1.TabIndex = 2
        Me.lblNum1.Text = "Number 1:"
        '
        'lblNum2
        '
        Me.lblNum2.AutoSize = True
        Me.lblNum2.Location = New System.Drawing.Point(275, 9)
        Me.lblNum2.Name = "lblNum2"
        Me.lblNum2.Size = New System.Drawing.Size(57, 13)
        Me.lblNum2.TabIndex = 3
        Me.lblNum2.Text = "Number 2:"
        '
        'txtInput1L
        '
        Me.txtInput1L.Location = New System.Drawing.Point(180, 6)
        Me.txtInput1L.Name = "txtInput1L"
        Me.txtInput1L.ReadOnly = True
        Me.txtInput1L.Size = New System.Drawing.Size(39, 20)
        Me.txtInput1L.TabIndex = 4
        '
        'txtInput2L
        '
        Me.txtInput2L.Location = New System.Drawing.Point(443, 6)
        Me.txtInput2L.Name = "txtInput2L"
        Me.txtInput2L.ReadOnly = True
        Me.txtInput2L.Size = New System.Drawing.Size(39, 20)
        Me.txtInput2L.TabIndex = 5
        '
        'txtOutputAdd
        '
        Me.txtOutputAdd.Location = New System.Drawing.Point(180, 68)
        Me.txtOutputAdd.Name = "txtOutputAdd"
        Me.txtOutputAdd.ReadOnly = True
        Me.txtOutputAdd.Size = New System.Drawing.Size(100, 20)
        Me.txtOutputAdd.TabIndex = 6
        '
        'txtOutputSub
        '
        Me.txtOutputSub.Location = New System.Drawing.Point(180, 94)
        Me.txtOutputSub.Name = "txtOutputSub"
        Me.txtOutputSub.ReadOnly = True
        Me.txtOutputSub.Size = New System.Drawing.Size(100, 20)
        Me.txtOutputSub.TabIndex = 7
        '
        'txtOutputMul
        '
        Me.txtOutputMul.Location = New System.Drawing.Point(180, 120)
        Me.txtOutputMul.Name = "txtOutputMul"
        Me.txtOutputMul.ReadOnly = True
        Me.txtOutputMul.Size = New System.Drawing.Size(100, 20)
        Me.txtOutputMul.TabIndex = 8
        '
        'txtOutputDiv
        '
        Me.txtOutputDiv.Location = New System.Drawing.Point(180, 146)
        Me.txtOutputDiv.Name = "txtOutputDiv"
        Me.txtOutputDiv.ReadOnly = True
        Me.txtOutputDiv.Size = New System.Drawing.Size(100, 20)
        Me.txtOutputDiv.TabIndex = 9
        '
        'txtOutputIntDiv
        '
        Me.txtOutputIntDiv.Location = New System.Drawing.Point(180, 172)
        Me.txtOutputIntDiv.Name = "txtOutputIntDiv"
        Me.txtOutputIntDiv.ReadOnly = True
        Me.txtOutputIntDiv.Size = New System.Drawing.Size(100, 20)
        Me.txtOutputIntDiv.TabIndex = 10
        '
        'txtOutputMod
        '
        Me.txtOutputMod.Location = New System.Drawing.Point(180, 198)
        Me.txtOutputMod.Name = "txtOutputMod"
        Me.txtOutputMod.ReadOnly = True
        Me.txtOutputMod.Size = New System.Drawing.Size(100, 20)
        Me.txtOutputMod.TabIndex = 11
        '
        'txtOutputConcat
        '
        Me.txtOutputConcat.Location = New System.Drawing.Point(180, 224)
        Me.txtOutputConcat.Name = "txtOutputConcat"
        Me.txtOutputConcat.ReadOnly = True
        Me.txtOutputConcat.Size = New System.Drawing.Size(100, 20)
        Me.txtOutputConcat.TabIndex = 12
        '
        'lblAdd
        '
        Me.lblAdd.AutoSize = True
        Me.lblAdd.Location = New System.Drawing.Point(118, 71)
        Me.lblAdd.Name = "lblAdd"
        Me.lblAdd.Size = New System.Drawing.Size(26, 13)
        Me.lblAdd.TabIndex = 13
        Me.lblAdd.Text = "Add"
        '
        'lblSub
        '
        Me.lblSub.AutoSize = True
        Me.lblSub.Location = New System.Drawing.Point(119, 97)
        Me.lblSub.Name = "lblSub"
        Me.lblSub.Size = New System.Drawing.Size(25, 13)
        Me.lblSub.TabIndex = 14
        Me.lblSub.Text = "Sub"
        '
        'lblMul
        '
        Me.lblMul.AutoSize = True
        Me.lblMul.Location = New System.Drawing.Point(119, 123)
        Me.lblMul.Name = "lblMul"
        Me.lblMul.Size = New System.Drawing.Size(27, 13)
        Me.lblMul.TabIndex = 15
        Me.lblMul.Text = "Mult"
        '
        'lblDiv
        '
        Me.lblDiv.AutoSize = True
        Me.lblDiv.Location = New System.Drawing.Point(119, 149)
        Me.lblDiv.Name = "lblDiv"
        Me.lblDiv.Size = New System.Drawing.Size(22, 13)
        Me.lblDiv.TabIndex = 16
        Me.lblDiv.Text = "Div"
        '
        'lblIntDiv
        '
        Me.lblIntDiv.AutoSize = True
        Me.lblIntDiv.Location = New System.Drawing.Point(118, 175)
        Me.lblIntDiv.Name = "lblIntDiv"
        Me.lblIntDiv.Size = New System.Drawing.Size(39, 13)
        Me.lblIntDiv.TabIndex = 17
        Me.lblIntDiv.Text = "Int Div"
        '
        'lblMod
        '
        Me.lblMod.AutoSize = True
        Me.lblMod.Location = New System.Drawing.Point(118, 201)
        Me.lblMod.Name = "lblMod"
        Me.lblMod.Size = New System.Drawing.Size(27, 13)
        Me.lblMod.TabIndex = 18
        Me.lblMod.Text = "Mod"
        '
        'lblConcat
        '
        Me.lblConcat.AutoSize = True
        Me.lblConcat.Location = New System.Drawing.Point(118, 227)
        Me.lblConcat.Name = "lblConcat"
        Me.lblConcat.Size = New System.Drawing.Size(41, 13)
        Me.lblConcat.TabIndex = 19
        Me.lblConcat.Text = "Concat"
        '
        'txtOutputAddL
        '
        Me.txtOutputAddL.Location = New System.Drawing.Point(286, 68)
        Me.txtOutputAddL.Name = "txtOutputAddL"
        Me.txtOutputAddL.ReadOnly = True
        Me.txtOutputAddL.Size = New System.Drawing.Size(39, 20)
        Me.txtOutputAddL.TabIndex = 20
        '
        'txtOutputSubL
        '
        Me.txtOutputSubL.Location = New System.Drawing.Point(286, 94)
        Me.txtOutputSubL.Name = "txtOutputSubL"
        Me.txtOutputSubL.ReadOnly = True
        Me.txtOutputSubL.Size = New System.Drawing.Size(39, 20)
        Me.txtOutputSubL.TabIndex = 21
        '
        'txtOutputMulL
        '
        Me.txtOutputMulL.Location = New System.Drawing.Point(286, 120)
        Me.txtOutputMulL.Name = "txtOutputMulL"
        Me.txtOutputMulL.ReadOnly = True
        Me.txtOutputMulL.Size = New System.Drawing.Size(39, 20)
        Me.txtOutputMulL.TabIndex = 22
        '
        'txtOutputDivL
        '
        Me.txtOutputDivL.Location = New System.Drawing.Point(286, 146)
        Me.txtOutputDivL.Name = "txtOutputDivL"
        Me.txtOutputDivL.ReadOnly = True
        Me.txtOutputDivL.Size = New System.Drawing.Size(39, 20)
        Me.txtOutputDivL.TabIndex = 23
        '
        'txtOutputIntDivL
        '
        Me.txtOutputIntDivL.Location = New System.Drawing.Point(286, 172)
        Me.txtOutputIntDivL.Name = "txtOutputIntDivL"
        Me.txtOutputIntDivL.ReadOnly = True
        Me.txtOutputIntDivL.Size = New System.Drawing.Size(39, 20)
        Me.txtOutputIntDivL.TabIndex = 24
        '
        'txtOutputModL
        '
        Me.txtOutputModL.Location = New System.Drawing.Point(286, 198)
        Me.txtOutputModL.Name = "txtOutputModL"
        Me.txtOutputModL.ReadOnly = True
        Me.txtOutputModL.Size = New System.Drawing.Size(39, 20)
        Me.txtOutputModL.TabIndex = 25
        '
        'txtOutputConcatL
        '
        Me.txtOutputConcatL.Location = New System.Drawing.Point(286, 224)
        Me.txtOutputConcatL.Name = "txtOutputConcatL"
        Me.txtOutputConcatL.ReadOnly = True
        Me.txtOutputConcatL.Size = New System.Drawing.Size(39, 20)
        Me.txtOutputConcatL.TabIndex = 26
        '
        'lblResults
        '
        Me.lblResults.AutoSize = True
        Me.lblResults.Location = New System.Drawing.Point(211, 52)
        Me.lblResults.Name = "lblResults"
        Me.lblResults.Size = New System.Drawing.Size(42, 13)
        Me.lblResults.TabIndex = 27
        Me.lblResults.Text = "Results"
        '
        'lblLength
        '
        Me.lblLength.AutoSize = True
        Me.lblLength.Location = New System.Drawing.Point(283, 52)
        Me.lblLength.Name = "lblLength"
        Me.lblLength.Size = New System.Drawing.Size(40, 13)
        Me.lblLength.TabIndex = 28
        Me.lblLength.Text = "Length"
        '
        'lstLog
        '
        Me.lstLog.FormattingEnabled = True
        Me.lstLog.Location = New System.Drawing.Point(15, 283)
        Me.lstLog.Name = "lstLog"
        Me.lstLog.Size = New System.Drawing.Size(467, 121)
        Me.lstLog.TabIndex = 30
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(504, 413)
        Me.Controls.Add(Me.lstLog)
        Me.Controls.Add(Me.lblLength)
        Me.Controls.Add(Me.lblResults)
        Me.Controls.Add(Me.txtOutputConcatL)
        Me.Controls.Add(Me.txtOutputModL)
        Me.Controls.Add(Me.txtOutputIntDivL)
        Me.Controls.Add(Me.txtOutputDivL)
        Me.Controls.Add(Me.txtOutputMulL)
        Me.Controls.Add(Me.txtOutputSubL)
        Me.Controls.Add(Me.txtOutputAddL)
        Me.Controls.Add(Me.lblConcat)
        Me.Controls.Add(Me.lblMod)
        Me.Controls.Add(Me.lblIntDiv)
        Me.Controls.Add(Me.lblDiv)
        Me.Controls.Add(Me.lblMul)
        Me.Controls.Add(Me.lblSub)
        Me.Controls.Add(Me.lblAdd)
        Me.Controls.Add(Me.txtOutputConcat)
        Me.Controls.Add(Me.txtOutputMod)
        Me.Controls.Add(Me.txtOutputIntDiv)
        Me.Controls.Add(Me.txtOutputDiv)
        Me.Controls.Add(Me.txtOutputMul)
        Me.Controls.Add(Me.txtOutputSub)
        Me.Controls.Add(Me.txtOutputAdd)
        Me.Controls.Add(Me.txtInput2L)
        Me.Controls.Add(Me.txtInput1L)
        Me.Controls.Add(Me.lblNum2)
        Me.Controls.Add(Me.lblNum1)
        Me.Controls.Add(Me.txtInput2)
        Me.Controls.Add(Me.txtInput1)
        Me.Name = "frmMain"
        Me.Text = "Assignment3"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents txtInput1 As System.Windows.Forms.TextBox
    Friend WithEvents txtInput2 As System.Windows.Forms.TextBox
    Friend WithEvents lblNum1 As System.Windows.Forms.Label
    Friend WithEvents lblNum2 As System.Windows.Forms.Label
    Friend WithEvents txtInput1L As System.Windows.Forms.TextBox
    Friend WithEvents txtInput2L As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputAdd As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputSub As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputMul As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputDiv As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputIntDiv As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputMod As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputConcat As System.Windows.Forms.TextBox
    Friend WithEvents lblAdd As System.Windows.Forms.Label
    Friend WithEvents lblSub As System.Windows.Forms.Label
    Friend WithEvents lblMul As System.Windows.Forms.Label
    Friend WithEvents lblDiv As System.Windows.Forms.Label
    Friend WithEvents lblIntDiv As System.Windows.Forms.Label
    Friend WithEvents lblMod As System.Windows.Forms.Label
    Friend WithEvents lblConcat As System.Windows.Forms.Label
    Friend WithEvents txtOutputAddL As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputSubL As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputMulL As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputDivL As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputIntDivL As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputModL As System.Windows.Forms.TextBox
    Friend WithEvents txtOutputConcatL As System.Windows.Forms.TextBox
    Friend WithEvents lblResults As System.Windows.Forms.Label
    Friend WithEvents lblLength As System.Windows.Forms.Label
    Friend WithEvents lstLog As ListBox
End Class
