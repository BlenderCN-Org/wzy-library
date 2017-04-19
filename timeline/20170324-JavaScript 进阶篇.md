# 慕课网 JavaScript进阶篇 学习笔记

HTML 引入外部的 JavaScript，语法：

    <script type="text/javascript" src="xxx.js"></script>

### 第 2 章 变量

声明变量语法：

    var 变量名;

### 第 3 章 数组

JavaScript 定义数组：

    var arr = new Array();
    arr[0] = 0;
    //可以指定长度
    var arr = new Array(8);

快速初始化数组的方法：

    //创建数组同时赋值
    var arr = new Array(0, 1, 2, 3, 4, 5);
    //直接输入一个数组（称 “字面量数组”）
    var arr = [0, 1, 2, 3, 4, 5];

引用数组的 length 属性可以获得数组的长度，即数组中元素的个数。语法：

    //获得数组myarray的长度
    myarray.length;

二维数组的定义方法（两层循环赋值）：

    var myarr=new Array();  //先声明一维
    for(var i=0;i<2;i++) {   //一维长度为2
        myarr[i]=new Array();  //再声明二维
        for(var j=0;j<3;j++) {   //二维长度为3
            myarr[i][j]=i+j;   // 赋值，每个数组元素的值为i+j
        }
    }

二维数组的定义方法（直接赋值）：

    var myarr = [[0,1,2], [0,1,2]];

### 第 5 章 函数

定义函数可以使用如下格式：

    function 函数名(参数1, 参数2) {
        函数代码
    }

### 第 6 章 事件

事件一般写在标签里

input 按钮示例：

    <input name="button" type="button" value="textContent" onclick="functionName()" />

事件有：

- `onmouseon`
- `onmouseout`
- `onfocus`: 当网页中的对象获得聚点时，执行 onfocus 调用的程序会被执行
- `onblur`: onblur 事件与 onfocus 是相对事件，当光标离开当前获得聚焦对象的时候，触发 onblur 事件，同时执行被调用的程序
- `onselect`: 选中事件，当文本框或者文本域中的文字被选中时，触发 onselect 事件，同时调用的程序就会被执行
- `onchange`: 通过改变文本框的内容来触发 onchange 事件，同时执行被调用的程序
- `onload`: 事件会在页面加载完成后，立即发生，同时执行被调用的程序
- `onunload`: 当用户退出页面时（页面关闭、页面刷新等），触发 onunload 事件，同时执行被调用的程序

onunload 代码示例：

    <script type="text/javascript">
        window.onunload = onunload_message;
        function onunload_message() {
            alert("Are you sure for leaving?");
        }
    </script>

获得输入框的值，注意后缀要加 `.value`

    var num1 = document.getElementById("inputBox").value;

输入框中获取的 value 都为字符串，所以如果要进行计算需要转置：

    parseInt(document.getElementById("inputBox").value);

### 第 7 章 JavaScript内置对象

- 访问对象属性的语法：`var objectName = [];`
- 访问对象的方法：`objectName.methodName()`

定义一个时间对象：`var Udate = new Date()`, 注意：使用关键字 new, Date() 的首字母必须大写。

- `get/setFullYear()`: 返回/设置年份，用四位数表示
- `getDay()`: 返回星期，返回的是 0-6 的数字，0 表示星期天
- `get/setTime()`: 返回/设置时间，单位毫秒数，计算从 1970 年 1 月 1 日零时到日期对象所指的日期的毫秒数

将目前日期对象的时间推迟 1 小时，代码如下：

    <script type="text/javascript">
        var mydate=new Date();
        document.write("当前时间："+mydate+"<br>");
        mydate.setTime(mydate.getTime() + 60 * 60 * 1000);
        document.write("推迟一小时时间：" + mydate);
    </script>

`charAt()`: 返回指定位置的字符。返回的字符是长度为 1 的字符串，语法：

    stringObject.charAt(index)

`indexOf()` 方法可返回某个指定的字符串值在字符串中首次出现的位置，语法：

    stringObject.indexOf(substring, startpos)

如果要检索的字符串值没有出现，则该方法返回 -1

`split()` 方法将字符串分割为字符串数组，并返回此数组，语法：

    stringObject.split(separator, limit)

如果把空字符串 `""` 用作 separator，那么 stringObject 中的每个字符之间都会被分割

`substring()` 方法用于提取字符串中介于两个指定下标之间的字符，语法：

    stringObject.substring(startPos, stopPos)

返回的内容是从 start 开始（包含 start 位置的字符）到 stop-1 处的所有字符，其长度为 stop 减 start

`substr()` 方法从字符串中提取从 startPos 位置开始的指定数目的字符串，语法：

    stringObject.substr(startPos, length)

`concat()` 方法用于连接两个或多个数组。此方法返回一个新数组，不改变原来的数组，语法：

    arrayObject.concat(array1, array2, ..., arrayN)

`join()` 方法用于把数组中的所有元素放入一个字符串。元素是通过指定的分隔符进行分隔的，语法：

    arrayObject.join(分隔符)

