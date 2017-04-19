# 慕课网 JavaScript入门篇 学习笔记

### 1-9 JavaScript 什么是函数

先定义函数，在 input 中调用时，格式为 `onclick="function"`，注意函数名需要双引号

    <script>
        function add2() {
            sum = 5 + 6;
            alert(sum);
        }
        add2();
    </scipt>
    ...
    <input type="button" value="click" onclick="add2()">

### 第 2 章

- `confirm` 消息对话框通常允许用户做选择的动作，弹出对话框包括一个确定按钮和一个取消按钮。语法：`confirm(str)`
- `prompt` 弹出消息对话框，通常用于询问一些需要与用户交互的信息。弹出消息对话框包括一个确定按钮、取消按钮与一个文本输入框）。语法：`prompt(str1, str2)`
- `open()` 方法可以查找一个已经存在或者新建的浏览器窗口。语法：`window.open([URL], [窗口名称], [参数字符串])`
- `close()` 关闭窗口。语法:
    - `window.close();` //关闭本窗口
    - `<窗口对象>.close();` //关闭指定的窗口

### 第 3 章

- `innerHTML`属性用于获取或替换 HTML 元素的内容。语法：`Object.innerHTML`
- 改变 HTML 元素样式，语法：`Object.style.property=new style;`
- 通过 display 属性实现显示和隐藏的效果。语法：`Object.style.display = value`
