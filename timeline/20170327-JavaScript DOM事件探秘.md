# 慕课网 JavaScript DOM事件探秘 学习笔记

### DOM 2级 事件处理程序

DOM 2级事件定义了两个方法：用于处理指定和删除事件处理程序的操作 `addEventListener()` 和 `removeEventListner()`。接收三个参数：要处理的事件名、作为事件处理程序的函数和布尔值

### DOM 中的事件对象

1. type 属性，用于获取事件类型
2. target 属性，用于获取事件目标
3. stopPropagation()，用于阻止事件冒泡
4. preventDefault()，阻止事件的默认行为

### IE 中的事件对象

1. type 属性，用于获取事件类型
2. srcElement，用于获取事件的目标
3. cancelBubble，用于阻止事件冒泡
4. returnValue，阻止事件的默认行为