`reverse()` 方法用于颠倒数组中元素的顺序，语法：

    arrayObject.reverse()

`slice()` 方法可从已有的数组中返回选定的元素，语法：

    arrayObject.slice(start, end)

`sort()` 方法使数组中的元素按照一定的顺序排列，语法：

    arrayObject.sort(方法函数)
    //通过排序函数实现升序/降序
    <script type="text/javascript">
        function sortNum(a,b) {
            return a - b;
            //升序，如降序，把“a - b”该成“b - a”
        }
        var myarr = new Array("80","16","50","6","100","1");
        document.write(myarr + "<br>");
        document.write(myarr.sort(sortNum));
    </script>

### 第 8 章 浏览器对象

计时器 `setInterval()`，在执行时，从载入页面后每隔指定的时间执行代码，语法：

    setInterval(代码，交互时间);
    //交互时间以毫秒计

`clearInterval()` 方法可取消由 setInterval() 设置的交互时间，语法：

    clearInterval(id_of_setInterval)

`setTimeout()` 计时器，在载入后延迟指定时间后，去执行一次表达式，仅执行一次，语法：

    setTimeout(代码，延迟时间);

从窗口被打开的那一刻开始记录，每个浏览器窗口、每个标签页乃至每个框架，都有自己的 hitstory 对象与特定的 window 对象关联，语法：

    window.history.[属性|方法]
    //window可以省略

back() 方法加载 history 列表中的前一个 URL，语法：

    window.history.back();

back() 相当于 go(-1)

forward() 方法，加载 history 列表中的下一个 URL，语法：

    window.history.forward();

forward() 相当于 go(1)

window.screen 对象包含有关用户屏幕的信息：

- `screen.height` 返回屏幕分辨率的高
- `screen.width` 返回屏幕分辨率的宽

### 第 9 章 DOM

文档对象模型 DOM - Document Object Model

- `getElementById`
- `getElementsByName`： 注意，`getElementsByName` 中 Elements 有 s
- `getElementsByTagName`
- `getAttribute`
- `setAttribute()`: 语法：`elementNode.setAttribute(name,value)`

节点属性：

- `nodeName`
- `nodeValue`
- `nodeType`：
    - 如果节点是元素节点，则 nodeType 属性将返回 1
    - 如果节点是属性节点，则 nodeType 属性将返回 2

访问关联节点：

- `childNodes`
- `firstChild`
- `lastChild`
- `parentNode`: 父节点
- `elementNode.parentNode.parentNode`: 祖节点
- `nextSibling`: 返回某个节点之后紧跟的节点（处于同一树层级中）
- `previousSibling`: 返回某个节点之前紧跟的节点（处于同一树层级中）
- `appendChild(newnode)`
- `insertBefore(newnode,node)`: 在已有的子节点前插入一个新的子节点
- `removeChild()`: 从子节点列表中删除某个节点。如删除成功，此方法可返回被删除的节点，如失败，则返回 NULL
- `node.replaceChild(newnode, oldnew)`: 实现子节点（对象）的替换，返回被替换对象的引用
- `document.createElement(tagName)`: 创建元素节点，返回一个 Element 对象
- `document.createTextNode(data)`: 创建新的文本节点，返回新创建的 Text 节点

示例，div 标签内创建一个新的 P 标签：

    <div id="test"><p id="x1">HTML</p><p>JavaScript</p></div>
    <script type="text/javascript">
        var otest = document.getElementById("test");
        var newnode = document.createElement("p");
        newnode.innerHTML = "This is a new p";
        //appendChild方法添加节点
        otest.appendChild(newnode);
    </script>

示例，创建一个按钮：

    <script type="text/javascript">
       var body = document.body;
       var input = document.createElement("input");  
       input.type = "button";  
       input.value = "创建一个按钮";  
       body.appendChild(input);  
     </script>

浏览器尺寸：

- `window.innerHeight`
- `window.innerWidth`
- `document.documentElement.clientHeight`: HTML 文档所在窗口的当前高度
- `document.documentElement.clientWidth`: HTML 文档所在窗口的当前宽度
- `scrollHeight`, `scrollWidth`
- `offsetHeight`: = clientHeight + 滚动条 + 边框，`offsetWidth`: 获取网页内容高度和宽度（包括滚动条等边线，会随窗口的显示大小改变）

document 对象的 body 属性对应 HTML 文档的 <body> 标签：

- `document.body.clientHeight`
- `document.body.clientWidth`

- `scrollLeft`: 设置或获取位于给定对象左边界与窗口中目前可见内容的最左端之间的距离 ，即左边灰色的内容。
- `scrollTop`: 设置或获取位于对象最顶端与窗口中可见内容的最顶端之间的距离 ，即上边灰色的内容。
- `offsetLeft`: 获取指定对象相对于版面或由 offsetParent 属性指定的父坐标的计算左侧位置 。
- `offsetTop`: 获取指定对象相对于版面或由 offsetParent 属性指定的父坐标的计算顶端位置 。
