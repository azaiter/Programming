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
        Me.lstOutput = New System.Windows.Forms.ListBox()
        Me.btnMainLoad = New System.Windows.Forms.Button()
        Me.btnSearch = New System.Windows.Forms.Button()
        Me.txtSearch = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'lstOutput
        '
        Me.lstOutput.Font = New System.Drawing.Font("Courier New", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lstOutput.FormattingEnabled = True
        Me.lstOutput.ItemHeight = 15
        Me.lstOutput.Location = New System.Drawing.Point(12, 42)
        Me.lstOutput.Name = "lstOutput"
        Me.lstOutput.Size = New System.Drawing.Size(644, 349)
        Me.lstOutput.TabIndex = 0
        '
        'btnMainLoad
        '
        Me.btnMainLoad.Location = New System.Drawing.Point(12, 12)
        Me.btnMainLoad.Name = "btnMainLoad"
        Me.btnMainLoad.Size = New System.Drawing.Size(156, 23)
        Me.btnMainLoad.TabIndex = 1
        Me.btnMainLoad.Text = "Load File"
        Me.btnMainLoad.UseVisualStyleBackColor = True
        '
        'btnSearch
        '
        Me.btnSearch.Location = New System.Drawing.Point(420, 9)
        Me.btnSearch.Name = "btnSearch"
        Me.btnSearch.Size = New System.Drawing.Size(130, 23)
        Me.btnSearch.TabIndex = 2
        Me.btnSearch.Text = "Search by Last Name"
        Me.btnSearch.UseVisualStyleBackColor = True
        '
        'txtSearch
        '
        Me.txtSearch.Location = New System.Drawing.Point(556, 12)
        Me.txtSearch.Name = "txtSearch"
        Me.txtSearch.Size = New System.Drawing.Size(100, 20)
        Me.txtSearch.TabIndex = 3
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(668, 409)
        Me.Controls.Add(Me.txtSearch)
        Me.Controls.Add(Me.btnSearch)
        Me.Controls.Add(Me.btnMainLoad)
        Me.Controls.Add(Me.lstOutput)
        Me.Name = "frmMain"
        Me.Text = "Ole Country School Grade System"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents lstOutput As System.Windows.Forms.ListBox
    Friend WithEvents btnMainLoad As Button
    Friend WithEvents btnSearch As Button
    Friend WithEvents txtSearch As TextBox
End Class
