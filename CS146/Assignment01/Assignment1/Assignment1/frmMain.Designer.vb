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
        Me.btnSayHello = New System.Windows.Forms.Button()
        Me.txtOutput = New System.Windows.Forms.TextBox()
        Me.txtInput = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'btnSayHello
        '
        Me.btnSayHello.Location = New System.Drawing.Point(12, 48)
        Me.btnSayHello.Name = "btnSayHello"
        Me.btnSayHello.Size = New System.Drawing.Size(260, 23)
        Me.btnSayHello.TabIndex = 0
        Me.btnSayHello.Text = "Say Hello"
        Me.btnSayHello.UseVisualStyleBackColor = True
        '
        'txtOutput
        '
        Me.txtOutput.Location = New System.Drawing.Point(12, 17)
        Me.txtOutput.Name = "txtOutput"
        Me.txtOutput.ReadOnly = True
        Me.txtOutput.Size = New System.Drawing.Size(260, 20)
        Me.txtOutput.TabIndex = 1
        Me.txtOutput.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txtInput
        '
        Me.txtInput.Location = New System.Drawing.Point(12, 80)
        Me.txtInput.Name = "txtInput"
        Me.txtInput.Size = New System.Drawing.Size(260, 20)
        Me.txtInput.TabIndex = 2
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 117)
        Me.Controls.Add(Me.txtInput)
        Me.Controls.Add(Me.txtOutput)
        Me.Controls.Add(Me.btnSayHello)
        Me.Name = "frmMain"
        Me.Text = "Hello World"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnSayHello As System.Windows.Forms.Button
    Friend WithEvents txtOutput As System.Windows.Forms.TextBox
    Friend WithEvents txtInput As System.Windows.Forms.TextBox

End Class
