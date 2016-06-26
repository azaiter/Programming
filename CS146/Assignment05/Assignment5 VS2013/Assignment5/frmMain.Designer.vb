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
        Me.lblCusNam = New System.Windows.Forms.Label()
        Me.lblAdrs = New System.Windows.Forms.Label()
        Me.lblCSZ = New System.Windows.Forms.Label()
        Me.lblComOrd = New System.Windows.Forms.Label()
        Me.lblMonOrd = New System.Windows.Forms.Label()
        Me.lblPrntOrd = New System.Windows.Forms.Label()
        Me.btnGenIn = New System.Windows.Forms.Button()
        Me.txtCusNam = New System.Windows.Forms.TextBox()
        Me.txtAdrs = New System.Windows.Forms.TextBox()
        Me.txtCSZ = New System.Windows.Forms.TextBox()
        Me.txtComOrd = New System.Windows.Forms.TextBox()
        Me.txtMonOrd = New System.Windows.Forms.TextBox()
        Me.txtPrntOrd = New System.Windows.Forms.TextBox()
        Me.lstOut = New System.Windows.Forms.ListBox()
        Me.SuspendLayout()
        '
        'lblCusNam
        '
        Me.lblCusNam.AutoSize = True
        Me.lblCusNam.Location = New System.Drawing.Point(20, 20)
        Me.lblCusNam.Name = "lblCusNam"
        Me.lblCusNam.Size = New System.Drawing.Size(87, 13)
        Me.lblCusNam.TabIndex = 0
        Me.lblCusNam.Text = "Customer Name:"
        '
        'lblAdrs
        '
        Me.lblAdrs.AutoSize = True
        Me.lblAdrs.Location = New System.Drawing.Point(20, 50)
        Me.lblAdrs.Name = "lblAdrs"
        Me.lblAdrs.Size = New System.Drawing.Size(50, 13)
        Me.lblAdrs.TabIndex = 1
        Me.lblAdrs.Text = "Address:"
        '
        'lblCSZ
        '
        Me.lblCSZ.AutoSize = True
        Me.lblCSZ.Location = New System.Drawing.Point(20, 80)
        Me.lblCSZ.Name = "lblCSZ"
        Me.lblCSZ.Size = New System.Drawing.Size(129, 13)
        Me.lblCSZ.TabIndex = 2
        Me.lblCSZ.Text = "City, State and Zip Code:"
        '
        'lblComOrd
        '
        Me.lblComOrd.AutoSize = True
        Me.lblComOrd.Location = New System.Drawing.Point(95, 143)
        Me.lblComOrd.Name = "lblComOrd"
        Me.lblComOrd.Size = New System.Drawing.Size(106, 13)
        Me.lblComOrd.TabIndex = 3
        Me.lblComOrd.Text = "Computers Ordered:"
        '
        'lblMonOrd
        '
        Me.lblMonOrd.AutoSize = True
        Me.lblMonOrd.Location = New System.Drawing.Point(95, 173)
        Me.lblMonOrd.Name = "lblMonOrd"
        Me.lblMonOrd.Size = New System.Drawing.Size(95, 13)
        Me.lblMonOrd.TabIndex = 4
        Me.lblMonOrd.Text = "Monitors Ordered:"
        '
        'lblPrntOrd
        '
        Me.lblPrntOrd.AutoSize = True
        Me.lblPrntOrd.Location = New System.Drawing.Point(95, 203)
        Me.lblPrntOrd.Name = "lblPrntOrd"
        Me.lblPrntOrd.Size = New System.Drawing.Size(91, 13)
        Me.lblPrntOrd.TabIndex = 5
        Me.lblPrntOrd.Text = "Printers Ordered:"
        '
        'btnGenIn
        '
        Me.btnGenIn.Location = New System.Drawing.Point(23, 261)
        Me.btnGenIn.Name = "btnGenIn"
        Me.btnGenIn.Size = New System.Drawing.Size(287, 23)
        Me.btnGenIn.TabIndex = 6
        Me.btnGenIn.Text = "Generate Invoice"
        Me.btnGenIn.UseVisualStyleBackColor = True
        '
        'txtCusNam
        '
        Me.txtCusNam.Location = New System.Drawing.Point(179, 17)
        Me.txtCusNam.Name = "txtCusNam"
        Me.txtCusNam.Size = New System.Drawing.Size(131, 20)
        Me.txtCusNam.TabIndex = 7
        '
        'txtAdrs
        '
        Me.txtAdrs.Location = New System.Drawing.Point(179, 47)
        Me.txtAdrs.Name = "txtAdrs"
        Me.txtAdrs.Size = New System.Drawing.Size(131, 20)
        Me.txtAdrs.TabIndex = 8
        '
        'txtCSZ
        '
        Me.txtCSZ.Location = New System.Drawing.Point(179, 77)
        Me.txtCSZ.Name = "txtCSZ"
        Me.txtCSZ.Size = New System.Drawing.Size(131, 20)
        Me.txtCSZ.TabIndex = 9
        '
        'txtComOrd
        '
        Me.txtComOrd.Location = New System.Drawing.Point(229, 140)
        Me.txtComOrd.Name = "txtComOrd"
        Me.txtComOrd.Size = New System.Drawing.Size(81, 20)
        Me.txtComOrd.TabIndex = 10
        '
        'txtMonOrd
        '
        Me.txtMonOrd.Location = New System.Drawing.Point(229, 170)
        Me.txtMonOrd.Name = "txtMonOrd"
        Me.txtMonOrd.Size = New System.Drawing.Size(81, 20)
        Me.txtMonOrd.TabIndex = 11
        '
        'txtPrntOrd
        '
        Me.txtPrntOrd.Location = New System.Drawing.Point(229, 200)
        Me.txtPrntOrd.Name = "txtPrntOrd"
        Me.txtPrntOrd.Size = New System.Drawing.Size(81, 20)
        Me.txtPrntOrd.TabIndex = 12
        '
        'lstOut
        '
        Me.lstOut.Font = New System.Drawing.Font("Courier New", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lstOut.FormattingEnabled = True
        Me.lstOut.ItemHeight = 14
        Me.lstOut.Location = New System.Drawing.Point(351, 17)
        Me.lstOut.Name = "lstOut"
        Me.lstOut.Size = New System.Drawing.Size(336, 270)
        Me.lstOut.TabIndex = 13
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(700, 312)
        Me.Controls.Add(Me.lstOut)
        Me.Controls.Add(Me.txtPrntOrd)
        Me.Controls.Add(Me.txtMonOrd)
        Me.Controls.Add(Me.txtComOrd)
        Me.Controls.Add(Me.txtCSZ)
        Me.Controls.Add(Me.txtAdrs)
        Me.Controls.Add(Me.txtCusNam)
        Me.Controls.Add(Me.btnGenIn)
        Me.Controls.Add(Me.lblPrntOrd)
        Me.Controls.Add(Me.lblMonOrd)
        Me.Controls.Add(Me.lblComOrd)
        Me.Controls.Add(Me.lblCSZ)
        Me.Controls.Add(Me.lblAdrs)
        Me.Controls.Add(Me.lblCusNam)
        Me.Name = "frmMain"
        Me.Text = "Computers ‘R’ Us - Order Form"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents lblCusNam As Label
    Friend WithEvents lblAdrs As Label
    Friend WithEvents lblCSZ As Label
    Friend WithEvents lblComOrd As Label
    Friend WithEvents lblMonOrd As Label
    Friend WithEvents lblPrntOrd As Label
    Friend WithEvents btnGenIn As Button
    Friend WithEvents txtCusNam As TextBox
    Friend WithEvents txtAdrs As TextBox
    Friend WithEvents txtCSZ As TextBox
    Friend WithEvents txtComOrd As TextBox
    Friend WithEvents txtMonOrd As TextBox
    Friend WithEvents txtPrntOrd As TextBox
    Friend WithEvents lstOut As ListBox
End Class
