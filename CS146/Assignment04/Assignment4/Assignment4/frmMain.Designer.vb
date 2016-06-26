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
        Me.btnCalc = New System.Windows.Forms.Button()
        Me.lstResults = New System.Windows.Forms.ListBox()
        Me.SuspendLayout()
        '
        'btnCalc
        '
        Me.btnCalc.Location = New System.Drawing.Point(316, 13)
        Me.btnCalc.Name = "btnCalc"
        Me.btnCalc.Size = New System.Drawing.Size(200, 50)
        Me.btnCalc.TabIndex = 0
        Me.btnCalc.Text = "Calculate Worth !"
        Me.btnCalc.UseVisualStyleBackColor = True
        '
        'lstResults
        '
        Me.lstResults.Font = New System.Drawing.Font("Courier New", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lstResults.FormattingEnabled = True
        Me.lstResults.ItemHeight = 14
        Me.lstResults.Location = New System.Drawing.Point(12, 69)
        Me.lstResults.Name = "lstResults"
        Me.lstResults.Size = New System.Drawing.Size(829, 326)
        Me.lstResults.TabIndex = 1
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(853, 411)
        Me.Controls.Add(Me.lstResults)
        Me.Controls.Add(Me.btnCalc)
        Me.Name = "frmMain"
        Me.Text = "Calculate Worth"
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents btnCalc As Button
    Friend WithEvents lstResults As ListBox
End Class
