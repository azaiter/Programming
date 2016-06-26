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
        Me.txtBox1 = New System.Windows.Forms.TextBox()
        Me.txtBox2 = New System.Windows.Forms.TextBox()
        Me.txtBox3 = New System.Windows.Forms.TextBox()
        Me.txtBox4 = New System.Windows.Forms.TextBox()
        Me.txtBox5 = New System.Windows.Forms.TextBox()
        Me.txtBox6 = New System.Windows.Forms.TextBox()
        Me.txtBox7 = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'txtBox1
        '
        Me.txtBox1.Location = New System.Drawing.Point(12, 12)
        Me.txtBox1.Name = "txtBox1"
        Me.txtBox1.Size = New System.Drawing.Size(43, 20)
        Me.txtBox1.TabIndex = 0
        '
        'txtBox2
        '
        Me.txtBox2.Location = New System.Drawing.Point(61, 12)
        Me.txtBox2.Name = "txtBox2"
        Me.txtBox2.Size = New System.Drawing.Size(43, 20)
        Me.txtBox2.TabIndex = 1
        '
        'txtBox3
        '
        Me.txtBox3.Location = New System.Drawing.Point(110, 12)
        Me.txtBox3.Name = "txtBox3"
        Me.txtBox3.Size = New System.Drawing.Size(43, 20)
        Me.txtBox3.TabIndex = 2
        '
        'txtBox4
        '
        Me.txtBox4.Location = New System.Drawing.Point(159, 12)
        Me.txtBox4.Name = "txtBox4"
        Me.txtBox4.Size = New System.Drawing.Size(43, 20)
        Me.txtBox4.TabIndex = 3
        '
        'txtBox5
        '
        Me.txtBox5.Location = New System.Drawing.Point(208, 12)
        Me.txtBox5.Name = "txtBox5"
        Me.txtBox5.Size = New System.Drawing.Size(43, 20)
        Me.txtBox5.TabIndex = 4
        '
        'txtBox6
        '
        Me.txtBox6.Location = New System.Drawing.Point(257, 12)
        Me.txtBox6.Name = "txtBox6"
        Me.txtBox6.Size = New System.Drawing.Size(43, 20)
        Me.txtBox6.TabIndex = 5
        '
        'txtBox7
        '
        Me.txtBox7.Location = New System.Drawing.Point(306, 12)
        Me.txtBox7.Name = "txtBox7"
        Me.txtBox7.Size = New System.Drawing.Size(43, 20)
        Me.txtBox7.TabIndex = 6
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(357, 47)
        Me.Controls.Add(Me.txtBox7)
        Me.Controls.Add(Me.txtBox6)
        Me.Controls.Add(Me.txtBox5)
        Me.Controls.Add(Me.txtBox4)
        Me.Controls.Add(Me.txtBox3)
        Me.Controls.Add(Me.txtBox2)
        Me.Controls.Add(Me.txtBox1)
        Me.Name = "frmMain"
        Me.Text = "Chaser Light Simulator"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents txtBox1 As System.Windows.Forms.TextBox
    Friend WithEvents txtBox2 As System.Windows.Forms.TextBox
    Friend WithEvents txtBox3 As System.Windows.Forms.TextBox
    Friend WithEvents txtBox4 As System.Windows.Forms.TextBox
    Friend WithEvents txtBox5 As System.Windows.Forms.TextBox
    Friend WithEvents txtBox6 As System.Windows.Forms.TextBox
    Friend WithEvents txtBox7 As System.Windows.Forms.TextBox

End Class
