##《Head First JavaScript》读书笔记

[Head First JavaScript Lab](https://www.headfirstlabs.com/books/hfjs/)

###目录

1. 交互式网络：感觉虚拟世界
2. 存储数据：每项事物都有自己的位置
3. 探索客户端：浏览器探索
4. 决策：前有岔路，面对抉择
5. 循环：自我重复的风险
6. 函数：简化、重复利用、回收再利用
7. 表单与验证：让用户全盘托出
8. 驾驭网页：利用DOM分割HTML
9. 为数据带来生命：科学对象怪人
10. 创建自定义对象：自定义对象让你为所欲为
11. 除错务尽：好脚本也会出错
12. 动态数据：贴心易感的网络应用程序

###第一章 交互式网络

HTML 的任何地方都可以安插 `<script>` 标签，但最好放在网页的 `<head>` 区域

例如：

	<html>
		<head>
			<title>House Finder</title>

			<script type="text/javascript">
				function validateNumber(value) {
					//Validate the number
						if (!isNumber(value))
					alert("Please enter a number.");
				}
			</script>

alert 函数

	alert ('Text to display');

要点：

1. 事件以 JavaScript 代码响应网页里发生的动静
2. `onload` 事件在网页载入完毕后触发
3. 设定 `<body>` 标签的 `onload` 属性，即可对 `onload` 事件有所响应
4. 函数把 JavaScript 打包为可重复利用的模块
5. 有些函数需要我们把信息传过去，才能完成任务
6. `alert()` 是个 JavaScript 内置函数，负责在弹出的对话框中呈现文字信息

###第二章 存储数据

JavaScript 使用三种基本数据类型：text, number, boolean

在脚本的执行过程中，变量(variable)会改变，常量(constant)的值则永不改变

变量，是存储器里附有独一无二名称(unique name)的存储位置(storage location)

建立变量：

	var Variable_name;

变量初始化(initializing):

	var Variable_name = Initial_value;

常量初始化：

	const Constant_name = Constant_value;

要点：

1. 脚本通常能以下列三种基本数据类型表示：文本，数字，布尔
2. 变量是可能在脚本执行过程中改变的数据
3. 常量是不会改变的数据
4. 关键字 `var` 用于创建变量，关键字 `const` 用于创建常量
5. JavaScript 数据的数据类型在设定数据为特定值的同时建立。另外，变量值的类型可以改变

驼峰型（首字母也大写）只会用于对象，小写驼峰型则用于变量和函数

文本转换为数字：

1. `parseInt()` 把字符串传给函数，函数就把字符串转换为整数
2. `parseFloat()` 把字符串传给函数，函数就把字符串转换为（十进位）浮点数


要点：`NaN` 代表非数字，也用于指出某段数据不是数字（当它期待中应该是数字时）

`getElementById()` 方法可返回对拥有指定 ID 的第一个对象的引用，语法：

	document.getElementById(id_name)
	document.getElementById(id_nane).value

JavaScript 取得网页元素的关键，就是 HTML 标签里的 id 属性，例如：

	<input type="text" id="id_name" name="id_name" />

就技术而言，`getElementById()` 是个 document 对象里的方法（method），而不是函数

对象是种先进的 JavaScript 数据类型，它能结合函数、常量与变量为一个逻辑实体(logical entity)。方法(method) 其实是属于某对象的函数，特性(property) 则是对象里的常量或变量。在实现层面上，JavaScript 几乎使用对象表达一切。

###第三章 浏览器探索

在 JavaScript 里设定定时器有两个关键：

1. 建立时间延迟(time delay)
2. 让定时器知道时限来临时该运行的程序代码

单次定时器(one-shot timer) 只会触发一次程序代码。间隔定时器(interval timer) 设定多段间隔，而不只设定一次时间延迟。间隔定时器每隔一段时间，即重复调用 "定时器代码"

制作（单次）定时器的 JavaScript 内置函数被称为 setTimeout()。例如：
	
	setTimeout("alert('Wake up!');", 600000);
	//JavaScript 代码需为字符串型，所以放在一对引号内
	//不管数字多大，都别在 JavaScript 的数值中加入逗号

setTimeout() 函数的一般形式：

	setTimeout (Timer_code, Timer_delay);

间隔定时器调用 `setInterval()` 函数，设定间隔定时器，即可于每次间隔延迟到期时反复运行程序代码，例如：

	var timerID = setInterval("alert('Wake up!');", 600000);

注意：延迟时间必以毫秒设定

调用 location 对象的 `reload()` 方法可以重新载入整个网页，代码如下：

	location.reload();

`clearInterval()` 函数用于清除 `setInterval()` 设置的间隔定时器。`clearInterval()` 函数需要我们传入间隔定时器的 id，id 则于创建定时器的同时，由 `setInterval()` 返回。存储了 `setInterval()` 返回的值（例如存到变量 timerID），再把这个zhi传给 `clearInterval()`，就能清楚定时器了，如下：

	clearInterval(timerID);

document 对象代表网页本身，利用同一个对象的 `getElementById()` 方法可取得网页元素。document 对象的 `body.clientWidth` 与 `body.clientHeight` 特性里存储了客户端窗口的宽度与高度

浏览器(browser) 意指网络客户端(web client)，因为它在网页的提供路径上处于客户端。但在浏览器环境里，客户端(client) 则表示浏览器窗口里_呈现网页_的特定区域。客户端窗口位于浏览器窗口里，并未包含标题栏、工具栏、滚动条等其他事物

resizeRock() 的程序代码，根据客户端窗口的尺寸，缩放图片（宠物石）的大小。另外，在 onload 事件处理器中，除了 greetUser()，还加入对 resizeRock() 的调用：

		function resizeRock() {
			document.getElementById("rockImg").style.height = (document.body.clientHeight - 100)*0.9;
		}
	...
	<body onload="resizeRock(); greetUser();"
		...
	</body>

要点：

1. `setTimeout()` 函数创建单次定时器，这种定时器将于一段时限后触发 JavaScript 代码
2. 设定依固定间隔启动的定时器，使用 `setInterval()` 创建间隔定时器
3. 必以毫秒(millisecond) 为指定定时器时限的单位，1 毫秒为千分之一秒
4. 网页元素具有设定样式的 style 对象，width、height 都是样式
5. 客户端窗口是浏览器窗口的一部分，只负责呈现网页，其他不关它的事
6. 可以通过 document 对象的 `body.clientWidth` 与 `body.clientHeight` 特性，取得客户端窗口的宽与高

`onresize` 与 `onclick` 均由用户触发，但 `onload` 则不然

JavaScript 于浏览器关闭或网页重新载入时摧毁 "所有" 变量

把 cookie.js 导入到网页里：

	<script type="text/javascript" src="cookie.js"></script>

下例包含三个处理 cookie 的协助函数，分别是写入、读取、清除 cookie：

	//有效日期，表示为 cookie 可以存在的天数
	function writeCookie(name, value, days) {
	  // By default, there is no expiration so the cookie is temporary
	  var expires = "";

	  // Specifying a number of days makes the cookie persistent
	  if (days) {
	    var date = new Date();
	    //计算有效日期时，需把天数换算为毫秒数再把毫秒数加到当前时间上
	    date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
	    expires = "; expires=" + date.toGMTString();
	  }

	  // Set the cookie to the name, value, and expiration date
	  document.cookie = name + "=" + value + expires + "; path=/";
	}

	function readCookie(name) {
	  // Find the specified cookie and return its value
	  var searchName = name + "=";
	  //cookie 列表使用分号区隔各个 cookie
	  var cookies = document.cookie.split(';');
	  for(var i=0; i < cookies.length; i++) {
	    var c = cookies[i];
	    while (c.charAt(0) == ' ')
	      c = c.substring(1, c.length);
	    if (c.indexOf(searchName) == 0)
	      return c.substring(searchName.length, c.length);
	  }
	  return null;
	}

	function eraseCookie(name) {
	  // Erase the specified cookie
	  //清除 cookie 的方式，就是把它改成没有值，而且有效日期已经过去(-1 天)
	  writeCookie(name, "", -1);
	}

要点：

1. cookie 是一块文本数据，由用户计算机上的浏览器下令存储
2. cookie 让脚本存储的数据能存活超过单一网络 session
3. 每个 cookie 都有有效日期，超过期限，浏览器随即清除 cookie
4. 把脚本移动到外部文件，是个让程序更容易重复利用和维护的便利方式
5. cookie 不能访问用户的硬盘或散布病毒，但可以存储输入网页上的个人数据

`navigator.cookieEnabled` 可供检查 cookie 支持的特性

###第四章 决策

if 语句：

	if (Test-condition)
		Statement;

if/else 语句

	if (Test-condition)
		Statement1;
	else
		Statement2;

JavaScript 多行注释：

	/* Start-of-comment
		More-comment
		End-of-comment */

switch/case 语句一般格式

	switch (Test-data) {
		case Match1:
			Statement;
			...
			break;
		...
		default:
			Statement;
			...
			break;
	}

###第五章 循环

for 循环格式：
	
	for (Init; Test; Update)
		Action;	

要点：

1. 数组能把多段数据存储在同一个地方
2. 虽然数组存储了多段信息，但只有一个变量名称
3. 索引数组通过称为索引(index) 的数值键访问

while 循环格式：

	Init;
	while (Test) {
		Action;
		Update;
	}

###第六章 函数

最基本的 JavaScript 函数语法：

	function Name() {
		Body
	}

数据通过函数的自变量(argument) 传入 JavaScript 函数：

	function Name(Arguments) {
		Body
	}

要点：

1. 函数提供了分离脚本任务的机制，而后再以可再利用的程序代码块予以统合
2. 函数是种削减重复代码的极佳方式，因为函数里的程序代码能依你的意愿尽情重复使用
3. 自变量让你传递数据至函数里，作为既定任务的输入

要点：

1. `return` 语句让函数返回数据给调用函数的代码
2. 函数返回一段数据时，数据将被放到调用函数的代码中国年
3. 函数只能返回一块数据
4. `return` 语句亦可不与任何数据同用，单纯用于提早结束函数

构成元件：独一无二的标示符（函数名称）、值（函数主体）。当函数主体单独出现而没有名称时，又被称为函数字面量(function literal)

函数引用提供联结事件处理函数与事件的便利方式

函数字面量让你创建匿名事件处理函数

要点：

1. 回调函数被浏览器调用，以响应发生在脚本外的事情
2. 函数引用能像变量般指派函数
3. 函数引用让我们联结 JavaScript 代码设计的事件处理函数，而不需改动 HTML 代码
4. 函数字面量为无名函数，在不需要有名称的函数时非常方便

每个表单域都有一个 `form` 对象，可被传给任何验证表单数据的函数：

	<input id="zipcode" name="zipcode" type="text" size="5" onclick="showIt(this.form)" />

`form` 对象厉害的地方在于它也是个数组，负责存储表单中所有域。但它的数组元素并非利用数值索引存储，而是使用域独有、于 name 属性设定的标示符。

`onblur` 其实是 `onfocus` 的相反事件。如果 `onfocus` 在元素或表单域取得输入焦点时触发，`onblur` 则于域失去焦点时被触发。

确认域是否并非无物：

	
	//调用 validateNonEmpty() 函数来响应 onblur 事件，以检查域是否并非无物
	onblur="validateNonEmpty(this)";

非无物验证

	/* 首先确认 helpText 元素的存在 (helpText!=null)
	   再把辅助信息指定给 innerHTML 特性 */
	if (helpText != null)
		helpText.innerHTML = "Please enter a value.";

要点：

1. 每个表单域可作为 JavaScript 对象而被访问
2. 在表单域对象里有个 `form` 特性，使用数组表示了整份表单的域
3. `onblur` 事件于输入焦点离开某个域时发生，它是触发数据验证函数的绝佳方式
4. 被动式验证辅助比较直觉，也比较不会骚扰用户
5. 字符串 length 特性可显示字符串包含的字符数量

`isNaN()` 函数可检查值是否 "不为数字"

正则表达式(regular expression) 专门设计用于匹配(match) 文本模式(pattern)

正则表达式总是以斜线起始和结束：

	/Expression/

正则表达式元字符：

1. `.`: 匹配任何字符，换行符(newline) 除外
2. `\d`: 匹配任何数字字符
3. `\w`: 匹配任何字母数字(字母或数字)字符
4. `\s`: 匹配空格
5. `\^`: 字符串需以模式起始
6. `$`: 字符串需以模式结束

限定符(quantifier)，限定符前为子模式(sub-pattern)，限定符即应用在子模式，并控制子模式出现在模式里的次数

1. `*`: 限定符前的子模式必须出现 0 或多次
2. `+`: 限定符前的子模式必须出现 1 或多次
3. `?`: 限定符前的子模式必须出现 0 或 1 次
4. `{n}`: 限定符前的子模式必须出现恰好 n 次
5. `()`: 集合字符或 / 和元字符，成为子模式

`RegExp` 对象的 `test()` 方法用于检查字符串是否包含正则表达式模式

要点：

1. JavaScript 通过内置 `RegExp` 对象而支持正则表达式，但正则表达式通常建立为 literal，所以很少见到这个对象
2. `RegExp` 对象的 `test()` 方法用于对字符串应用正则表达式模式的检测

元字符选替(alternation) 跟 JavaScript 的 OR 逻辑运算符非常像。选替只用到一个 `|`，而且它的功能是让模式指定一连串可供选择的子模式。换句话说，这些可供选择的子模式中，只要有一个匹配成功，就算模式匹配成功。

在正则表达式的模式中，字符类提供控制可选字符的有效率方式

字符类：`[CharacterClass]`，字符类是一组匹配单一字符的正则表达式规则

正则表达式特殊字符需要转义，才能把实际字符放在正则表达式里。下列字符前均需加上反斜线`\` 做转义: `[, \, ^, $, ., |, ?, *, +, ()`.

###第八章 驾驭网页

同一个网页上的各个元素 ID 应该有独特性

`getElementsByTagName()` 能抓出网页上所有特定类型的元素，如 div 或 img，这个方法返回的结果数组里，包含出现在网页上的每一个指定元素，并按照出现在 HTML 的顺序排列，例如

	var divs = document.getElementsByTagName("div");
	document.getElementsByTagName("img")[3]

innerHTML 特性对所有存储在元素里的内容提供了访问管道

想设定元素的 inner HTML，该元素必须能够包含 HTML 的内容。所以 innerHTML 特性实际上用于设置内容类元素，例如 div、span、p，以及其他装载内容的元素

设置元素内容时，innerHTML 特性一定完全改写任何原有内容，所以它没有附加(appending) 的概念。不过，附加的效果可借由串联新内容至旧内容上，然后指定串联结果给 innerHTML 而达成，如下：

	elem.innerHTML += " This sentence gets appended.

节点特性：

1. `nodeValue`: 存储于节点的值，只限文本与属性节点使用(不含元素)
2. `childNodes`: 包含节点下所有子节点的数组，以出现在 HTML 代码中的顺序而排列
3. `nodeType`: 节点类型，例如它是 DOCUMENT 或 TEXT 等，但以代号表示
4. `firstChild`: 节点下的第一个子节点
5. `lastChild`: 节点下的最后一个子节点

改变节点文本的(安全)三步骤：

1. `removeChild()`: 移除目标节点下的一个子节点，传入将被移除的子节点
2. `createTextNode()`: 从文本字符串创建文本节点
3. `appendChild()`: 以最后一个子节点的形式加入新节点，传入将被新增的子节点

例如：

	var node = document.getElementById("story");
	while (node.firstChild)
		node.removeChild(node.firstChild);
	node.appendChild(document.createTextNode("OK, maybe you are alone."));

要点：

1. innerHTML 虽非万维网的标准，但这个特性能访问元素内存储的所有内容
2. Document Object Model（文档对象模型），简称 DOM，提供访问和修改网页数据的标准化机制
3. DOM 视网页为关联节点的层次树
4. 使用 DOM（而非 innerHTML）改变网页内容的方案，需移除元素下所有子节点，然后创建并附加上包含新内容的新子节点

决策元素需要并排呈现，不能是需要换行的块元素(block element)。`div` 是个块元素，但 `span` 则是行内元素(inline element)。决策需要行内元素，所以采用 `span`

节点的 style 特性提供对单一样式特性的访问

要点：

1. 借由改变节点的整份样式类，`className` 节点特性达成戏剧性的样式变化
2. 借由访问节点的单一样式特性，`style` 节点特性达成少量样式变化
3. CSS 样式类与 JavaScript 类完全无关——它们是完全不同的东西
4. 网页元素可利用元素对象的 `visibility` 样式特性做动态的显示或隐藏

`createElement()` 可创建任何 HTML 元素，`createTextNode()` 可以加入新的文本内容

要点：

1. 利用 document 对象的 createElement() 方法，能够创建任何 HTML 元素
2. 若需新增元素的文本内容，必须创建一个文本内容子元素，并附加至元素下
3. 借由小心地新增与移除 DOM 树上的节点，网页可以随意拆解与重组

###第九章 为数据带来生命

对象在一个存储容器内链接变量与函数

当变量与函数被放在对象里，它们都被当成对象成员(object member)。更详细地说，变量称为对象的特性(property)，函数则称为对象的方法(method)。

对象中的特性与方法等于对象外的变量与函数

	Object.Property/Method

点号运算符引用来自对象的特性或方法

要点：

1. 对象是种特殊的数据结构，结合了数据与依据数据行动的程序代码
2. 实际上，对象只是结合成单一结构体的变量和函数
3. 当变量被放在对象里时，它称为特性；当函数被放在对象里时，它称为方法
4. 引用特性和方法时需提供对象的名称，后随点号运算符，再接上特性或方法的名称

一个自定义对象，让两块博客数据结为单一实体

构造函数(constructor) 负责创建对象

`this` 是 JavaScript 的关键字，用于饮用对象。`this` 从对象内部引用同一个对象。`this` 指出对象的所有权。

内置 Date 对象可表达时间里的瞬间

在 Date 对象里，时间以毫秒数表达

`new` 运算符在构造函数的协助下创建对象

要点：

1. 标准的 JavaScript `Date` 对象，以毫秒表达瞬间
2. `Date` 对象具有一些访问各部分时间值的方法
3. `Date` 对象聪明到能够对日期做四则运算，还有比较日期
4. 与大部分对象相同(`String` 对象除外)，`Date` 对象需以 `new`  运算符创建

`toString()` 方法提供对象的字符串表现方式。

访问日期格式的片段

1. `getMonth()`：访问月
2. `getDate()`：访问日
3. `getFullYear()`：访问年

string 的 method：

1. `length`：字符串里的字符数量
2. `indexOf()`：寻找字符串是否包含特定子字符串
3. `charAt()`：寻找特定字符在字符串里的位置
4. `toLowerCase()/toUpperCase()` 转换字符串为小写/大写

###第十章 创建自定义对象

对象类是种模板，对象实例则是根据模板创建的事物。

关键字 this 用于设置实例拥有的特性和方法。

方法存储在类里，让所有实例共享一份方法代码。

要点：

1. 类是对象的描述，实例则是实际的对象，根据对象描述所创建
2. 类勾画了对象的特性与方法，实例则把真正的数据放在特性里以供方法利用
3. 关键字 this 用于从实例本身的程序代码内访问实例
4. prototype 对象让方法可存储于类内，以免实例不必要地一直复制程序代码

类特性在类里存储一次，但能被所有实例访问。

就 Blog 对象而言，图像只是个字符串。

###第十一章 除错务尽		

要点：

1. 虽然大多数浏览器都提供了错误控制台（记录 JavaScript 的错误），但并非完全准确，你不能全盘相信它们
2. 虽然浏览器通常产生不完全的错误信息，但通常都会提供寻找问题的线索
3. 围起代码块的大括号，是个常见的缺陷起源——请小心，务必确认起始与结尾括号成对出现

转义符用在字符串中表示实际字符。

alert 框可作为快速查看变量值的便利工具

要点：

1. 语法错误关系到程序代码违反了 JavaScript 的语言规则，通常能被 JavaScript 解释器捕捉
2. 字符串必须小心地以成对引号或撇号围起
3. 在 HTML 事件处理器的属性里包含 JavaScript 代码时，应小心混用引号与撇号
4. 对于 “在脚本中观察变量”，alert 框提供了初级但好用的选项
5. 常见的错误：不小心把测试条件里的 == 写成 =

503/628






































