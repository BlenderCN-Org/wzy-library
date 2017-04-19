# 玩转 Bootstrap（JS插件）

#### 一次性导入

    <!—导入jQuery版本库，因为Bootstrap的JavaScript插件依赖于jQuery -->
    <script src="http://libs.baidu.com/jquery/1.9.0/jquery.js"></script>
    <!—- 一次性导入所有Bootstrap的JavaScript插件（压缩版本） -->
    <script src="js/bootstrap.min.js"></script>

#### 单独导入

- 动画过渡（Transitions）:对应的插件文件“transition.js”
- 模态弹窗（Modal）:对应的插件文件“modal.js”
- 下拉菜单（Dropdown）：对应的插件文件“dropdown.js”
- 滚动侦测（Scrollspy）：对应的插件文件“scrollspy.js”
- 选项卡（Tab）：对应的插件文件“tab.js”
- 提示框（Tooltips）：对应的插件文件“tooltop.js”
- 弹出框（Popover）：对应的插件文件“popover.js”
- 警告框（Alert）：对应的插件文件“alert.js”
- 按钮（Buttons）：对应的插件文件“button.js”
- 折叠/手风琴（Collapse）：对应的插件文件“collapse.js”
- 图片轮播Carousel：对应的插件文件“carousel.js”
- 自动定位浮标Affix：对应的插件文件“affix.js”

#### 模态弹出窗

- 声明式触发方法
    - 自顶两个属性：`data-toggle` & `data-target`
    - 使用链接 `<a>` 元素触发，使用 `href` 替代 `data-target`
    - 建议统一使用 `data-target` 来触发模态弹出窗
    - 动画过渡效果，增加类名 `fade`
- JavaScript触发方法

JavaScript 触发的模态弹出窗，代码示例：

    $(function(){
      $(".btn").click(function(){
        $("#idName").modal();
      });
    });
    //参数
    $(function(){
      $(".btn").click(function(){
        $("#idName").modal({
            keyboard:false
            });
      });
    });

#### 下拉菜单 Dropdown

- 被点击的菜单项链接或按钮需要添加自定义属性 data-toggle="dropdown"
- 如果触发下拉菜单的元素是一个链接元素，为了避免点击链接，页面跳到顶部，可以使用data-target="#"来替代href="#"
- 两种不同触发方式：
    - 直接声明触发：`data-toggle="dropdown"`
    - JS触发：`$function(){ $(".dropdown-toggle").dropdown(); }`

#### 滚动监控器

滚动监控器的设计步骤：

    1. 使用滚动监控器，首要的条件是在页面中加载对应的插件。在这里你可以加载合并好的bootstrap.js或者其独立的插件文件scrollspy.js
    2. 设计一个带有下拉菜单的导航条。分别为导航条和下拉菜单项定义一个锚点链接，锚点分别为“#blog”,“html”,“#css”,“#sass”,“#js”,“php”,“#about”。同时为导航条定义一个id值“navbar-menu”（id名称可自由定义），方便滚动监控
    3. 设计监控对象。这里将监控对象内容都放置在一个div名为scrollspy（这个类名可自由定义）的容器中，其中放了多个子内容框。每个子内容框有一个标题，而且每个标题的ID值与导航菜单项中的锚点链接名相对应，并且注意加入“data-target="#navbar-menu"”属性（这个属性值要与前面的nav标签的id名称保持一致）
    4. 为监控对象定义样式，设置容器scrollspy大小（设置高度目的是为了产生垂直滚动条）

#### 选项卡 Nav, Tabs

Bootstrap 框架中的选项卡主要有两部分：

- 选项卡组件（也就是菜单组件），对应的是 Bootstrap的 `nav-tabs`）
- 底部可以切换的选项卡面板，在 Bootstrap 中通常 `class="tab-pane"` 来表示
- 在添加 fade 样式时，最初的默认显示的内容面板一定要记得加上 in 类名，不然其内容用户无法看到
- `data-toggle` 触发：
    - nav-tabs 对应 `data-toggle="tab"`
    - nav-pills 对应 `data-toggle="pill"`

#### 提示框 Tooltip

- 通过 title 属性的值来定义提示信息(也可以使用自定义属性 data-original-title 来设置提示信息)。
- Bootstrap框架中的提示框的触发方式和前面介绍的插件略有不同。不能直接通过自定义的属性 data- 来触发。必须得依赖于JavaScript的代码触发

提示框 JS 最简单的触发方式：

    $(function(){
        $('[data-toggle="tooltip"]').tooltip();
    });

也可以单独指定一个元素，在该元素上调用提示框，并且可能通过JavaScript的各种参数来实现，无需定义一些 data 属性，如：

    $(function(){
        $('#myTooltip').tooltip({
           title:"我是一个提示框，我在顶部出现",
           placement:'top'
        });
    });

#### 弹出框 Popover

- 而弹出框Popover和提示框tooltip相比，就多了一个content内容
- 弹出框的制作结构和提示框并无太多差别，但样式上有比较大的区别，主要是定义了弹出框边框、圆角、背景、阴影以及三角形等样式

#### 提示框与弹出框的异同

- 提示框 tooltip 的默认触发事件是 hover 和 focus，而弹出框 popover 是 click
- 提示框 tooltip 只有一个内容(title)，而弹出框不仅可以设置标题（title）还可以设置内容(content)

提示框tooltip的模板：

    <div class="tooltip" role="tooltip">
        <div class="tooltip-arrow"></div>
        <div class="tooltip-inner"></div>
    </div>

弹出框popover的模板：

    <div class="popover" role="tooltip">
        <div class="arrow"></div>
        <h3 class="popover-title"></h3>
        <div class="popover-content"></div>
    </div>

#### 按钮插件 JavaScript用法

1. 切换按钮状态（得到焦点）：`$("#mybutton").button("toggle")`
2. 重新恢复按钮：`$("#mybutton").button("reset")`
3. 任意参数：`$("#mybutton").button("任意字符参数名")`

#### 图片轮播 Carousel

- 声明式：是通过定义 data 属性来实现
    - `data-ride` 属性：取值 carousel，并且将其定义在 carousel 上
    - `data-target` 属性：取值 carousel 定义的 ID 名或者其他样式识别符，如前面示例所示，取值为“#slidershow”，并且将其定义在轮播图计数器的每个 li 上
    - `data-slide` 属性：取值包括 prev，next，prev表示向后滚动，next 表示向前滚动。该属性值同样定义在轮播图控制器的 a 链接上，同时设置控制器 href 值为容器 carousel 的 ID 名或其他样式识别符
    - `data-slide-to` 属性：用来传递某个帧的下标，比如 data-slide-to="2"，可以直接跳转到这个指定的帧（下标从0开始计），同样定义在轮播图计数器的每个 li 上

#### Bootstrap 在线自定义设置

在Bootstrap框架的官网为大家提供了一个在线自定义 Bootstrap 框架的配置页面 http://getbootstrap.com/customize/　，可以通过这里进行配置。

在线自定义设置主要包括三个部分：

- Bootstrap 组件
- Bootstrap 插件
- Bootstrap 的 LESS 版本变量设置
