# Sass进阶篇

#### `@for` 循环

`@for` 循环有两种方式：

    @for $i from <start> through <end>
    @for $i from <start> to <end>

- $i 表示变量
- start 表示起始值
- end 表示结束值
- 区别是关键字 through 表示包括 end 这个数，而 to 则不包括 end 这个数

#### `@each` 循环

`@each` 循环就是去遍历一个列表，然后从列表中取出对应的值。`@each` 循环指令的形式：

    @each $var in <list>

#### Sass 函数功能

- 字符串函数
    - `unquote($string)`：删除字符串中的引号
        - `unquote()` 函数只能删除字符串最前和最后的引号（双引号或单引号），而无法删除字符串中间的引号。如果字符没有带引号，返回的将是字符串本身
    - `quote($string)`：给字符串添加引号
        - `quote()` 函数只能给字符串增加双引号
        - 字符串中间有单引号或者空格时，需要用单引号或双引号括起，否则编译的时候将会报错
        - `quote()` 碰到特殊符号，比如： `!、?、>` 等，除中折号 `-` 和 下划线 `_` 都需要使用双引号括起，否则编译器在进行编译的时候同样会报错
    - `To-upper-case()` 函数将字符串小写字母转换成大写字母
    - `To-lower-case()` 函数 与 `To-upper-case()` 刚好相反，将字符串转换成小写字母
- 数字函数
    - `percentage($value)`：将一个不带单位的数转换成百分比值
    - `round($value)`：将数值四舍五入，转换成一个最接近的整数
    - `ceil($value)`：将大于自己的小数转换成下一位整数
    - `floor($value)`：将一个数去除他的小数部分
    - `abs($value)`：返回一个数的绝对值
    - `min($numbers…)`：找出几个数值之间的最小值
        - 在 min() 函数中同时出现两种不同类型的单位，将会报错误信息
    - `max($numbers…)`：找出几个数值之间的最大值
    - `random()`: 获取随机数
- 列表函数
    - `length($list)`：返回一个列表的长度值
        - `length()` 函数中的列表参数之间使用空格隔开，不能使用逗号，否则函数将会出错
    - `nth($list, $n)`：返回一个列表中指定的某个标签值
    - `join($list1, $list2, [$separator])`：将两个列给连接在一起，变成一个列表
        - `join()` 只能将两个列表连接成一个列表，如果直接连接两个以上的列表将会报错
        - `join()` 函数中还有一个很特别的参数 `$separator`，这个参数主要是用来给列表函数连接列表值是，使用的分隔符号，默认值为 auto
        - `$separator` 除了默认值 auto 之外，还有 comma 和 space 两个值，其中 comma 值指定列表中的列表项值之间使用逗号（,）分隔，space 值指定列表中的列表项值之间使用空格（ ）分隔
    - `append($list1, $val, [$separator])`：将某个值放在列表的最后
        - 如果列表只有一个列表项时，那么插入进来的值将和原来的值会以空格的方式分隔
        - 如果列表中列表项是以空格分隔列表项，那么插入进来的列表项也将以空格分隔
        - 如果列表中列表项是以逗号分隔列表项，那么插入进来的列表项也将以逗号分隔
        - 设置 `$separator` 参数
            - 如果取值为 comma 将会以逗号分隔列表项
            - 如果取值为 space 将会以空格分隔列表项
    - `zip($lists…)`：将几个列表结合成一个多维的列表
    - `index($list, $value)`：返回一个值在列表中的位置值
        - 在 index() 函数中，如果指定的值不在列表中（没有找到相应的值），那么返回的值将是 false，相反就会返回对应的值在列表中所处的位置
