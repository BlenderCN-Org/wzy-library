# CSS 十天精通CSS3

#### 边框 圆角效果 border-radius

实心上半圆，实现方法：把高度(height)设为宽度（width）的一半，并且只设置左上角和右上角的半径与元素的高度一致（大于也是可以的）。

    div{
        height:50px;/*是width的一半*/
        width:100px;
        background:#9da;
        border-radius:50px 50px 0 0;/*半径至少设置为height的值*/
        }

#### 边框阴影 box-shadow

- 使用方法：`box-shadow: X轴偏移量 Y轴偏移量 [阴影模糊半径] [阴影扩展半径] [阴影颜色] [投影方式];`
- 注意：inset 可以写在参数的第一个或最后一个，其它位置是无效的
- 添加多个阴影，只需用逗号隔开即可
- 阴影模糊半径：此参数可选，其值只能是为正值，如果其值为0时，表示阴影不具有模糊效果，其值越大阴影的边缘就越模糊
- 阴影扩展半径：此参数可选，其值可以是正负值，如果值为正，则整个阴影都延展扩大，反之值为负值时，则缩小
- X轴偏移量和Y轴偏移量值可以设置为负数

#### 边框应用图片 border-image

- 语法：`border-image:url(xxx.jpg) 70 70 70 70 repeat;`
- 数字为切割图片的宽度，单位为像素，但省略 px 也可以使用百分比，遵循顺时针的规律来分别设置
- 图片延伸方式，三个可选参数分别为：
    - round，平铺
    - repeat，重复
    - stretch，拉伸

#### 渐变色彩

CSS3 Gradient 分为线性渐变(linear) 和径向渐变(radial)

- 语法：`linear-gradient(to bottom, #fff, #999)`
- 第一个参数：指定渐变方向，可以用“角度”或“英文”来表示
    - to top
    - to right
    - to bottom
    - to left
    - to top left
    - to top right
- 第二个和第三个参数，表示颜色的起始点和结束点，可以有多个颜色值

#### 文字与字体 text-overflow & word-wrap

- `text-overflow: clip / ellipsis`
    - clip：表示 剪切
    - ellipsis：表示显示，省略标记
- `word-wrap: normal / break-word`
    - 表示控制连续文本换行
    - 表示内容将在边界内换行

#### 嵌入字体 @font-face

    @font-face {
        font-family : 字体名称;
        src : 字体文件在服务器上的相对或绝对路径;
    }

#### 文本阴影 text-shadow

- `text-shadow: X-Offset Y-Offset blur color;`
    - X-Offset：表示阴影的水平偏移距离，其值为正值时阴影向右偏移，反之向左偏移   
    - Y-Offset：是指阴影的垂直偏移距离，如果其值是正值时，阴影向下偏移，反之向上偏移
    - Blur：是指阴影的模糊程度，其值不能是负值，如果值越大，阴影越模糊，反之阴影越清晰，如果不需要阴影模糊可以将Blur值设置为0(blur注意要加px单位)
    - Color：是指阴影的颜色，其可以使用rgba色

#### 背景

- `background-origin ： border-box / padding-box / content-box;`
- 需要注意的是，如果背景不是no-repeat，这个属性无效，它会从边框开始显示

`background-clip` 用来将背景图片做适当的裁剪以适应实际需要。语法：

- `background-clip ： border-box / padding-box / content-box / no-clip`
- 参数分别表示从边框、或内填充，或者内容区域向外裁剪背景。no-clip表示不裁切，和参数border-box显示同样的效果
- backgroud-clip默认值为border-box

`background-size` 设置背景图片的大小，以长度值或百分比显示，还可以通过 cover 和 contain 队图片进行伸缩

