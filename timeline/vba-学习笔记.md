##VBA 学习笔记

###第二讲 VBA语句对象方法属性

####VBA语句

一. 宏程序语句: 运行后可以完成一个功能</br>

	Sub test_0()   //开始语句
		Range("a1") = 100
	End Sub   //结束语句

二. 函数程序语句: 运行后可以返回一个值</br>

	Funciton shcount()
		shcount = Sheets.Count
	End Function

三. 在程序中应用的语句

	Sub test_1()
		Call test
	End Sub

	Sub test_2()
		For x = 1 To 100   //for next 循环语句
			Cells(x,1) = x
		Next x
	End Sub

####VBA对象

VBA中的对象其实就是我们操作的具有方法、属性的excel中支持的对象</br>
Excel中的常用对象表示方法:

一. 工作簿

- `Workbooks`代表工作簿集合，所有的工作簿，`Workbooks(N)`表示已打开第N个工作簿
- `Workbooks("工作簿名称")`
- `ActiveWorkbook`正在操作的工作簿
- `ThisWorkBook`代码所在的工作簿

二. 工作表

- `Sheets("工作表名称")`
- `Sheet1`表示第一个插入的工作表，`Sheet2`表示第二个插入的工作表...
- `Sheets(n)`表示按排列顺序，第n个工作表
- `ActiveSheet`表示活动工作表，光标所在工作表
- `worksheet`也表示工作表，但不包括图标工作表、宏工作表等

三. 单元格

- `cells`所有单元格
- `Range("单元格地址")`
- `Cells(行数,列数)`(注:不用加双引号)
- `Activecell`正在选中或编辑的单元格
- `Selection`正被选中或选取的单元格或单元格区域

####VBA属性

VBA属性就是VBA对象所具有的特点，表示某个对象的属性的方法是`对象.属性=属性值`。

	Sub test_0()
		Range("a1").Value = 100
	End Sub

	Sub test_1()
		Sheets(1).Name = "工作表改名"
	End Sub

	Sub test_2()
		Sheets("Sheet2").Range("a1").Value = "abcd"
	End Sub

	Sub test_3()
		Range("A2").Interior.ColorIndex = 3
	End Sub

####VBA方法

VBA方法是作用于VBA对象上的动作，表示用某个方法作用于VBA的对象上，可以用以下格式: `对象.方法 参数名称:=参数值`。

	Sub test_0()
		Range("a1").Copy Destination:=Range("a2")
		//Range("A1").Copy Range("A2")
	End Sub

	Sub test_1()
		Sheet1.Move.before:=Sheets("Sheet3")
	End Sub

###第三讲 判断语句

If判断语句

	Sub 单条件判断()
		If Range("a1").Value>0 Then
			Range("b1") = "正数"
		Else
			Range("b1") = "负数或0"
		End IF
	End Sub

	Sub 多条件判断_0()
		If Range("a1").Value > 0 Then
			Range("b1") = "正数"
		ElseIf Range("a1") = 0 Then
			Range("b1") = "等于0"
		Else 
			Range("b1") = "负数"
		End If
	End Sub

	Sub 多条件判断_1()
		If Range("a1") <> "" And Range("a2") <> "" Then
			Range("a3") = Range("a1")*Range("a2")
		End If
	End Sub

Select判断

	Sub 单条件判断()
		Select Case Range("a1").Value
		Case Is>0
			Range("b1") = "正数"
		Case Else
			Range("b1") = "负数或0"
		End Select
	End Sub

	Sub 多条件判断()
		Select Case Range("a1").Value
		Case Is>0
			Range("b1") = "正数"
		Case Is=0
			Range("b1") = "等于0"
		Case Else
			Range("b1") = "负数"
		End Select
	End Sub

IFF函数判断

	Sub 判断()
		Range("a3") = IIf(Range("a1")<=0,"负数或零","正数")
	End Sub

区间判断

	Sub if区间判断()
		If Range("a1") <= 1000 Then
			Range("b2") = 0.01
		ElseIf Range("a1") <= 3000 Then
			Range("b2") = 0.03
		ElseIf Range("a1") > 3000 Then
			Range("b2") = 0.05
		End If
	End Sub

	Sub select区间判断()
		Select Case Range("a1").Value
		Case 0 To 1000
			Range("b2") = 0.01
		Case 1001 To 3000
			Range("b2") = 0.03
		Case Is>3000
			Range("b2") = 0.05
		End Select
	End Sub

###第四讲 循环语句

	Sub for循环_0()
	Dim x As Integer
		For x = 2 To 6 Step 2   //Step 1时一般可省略
			Range("d" & x) = Range() * Range("c" & x)
		Next x
	End Sub

	Sub for循环_1()
	Dim rg As Range
		For Each rg In Range("d2:d18")
			rg = rg.Offset(0,-1) * rg.Offset(0,-2)
		Next rg
	End Sub

	Sub do-loop-until循环()
	Dim x As Integer
		x = 1
		Do
			x = x + 1
			Cells(x,4) = Cells(x,2) * Cells(x,3)
		Loop Until x = 18
	End Sub

	Sub do-while循环()
	Dim x As Integer
		x = 1
		Do While x < 18
			x = x + 1
			Cells(x, 4) = Cells(x, 2) * Cells(x, 3)
		Loop
	End Sub

	Sub 给空值赋值0()
		Dim rg As Range
		For Each rg In Range("a1:b7, d5:e9")
			If rg = "" Then
				rg = 0
			End If
		Next rg
	End Sub

	Sub 查找断点()
		Dim x As Integer
		Do
			x = x + 1
			If Cells(x+1, 1) <> Cells(x, 1)+1 Then
				Cells(x, 2) = "断点"
				Exit Do   //退出循环
			End If
		Loop Until x = 14
	End Sub