- 颜色函数
    - RGB 颜色函数
        - `rgb($red,$green,$blue)`：根据红、绿、蓝三个值创建一个颜色
        - `rgba($red,$green,$blue,$alpha)`：根据红、绿、蓝和透明度值创建一个颜色
            - `rgba($red,$green,$blue,$alpha)`  //将一个rgba颜色转译出来，和未转译的值一样
            - `rgba($color,$alpha)`  //将一个Hex颜色转换成rgba颜色
        - `red($color)`：从一个颜色中获取其中红色值
        - `green($color)`：从一个颜色中获取其中绿色值
        - `blue($color)`：从一个颜色中获取其中蓝色值
        - `mix($color-1,$color-2,[$weight])`：把两种颜色混合在一起
            - 使用语法：`mix($color-1,$color-2,$weight);`
            - `$color-1` 和 `$color-2` 指的是你需要合并的颜色，颜色可以是任何表达式，也可以是颜色变量
            - `$weight` 为 合并的比例（选择权重），默认值为 50%，其取值范围是 0~1 之间。它是每个 RGB 的百分比来衡量，当然透明度也会有一定的权重。默认的比例是 50%，这意味着两个颜色各占一半，如果指定的比例是 25%，这意味着第一个颜色所占比例为 25%，第二个颜色所占比例为75%
    - HSL 颜色函数(Hue 色相；Saturation 饱和度；Lightness 明度)
        - `hsl($hue,$saturation,$lightness)`：通过色相（hue）、饱和度(saturation)和亮度（lightness）的值创建一个颜色
        - `hsla($hue,$saturation,$lightness,$alpha)`：通过色相（hue）、饱和度(saturation)、亮度（lightness）和透明（alpha）的值创建一个颜色
        - `hue($color)`：从一个颜色中获取色相（hue）值
        - `saturation($color)`：从一个颜色中获取饱和度（saturation）值
        - `lightness($color)`：从一个颜色中获取亮度（lightness）值
        - `adjust-hue($color,$degrees)`：通过改变一个颜色的色相值，创建一个新的颜色
        - `lighten($color,$amount)`：通过改变颜色的亮度值，让颜色变亮，创建一个新的颜色
        - `darken($color,$amount)`：通过改变颜色的亮度值，让颜色变暗，创建一个新的颜色
        - `saturate($color,$amount)`：通过改变颜色的饱和度值，让颜色更饱和，从而创建一个新的颜色
        - `desaturate($color,$amount)`：通过改变颜色的饱和度值，让颜色更少的饱和，从而创建出一个新的颜色
        - `grayscale($color)`：将一个颜色变成灰色，相当于 `desaturate($color,100%)`
        - `complement($color)`：返回一个补充色，相当于 `adjust-hue($color,180deg)`
        - `invert($color)`：反回一个反相色，红、绿、蓝色值倒过来，而透明度不变
    - Opacity 函数
        - `alpha($color) /opacity($color)`：获取颜色透明度值
        - `rgba($color, $alpha)`：改变颜色的透明度值
        - `opacify($color, $amount) / fade-in($color, $amount)`：使颜色更不透明
            - 对已有颜色的透明度做一个加法运算，会让颜色更加不透明。其接受两个参数，第一个参数是原始颜色，第二个参数是你需要增加的透明度值，其取值范围主要是在 0~1 之间。当透明度值增加到大于 1 时，会以 1 计算，表示颜色不具有任何透明度
        - `transparentize($color, $amount) / fade-out($color, $amount)`：使颜色更加透明
            - 让透明值做减法运算，当计算出来的结果小于 0 时会以 0 计算，表示全透明
- Introspection 函数
    - Introspection 函数包括了几个判断型函数：
    - `type-of($value)`：返回一个值的类型
        - `type-of()` 函数主要用来判断一个值是属于什么类型：
        - `type-of()` 返回值：
            - number 为数值型
            - string 为字符串型
            - bool 为布尔型
            - color 为颜色型
    - `unit($number)`：返回一个值的单位
        - `unit()` 函数主要是用来获取一个值所使用的单位，碰到复杂的计算时，其能根据运算得到一个“多单位组合”的值，不过只充许乘、除运算
        - 但加、减碰到不同单位时，`unit()` 函数将会报错，除 px 与 cm、mm 运算之外
    - `unitless($number)`：判断一个值是否带有单位
        - 不带单位返回的值为 true，带单位返回的值为 false
    - `comparable($number-1, $number-2)`：判断两个值是否可以做加、减和合并