- `background-size: auto / <长度值> / <百分比> / cover / contain`
    - auto：默认值，不改变背景图片的原始高度和宽度；
    - <长度值>：成对出现如200px 50px，将背景图片宽高依次设置为前面两个值，当设置一个值时，将其作为图片宽度值来等比缩放；
    - <百分比>：0％~100％之间的任何值，将背景图片宽高依次设置为所在元素宽高乘以前面百分比得出的数值，当设置一个值时同上；
    - cover：顾名思义为覆盖，即将背景图片等比缩放以填满整个容器；
    - contain：容纳，即将背景图片等比缩放至某一边紧贴容器边缘为止。

#### 使用渐变与伪类选择器制作导航分隔线

    /*使用伪元素制作导航列表项分隔线*/
    .nav li{background:linear-gradient(to bottom,#dd2926,#a82724,#dd2926) no-repeat right / 3px 15px;}
    /*删除第一项和最后一项导航分隔线*/
    .nav li:last-child{background:none;}

#### 选择器

- `:root`：根选择器
- `:not`：否定选择器
    - 注意，`:not`需要紧跟在元素名后面，中间不能有空格
- `:empty`：空选择器，用来选择没有任何内容的元素，这里没有内容指的是一点内容都没有，哪怕是一个空格
- `:target`：目标选择器，用来匹配文档(页面)的url的某个标志符的目标元素
- `::selection`：伪类元素选择器用来匹配突出显示的文本(用鼠标选择文本时的文本)
- `:read-only`：伪类选择器用来指定处于只读状态元素的样式。简单点理解就是，元素中设置了“readonly=’readonly’”
- `:read-write`：指定当元素处于非只读状态时的样式
- `::before`和`::after`这两个主要用来给元素的前面或后面插入内容，这两个常和"content"配合使用，使用的场景最多的就是清除浮动

#### 变形与动画

- `-ms-transform`：-ms代表ie内核识别码
- `-moz-transform`：-moz代表火狐内核识别码
- `-webkit-transform`：-webkit代表谷歌内核识别码
- `rotate()`：旋转
- `skew()`：扭曲
- `scale()`：缩放
- `translate()`：位移
    -  translate的百分比是根据自身的宽度和高度来定的，`translate(-50%,-50%)` 配合 `top：50%，left：50%` 实现了居中
    - 当元素原来已经有position:absolute的时候，这时候你想相对于本身移动，可以使用translate
    - 做动画的时候translate更适合，不会引起页面的重排和重绘
    - 关于transform类的，可以使用GPU加速，提高浏览器的性能
- `matrix()`：是一个含六个值的(a,b,c,d,e,f)变换矩阵，用来指定一个2D变换，相当于直接应用一个[a b c d e f]变换矩阵。就是基于水平方向（X轴）和垂直方向（Y轴）重新定位元素
- `transform-origin`：中心点
- `transition-property`：就是通过鼠标的单击、获得焦点，被点击或对元素任何改变中触发，并平滑地以动画效果改变CSS的属性值


在CSS中创建简单的过渡效果可以从以下几个步骤来实现：

1. 在默认样式中声明元素的初始状态样式
2. 声明过渡元素最终状态样式，比如悬浮状态
3. 在默认样式中通过添加过渡函数，添加一些不同的样式

CSS3的过度transition属性是一个复合属性，主要包括以下几个子属性：

- `transition-property`:指定过渡或动态模拟的CSS属性
- `transition-duration`:指定完成过渡所需的时间
- `transition-timing-function`:指定过渡函数
- `transition-delay`:指定开始出现的延迟时间

特别注意：当“transition-property”属性设置为all时，表示的是所有中点值的属性

- `@keyframe animationName{...}`：关键帧
- `animation-name`属性主要是用来调用 `@keyframes` 定义好的动画
    - 调用动画语法：`animation-name: none | IDENT[,none|DENT]*;`
- `animation-duration`主要用来设置CSS3动画播放时间
    - 动画播放时间语法：`animation-duration: <time>[,<time>]*`
- `animation-timing-function`属性主要用来设置动画播放方式
- `animation-delay`属性用来定义动画开始播放的时间，用来触发动画播放的时间点
    - 语法规则：`animation-delay:<time>[,<time>]*`
- `animation-iteration-count`属性主要用来定义动画的播放次数
    - 语法规则：`animation-iteration-count: infinite | <number> [, infinite | <number>]*`
- `animation-direction`属性主要用来设置动画播放方向
    - 语法规则：`animation-direction:normal | alternate [, normal | alternate]*`
    - 主要有两个值：normal、alternate
        - normal是默认值，如果设置为normal时，动画的每次循环都是向前播放；
        - 另一个值是alternate，他的作用是，动画播放在第偶数次向前播放，第奇数次向反方向播放。
- `animation-play-state`属性主要用来控制元素动画的播放状态
    - 其主要有两个值：running(默认值)和paused
- `animation-fill-mode`属性定义在动画开始之前和结束之后发生的操作
    - 主要具有四个属性值：none、forwards、backwords和both

#### 布局样式

- 多列布局语法：`columns：<column-width>||<column-count>`
- 列宽：`column-width: auto|<length>`
- 列数：`column-count：auto|<integer>`
- 列间距：`column-gap: normal||<length>`
- 列表边框：`column-rule:<column-rule-width>|<column-rule-style>|<column-rule-color>`
- 跨列设置：`column-span: none | all`

#### 盒子模型

- W3C标准盒模型
    - 外盒尺寸计算（元素空间尺寸）
        - element空间高度＝内容高度＋内距＋边框＋外距
        - element空间宽度＝内容宽度＋内距＋边框＋外距
    - 内盒尺寸计算（元素大小）
        - element高度＝内容高度＋内距＋边框（height为内容高度）
        - element宽度＝内容宽度＋内距＋边框（width为内容宽度）
- box-sizing属性，能够事先定义盒模型的尺寸解析方式
    - 其语法规则如下：`box-sizing: content-box | border-box | inherit`
    - 属性：content-box, border-box, inherit

#### Media Queries

- 媒体类型：
    - All：所有设备
    - Braille：盲人用点字法触觉回馈设备
    - Embossed：盲文打印机
    - Handheld：便携设备
    - Print：打印用纸或打印预览视图
    - Projection：各种投影设备
    - Screen：电脑显示器
    - Speech：语音或音频合成器
    - Tv：电视机类型设备
    - Tty：使用固定密度字母栅格的媒介，比如电传打字机和终端
- 媒体类型常用的引用方法：
    - link标签
    - `@import`
    - `@media`
- Media Queries 使用方法：`@media 媒体类型 and (媒体特性){你的样式}`
- Media Queries 常用特性：
    - max-width：最大宽度
    - min-width：最小宽度
    - and：多个特性使用
    - device width：设备屏幕的输出宽度
    - not：取反操作
    - only：指定
- Media Queries在其他浏览器中不要像其他CSS3属性一样在不同的浏览器中添加前缀

#### Responsive

- 弹性图片：`img {max-width:100%;}`
- Responsive 布局技巧：
    - 尽量少用无关紧要的div
    - 不要使用内联元素（inline）
    - 尽量少用JS或flash
    - 丢弃没用的绝对定位和浮动样式
    - 摒弃任何冗余结构和不使用100%设置
- meta 标签被称为可视区域 meta 标签，使用方法为：`meta name="viewport" content="" />`

#### 用户界面与其他重要属性

- resize属性主要是用来改变元素尺寸大小的，其主要目的是增强用户体验，语法：`resize: none | both | horizontal | vertical | inherit`
- outline 外轮廓属性，外轮廓线不占用网页布局空间，不一定是矩形，外轮廓是属于一种动态样式，只有元素获取到焦点或者被激活时呈现
    - outline属性的基本语法：`outline: ［outline-color］ || [outline-style] || [outline-width] || [outline-offset] || inherit`
    - 
