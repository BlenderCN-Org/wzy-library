# JavaScript 网页定位导航特效

## 特效设计

#### scroll

- scroll([data], fn)：当用户滚动指定的元素时，会发生 scroll 事件
- scroll 事件适用于所有可滚动的元素和 window 对象（浏览器窗口）。例如，当页面滚动条变化时，执行函数，语法：`$(window).scroll(function(){});`
- scrollTop([val])：获取/设置匹配元素相对滚动条顶部的偏移
- offset()：获取匹配元素的相对偏移。返回的对象包含两个整形属性：top 和 left，以像素计

#### 编程技巧

- 列表简写：`ul>li*5>a`, 按 Tab 键(webstorm zencoding)
- 竖向选择：按住 alt/option 键


#### 右侧固定导航栏

	#menu {
		position: fixed;
		top: 100px;
		//先居中定位，然后根据content向右偏移
		left: 50%;
		margin-left: 400px;
		width: 80px;
	}
