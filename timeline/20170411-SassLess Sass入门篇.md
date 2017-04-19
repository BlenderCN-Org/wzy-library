# Sass 入门篇

#### CSS 预处理器

通俗的说，“CSS 预处理器用一种专门的编程语言，进行 Web 页面样式设计，然后再编译成正常的 CSS 文件，以供项目使用。CSS 预处理器为 CSS 增加一些编程的特性，无需考虑浏览器的兼容性问题”，例如你可以在 CSS 中使用变量、简单的逻辑程序、函数（如右侧代码编辑器中就使用了变量$color）等等在编程语言中的一些基本特性，可以让你的 CSS 更加简洁、适应性更强、可读性更佳，更易于代码的维护等诸多好处。

#### Sass 和 SCSS 的区别

Sass 和 SCSS 其实是同一种东西，我们平时都称之为 Sass，两者之间不同之处有以下两点：

1. 文件扩展名不同，Sass 是以“.sass”后缀为扩展名，而 SCSS 是以“.scss”后缀为扩展名
2. 语法书写方式不同，Sass 是以严格的缩进式语法规则来书写，不带大括号({})和分号(;)，而 SCSS 的语法书写和我们的 CSS 语法书写方式非常类似。

【我的一个不成熟的小观察】Sass 没有 `;`，没有 `{}`，直接采用缩进表示逻辑关系

#### 安装 Sass

- 先下载 ruby，然后打开 Ruby Command 窗口
- 输入 `gem install sass`
- 确认是否安装成功：`sass -v`
- 更新 Sass，`gem update sass`
- 卸载（删除）Sass：`gem uninstall sass`

在此特别提醒新同学：“.sass”只能使用 Sass 老语法规则（缩进规则），“.scss”使用的是 Sass 的新语法规则，也就是 SCSS 语法规则（类似 CSS 语法格式）。

#### Sass 编译的方法

- 命令编译
- GUI 工具编译
- 自动化编译

#### Sass 命令编译

单文件编译：

    sass <要编译的Sass文件路径>/style.scss:<要输出CSS文件路径>/style.css

多文件编译：

    sass sass/:css/

在编译 Sass 时，开启“watch”功能，这样只要你的代码进行任保修改，都能自动监测到代码的变化，并且给你直接编译出来：

    sass --watch <要编译的Sass文件路径>/style.scss:<要输出CSS文件路径>/style.css

简单示例，假设我本地有一个项目，我要把项目中“bootstrap.scss”编译出“bootstrap.css”文件，并且将编译出来的文件放在“css”文件夹中，我就可以在我的命令终端中执行：

    sass --watch sass/bootstrap.scss:css/bootstrap.css

GUI 界面工具编译：

- [Koala](http://www.w3cplus.com/preprocessor/sass-gui-tool-koala.html)
- [CodeKit](http://www.w3cplus.com/preprocessor/sass-gui-tool-codekit.html)

#### Sass 常见的编译错误

最为常见的一个错误就是<strong>字符编译</strong>引起的。在Sass的编译的过程中，是不是支持“GBK”编码的。所以在创建 Sass 文件时，就需要将文件编码设置为“utf-8”。<br/>
另外一个错误就是路径中的<strong>中文字符</strong>引起的。建议在项目中文件命名或者文件目录命名不要使用中文字符。<br/>
而至于人为失误造成的编译失败，在编译过程中都会有具体的说明，大家可以根据编译器提供的错误信息进行对应的修改。<br/>

#### Sass 不同输出方式的样式风格

- 嵌套输出方式 nested
    - 在编译的时候带上参数“ --style nested”
- 展开输出方式 expanded
    - 在编译的时候带上参数“ --style expanded”
- 紧凑输出方式 compact
    - 在编译的时候带上参数“ --style compact”
- 压缩输出方式 compressed
    - 在编译的时候带上参数“ --style compressed”

#### Sass 的调试

在浏览器中直接调试 Sass 文件，能找到对应的行数。值得庆幸的是，现在实现并不是一件难事，只要你的浏览器支持“sourcemap”功能即可。早一点的版本，需要在编译的时候添加“--sourcemap”  参数：

    sass --watch --scss --sourcemap style.scss:style.css

在 Sass3.3 版本之上（我测试使用的版本是 3.4.7），不需要添加这个参数也可以：

    sass --watch style.scss:style.css

在命令终端，你将看到一个信息：

    >>> Change detected to: style.scss
      write style.css
      write style.css.map

这时你就可以调试你的 Sass 代码。

#### 声明变量

Sass 的变量包括三个部分：

1. 声明变量的符号“$”
2. 变量名称
3. 赋予变量的值

声明变量示例：

    $brand-primary : darken(#428bca, 6.5%) !default; // #337ab7
    $btn-primary-color : #fff !default;
    $btn-primary-bg : $brand-primary !default;
    $btn-primary-border : darken($btn-primary-bg, 5%) !default;

如果值后面加上!default则表示默认值。

- sass 的默认变量一般是用来设置默认值，然后根据需求来覆盖的，覆盖的方式也很简单，只需要在默认变量之前重新声明下变量即可。
- 默认变量的价值在进行组件化开发的时候会非常有用。

#### 局部变量和全局变量

- 全局变量就是定义在元素外面的变量
- 当在局部范围（选择器内、函数内、混合宏内...）声明一个已经存在于全局范围内的变量时，局部变量就成为了全局变量的影子。基本上，局部变量只会在局部范围内覆盖全局变量

#### 什么时候声明变量

建议，创建变量只适用于感觉确有必要的情况下。不要为了某些骇客行为而声明新变量，这丝毫没有作用。只有满足所有下述标准时方可创建新变量：

1. 该值至少重复出现了两次；
2. 该值至少可能会被更新一次；
3. 该值所有的表现都与变量有关（非巧合）。

基本上，没有理由声明一个永远不需要更新或者只在单一地方使用变量。

#### 选择器嵌套

Sass 的嵌套分为三种：

1. 选择器嵌套
2. 属性嵌套(要加`:`)
3. 伪类嵌套

伪元素嵌套和属性嵌套非常类似，只不过他需要借助`&`符号一起配合使用

#### 混合宏 & 基础特性

- 在 Sass 中，使用“@mixin”来声明一个混合宏
- 可以在定义混合宏时带有参数
- 匹配了关键词“@include”来调用声明好的混合宏
- 当混合宏传的参数过多之时，可以使用参数 `...` 来替代
- Sass 在调用相同的混合宏时，并不能智能的将相同的样式代码块合并在一起。
- 通过关键词 “@extend”来继承已存在的类样式块，从而实现代码的继承
- 占位符 %placeholder 可以取代以前 CSS 中的基类造成的代码冗余的情形。
    - 因为 %placeholder 声明的代码，如果不被 `@extend` 调用的话，不会产生任何代码。
    - 通过 `@extend` 调用的占位符，编译出来的代码会将相同的代码合并在一起。这也是我们希望看到的效果，也让你的代码变得更为干净。
- 混合宏 vs 继承 vs 占位符
    - 混合宏：如果代码块中涉及到变量，建议使用混合宏来创建相同的代码块
    - 继承：如果代码块不需要传任何变量参数，而且有一个基类已在文件中存在，建议使用 Sass 的继承
- 使用 `#{}` 功能插值

#### 注释

- `//`：不会在被编译出来的 CSS 中显示
- `/* */`：会在编译出来的 CSS 中显示

#### 除法

Sass 中除法需要使用小括号，但如果已存在数学表达式，变量则会被识别为除法
