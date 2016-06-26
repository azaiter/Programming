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
        Me.lstOut = New System.Windows.Forms.ListBox()
        Me.btnSubmit = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'lstOut
        '
        Me.lstOut.FormattingEnabled = True
        Me.lstOut.Location = New System.Drawing.Point(13, 13)
        Me.lstOut.Name = "lstOut"
        Me.lstOut.Size = New System.Drawing.Size(516, 290)
        Me.lstOut.TabIndex = 0
        '
        'btnSubmit
        '
        Me.btnSubmit.Location = New System.Drawing.Point(172, 311)
        Me.btnSubmit.Name = "btnSubmit"
        Me.btnSubmit.Size = New System.Drawing.Size(187, 28)
        Me.btnSubmit.TabIndex = 1
        Me.btnSubmit.Text = "Analyze File Now !"
        Me.btnSubmit.UseVisualStyleBackColor = True
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(541, 347)
        Me.Controls.Add(Me.btnSubmit)
        Me.Controls.Add(Me.lstOut)
        Me.Name = "frmMain"
        Me.Text = "Palindromes Analyzer"
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents lstOut As ListBox
    Friend WithEvents btnSubmit As Button
End Class