- 三元函数等
    - Miscellaneous 函数称为三元条件函数，主要因为他和 JavaScript 中的三元判断非常的相似。他有两个值，当条件成立返回一种值，当条件不成立时返回另一种值：
    - `if($condition,$if-true,$if-false)`
    - 上面表达式的意思是当 `$condition` 条件成立时，返回的值为 `$if-true`，否则返回的是 `$if-false` 值
- Map 数据地图
    - 也称为数组，因为总是以 `key:value` 成对出现，更像是一个 JSON 数据
    - `map-get($map,$key)`：根据给定的 key 值，返回 map 中相关的值
        - 根据 `$key` 参数，返回` $key` 在 `$map` 中对应的 value 值。如果 `$key` 不存在 `$map` 中，将返回 null 值
        - 此函数包括两个参数：
            - `$map`：定义好的 map。
            - `$key`：需要遍历的 key。
    - `map-merge($map1,$map2)`：将两个 map 合并成一个新的 map
        - 如果 `$map1` 和 `$map2` 中有相同的 `$key` 名，那么将 `$map2` 中的 `$key` 会取代 `$map1` 中的
    - `map-remove($map,$key)`：从 map 中删除一个 key，返回一个新 map
    - `map-keys($map)`：返回 map 中所有的 key
        - 返回 `$map` 中的所有 key。这些值赋予给一个变量，那他就是一个列表
    - `map-values($map)`：返回 map 中所有的 value
        - 获取 `$map` 的所有 value 值，可以说也将是一个列表。而且，`map-values($map)` 中如果有相同的 value 也将会全部获取出来
    - `map-has-key($map,$key)`：根据给定的 key 值判断 map 是否有对应的 value 值，如果有返回 true，否则返回 false
    - `keywords($args)`：返回一个函数的参数，这个参数可以动态的设置 key 和 value
        - `keywords($args)` 函数可以说是一个动态创建 map 的函数。可以通过混合宏或函数的参数变创建 map。参数也是成对出现，其中 `$args` 变成 key(会自动去掉$符号)，而 `$args` 对应的值就是value
- 自定义函数

自定义函数示例：

    @function colors($color){
        @if not map-has-key($social-colors,$color){
            @warn "No color found for `#{$color}` in $social-colors map. Property omitted.";
        }
        @return map-get($social-colors,$color);
    }

# `@` 的规则

- `@import`
    - `@import` 根据文件名引入。 默认情况下，它会寻找 Sass 文件并直接引入， 但是，在少数几种情况下，它会被编译成 CSS 的 `@import` 规则：
        - 如果文件的扩展名是 .css
        - 如果文件名以 http:// 开头
        - 如果文件名是 url()
        - 如果 `@import` 包含了任何媒体查询（media queries）
    - 如果你有一个 SCSS 或 Sass 文件需要引入， 但是你又不希望它被编译为一个 CSS 文件， 这时，你就可以在文件名前面加一个下划线，就能避免被编译。 这将告诉 Sass 不要把它编译成 CSS 文件。 然后，你就可以像往常一样引入这个文件了，而且还可以省略掉文件名前面的下划线
- `@media`
    - `@media` 可以嵌套在 CSS 规则中。有点类似 JS 的冒泡功能，如果在样式中使用 `@media` 指令，它将冒泡到外面
- `@extend`
    - `@extend` 是用来扩展选择器或占位符
- `@at-root`
    - `@at-root` 从字面上解释就是跳出根元素。当你选择器嵌套多层之后，想让某个选择器跳出，此时就可以使用 `@at-root`
- `@debug`
    - `@debug` 在 Sass 中是用来调试的，当你的在 Sass 的源码中使用了 `@debug` 指令之后，Sass 代码在编译出错时，在命令终端会输出你设置的提示 Bug:
- `@warn`
- `@error`
