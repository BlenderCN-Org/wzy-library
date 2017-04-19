《The Little Schemer》读书笔记

##1. Toys

####atom
An atom can be a string of characters, or a string of digits, or with other special characters.

####list
由括号包括的数据，内容可以是 atom 或 list.
注意：( ) 也是 list，because it contains zero S-expressions enclosed by parentheses. This special S-expression is called the null (or empty) list.

####S-expression
其实就是 symbolic expression，可以是一个 atom，或者一个括号组成的 list。
All atoms and lists are S-expressions.

####序对
（序对的知识点本书中没有具体解释，但是 SICP 中有讲到，算是背景知识）
序对可以通过基本过程 `cons` 构造。过程 `cons` 取两个参数，返回一个包含这两个参数作为其成分的复合数据对象。如果给了一个序对，可以用基本过程 `car` 和 `cdr` 提取出其中部分。

名字 `cons` 表示 “构造”（construct）。名字 `car` 表示 “Contents of Address part of Register”（寄存器的地址部分的内容），`cdr`（读作 “could-er”）表示 “Contents of Decrement part of Register”（寄存器的减量部分的内容）

####car
The Law of Car: The primitive car is defined only for non-empty lists.
我自己总结一下：

1. `car` 只能出现在非空列表（non-empty lists）
2. 并且指向非空列表的第一个 S-expression（可以是 atom 也可以是 list）

以下两种问法语义相同：the car of the list l = (car l)

####cdr
`cdr` 白话点说就是除了 `(car l)` 的 list，所以 `cdr` 可以是一个空列表（null list）。

The Law of Cdr:
The primitive cdr is defined only for non-empty lists. The cdr of any non-empty list is always another list.

强调一下：只有 non-empty list 才有 `car` & `cdr`.
另外，`car` 相比原 list 会少一层括号，但 `cdr` 一定是和原 list 有想多层级的括号。举个例子：

- l is ((b) (x y) ((c)))
- (car (cdr l)) is (x y)
- (cdr (cdr l)) is (((c)))

####cons
`(cons a l) ` = cons the atom a onto the list l.
Notice, cons adds any S-expression to the front of a list.（cons 把 atom 添加在 list 的前面）。

`cons` 的用法：
(cons A B)，A 可以是任何 S-expression，B 是任何 list。
The Law of Cons: The primitive cons takes two arguments. The second argument to cons must be a list. The result is a list.

`(quote())` is a notation for the null list.
L: Also () and '()
S: Also '()

####null?
判断 list 是否为 empty list（判断对象不能是 atom）
The Law of Null?: The primitive null? is defined only for lists.

####atom?
`(atom? A)` is just another way to ask "Is A is an atom?"
atom? 的对象可以是任何 S-expression

####eq?
The Law of Eq?: The primitive eq? takes two arguments. Each must be a non-numeric atom.
`eq?` takes two arguments. Both of them must be non-numeric atoms.（`eq?` 的两个对象必须是 non-numeric atoms）

##2. Do it, do it again, and again, and again...

####lat?
判断 list 中的元素是否都为 atom，every lat is a list of atoms! 
注意：`(lat? l)` is True, because it does not contain a list.
empty list 也是 lat.

`(cond ...)` asks questions;
`(lambda ...)` creates a function;
`(define ...)` gives it a name.

大概的 function lat? 流程图：
<p align=center><img src="images/QQ20151102-00.png"/></p>
其实就是 cond 环境下，按顺序走 list，先判断第一行（list）的第一个 S-expression，即 `(car l)`，True，那么就再判断 `(cdr l)`；如果 `(car l) ` = False，那么就跳到下一行（list）。恩，我为什么想到了跳蛋的游戏（想想 focus on a tiaodan，然后在 function 中开始跳，true 就沿着 list 跳，false 就跳到下一个 list，然后继续沿着 list 跳）（图有点龊不好意思，其实做成动画会更形象一点，但我他妈是在看书呢！！！瞎想什么！）：
<p align=center><img src="images/QQ20151102-01.png"></p>

####or?
`(or? A B)`，A 或 B 为 True 即为 True。
`(or ...)` asks two questions, on at a time. If the first one is true it stops and answers true. Otherwise it asks the second question and answers with whatever the second question answers.

####member?
一般形式：`(member? A B)`
判断 list B 中是否有元素 A。

####The First Commandment (preliminary):
Always ask `null?` as the first question in expressing any function.

####else
else 是一个值永远为 True 的问题。

##3. Cons the Magnificent

####rember
rember 的意思就是执行 “remove a member”。
一般形式：`(rember a lat)`，即 去掉 lat 中的 a. 若 lat 中不存在 a，则结果仍为 lat.
`(rember a lat)` takes an atom and  a lat as its arguments, and makes a new lat with the first occurrence of the atom in the old lat removed.

####The Second Commandment
Use cons to build lists.

####cons
`(cons a lat)` 就是把 atom a 加在 lat 前面，构成一个新的 lat.

我画了个图，大概说明一下 `(rember a lat)`，其实就是一个循环嵌套结构，判断 lat 的每一个 atom，如果不是要删除的元素，就保留这个 atom 并判断下一个是否是要删除的元素，然后遇到要删除的元素，就不保留，`(rember a lat*)` 取值为 `(cdr lat*)（lat*:  (car lat*)=a ）`（此处感谢友邻 123 的指正），然后再倒序重建 lat。因为要删除的元素没有保留，所以重建之后的 lat 就没有了 a，就相当于从 lat 中删除了 a. 红色标记部分就是保留重建需要的 atom：
<p align=center><img src="images/QQ20151102-02.png"></p>

####firsts
The function firsts takes one argument, a list, which is either a null list or contains only non-empty lists. It builds another list composed of the first S-expression of each internal list.
使用形式：`(firsts l)`, l 是空列表或者是只包含非空列表的列表，firsts 就是将 l 所包含的每个 list 的第一个 S-expression 取出组成一个新的 list。

一个 cond 中，第一个 question 一定是 null?，最后一个 question 一定是 else。

####The Third Commandment
When building a list, describe the first typical element, and then cons it onto the natural recursion.

####insertR
格式：`(insertR new old lat)`, 在 lat 中的 old 的右边插入 new.
It takes three arguments: the atoms new and old, and a lat. The function insertR builds a lat with new inserted to the right of the first occurrence of old.

####insertL
格式：`(insertL new old lat)`
同理，在 lat 的 old 的左边插入 new.

####subst
`(subst new old lat)` replaces the first occurrence of old in the lat with new.

####subst2
`(subst2 new o1 o2 lat)` replaces either the first occurrence of o1 or the first occurrence of o2 by new.
在 lat 中，把 o1 或 o2 中先出的替换成 new.

####multirember
`(multirember a lat)` 把 lat 中所有的 a 都删除

####The Fourth Commandment (preliminary)
Always change at least one argument while recurring. It must be changed to be closer to termination. The changing argument must be tested in the termination condition: when using cdr, test termination with null?.

`multiinsertR`, `multiinsertL`, `multisubst`，同理，都是对 lat 中多个对象操作。

##4. Numbers Games

Lisp 只考虑非负整数（nonnegative integers, i.e., 0, 1, 2, 3, ...）

####add1
即 +1.

####sub1
即 -1.

####zero?
判断是否为 0.

####function +
格式：`（+ n m）`, 判断 m 是否为 0，若为 0，结果为 n；不为 0，就将 m 拆为 m 个 add1，与 n 相加。

`(function -)` 同理。It takes two numbers as arguments, and reduces the second until it hits zero. It subtracts one from the result as many times as it did to cause the second one to reach zero.

####tup
tup 是 tuple 的缩写，tup 中所有元素都为 number；

####addtup
格式 :`(addtup tup)`, 将 tup 中的所有数字相加，结果为一个数字。

####The First Commandment (first revision)
When recurring on a list of atoms, lat, ask two questions about it: `(null? lat)` and else.
When recurring on a number, n, ask two questions about it: `(zero? n)` and else.

####The Fourth Commandment (first revision)
Always change at least one argument while recurring. It must be changed to be closer to termination. The changing argument must be tested in the termination condition:
when using cdr, test termination with null? and
when using sub1, test termination with zero?.

下图是 (× n m) 的递归框图（实际就是 m 个 n 和一个 0 相加）：
<p align=center><img src="images/QQ20151102-03.png"></p>

####The Fifth Commandment
When building a value with +, always use 0 for the value of the terminating line, for adding 0 does not change the value of an addition.
When building a value with ×, always use 1 for the value of the terminating line, for multiplying by 1 does not change the value of a multiplication.
When building a value with cons, always consider () for the value of the terminating line.

####tup+
格式：`(tup+ tup1 tup2)`, 两个 tup 中的元素分别对应相加，得到一个与 tup1 & tup2 等长的 tup.
It adds the first number of tup1 to the first number of tup2, then it adds the second number of tup1 to the second number of tup2, and so on, building a tup of the answer, for tups of the same length.
当然 tup+ 也可以不等长。

判断大小，先判断是否为 0，然后再递归 sub1，直到其中一个数为 0.

乘法，除法同理，`function (length lat)` 判断 lat 的长度（有几个 atom）。

####pick
格式：`(pick n lat)`, 挑出 lat 的第 n （n 为正整数）个atom，返回值为 atom.

####rempick
格式：`(rempick n lat)`，删除 lat 的第 n 个 atom.

####no-nums
格式：`(no-nums lat)`，删掉 lat 中的所有数字 atoms.

####all-nums
Format: `(all-nums lat)`, which extracts a tup from a lat using all the numbers in the lat.
得出一个 tup，由所有 lat 的数字 atoms 组成。

####eqan?
格式：`(eqan? a1 a2)`，判断 a1 a2 是否相同。
（`eq?` 的对象必须是非数字（non-numeric atom））

#####occur
格式：`(occur a lat)`, 计算 a 在 lat 中出现的次数。

##5. Oh My Gawd: It's Full of Stars

####rember*
格式：`（rember* a l）`，把 l 中出现的 a 全部删除。

####insertR*
格式：`（insertR* new old l）`，在 l 中所有 old 的右边加上 new.

####The First Commandment (final version)
When recurring on a list of atoms, lat, ask two questions about it: `(null? lat)` and else.
When recurring on a number, n, ask two questions about it: `(zero? n)` and else.
When recurring on a list of S-expressions, l, ask three questions about it: `(null? l)`, `(atom? (car l))`, and else.

####How are all *-functions similar? And why?
They all ask three questions and recur with the car as well as with the cdr, whenever the car is a list.
Because all *-functions work on lists that are either
- empty
- an atom consed onto a list, or
- a list consed onto a list

####The Fourth Commandment (final version)
Always change at least one argument while recurring. When recurring on a list of atoms, lat, use (cdr lat). When recurring on a number, n, use (sub1 n). And when recurring on a list of S-expressions, l, use (car l) and (cdr l) if neither (null? l) nor (atom? (car l)) are true.
It must be changed to be closer to termination. The changing argument must be tested in the termination condition:
when using cdr, test termination with null? and
when using sub1, test termination with zero?.

####occur*
格式：`（occur* a l）`，计算 a 在 l 中出现的次数，返回一个非负整数。

####subst*
格式：`（subst* new old l）`，用 new 替换 l 中出现的所有 old.

####member*
格式：`（member* a l）`，判断 l 中是否出现 a，返回一个布尔值。

####leftmost
The function leftmost finds the leftmost atom in a non-empty list of S-expressions that does not contain the empty list.

####eqlist
格式：`（eqlist? l1 l2）`，判断两个 list 是否完全相同。
`eqlist?` 的逻辑框图，颜色越深逻辑优先级越高（另外一开始我认为 92 页 define eqlist? 有错，cond 中第二个 or 的括号多了，隔了一晚琢磨一下，没错，没错）：
<p align=center><img src="images/QQ20151102-04.png"></p>

然后简化之后（把第三个 question 都删了）：
<p align=center><img src="images/QQ20151102-05.png"></p>

####The Sixth Commandment
Simplify only after the function is correct.
之前 function `rember(s l)`，l 必须为 lat，逻辑框图如下：
<p align=center><img src="images/QQ20151102-06.png"></p>

现在 重新定义 function `rember`, l 为 a list of S-expressions 且 a 可以为任何 S-expression，框图简化如下：
<p align=center><img src="images/QQ20151102-07.png"></p>

####6. Shadows

####arithmetic expression
For the purpose of this chapter, an arithmetic expression is either an atom (including numbers), or two arithmetic expression combined by `+`, `×`, or `↑`.
本章中，一个算术表达式可以是一个 atom（包括数字），也可以是被 `+`，`×` 和 `↑` 连接的两个算术表达式，另外一个算数表达式一般不包括括号。

####quot
引用格式：`(quote a)`，a 可以是atom，也可以是符号，均表示为一个 atom。

####numbered
`numbered?` is a function that determines whether a representation of an arithmetic expression contains only numbers besides the `+`, `×`, and `↑`.

####The Seventh Commandment
Recur on the subparts that are of the same nature:

- On the sublists of a list.
- On the subexpressions of an arithmetic expression.

####value
格式：`(value nexp)`，计算 nexp 的值，返回一个 number.
value 的逻辑框图（其中使用了三个 function，分别是 1st-sub-exp, 2nd-sub-exp and operator）：
<p align=center><img src="images/QQ20151102-08.png"></p>

####The Eighth Commandment
Use help functions to abstract from representations.

##7. Friends and Relations

####set?
格式：`（set? lat）`，若 lat 中的 atom 都是唯一且互不相同，则返回 #t.

####makeset
格式：`(makeset lat)`，删除 lat 中重复出现的 atom，只保留第一个（也可以最后一个，根据定义判断）。
The function makeset remembers to cons the first atom in the lat onto the result of the natural recursion, after removing all occurrences of the first atom from the rest of the lat.

####subset?
格式：`(subset? set1 set2)`，判断 set1 是否是 set2 的子集，是则返回 #t.

####eqset?
格式：`(eqset? set1 set2)`，判断是否为相同集合（atom 的顺序可以不一样）。

####intersect?
格式：`（intersect? set1 set2）`，判断是否有交集。

####intersect
格式：`（intersect set1 set2）`，求集合交集。

####union
格式：`（union set1 set2）`，求合集。

####xxx
格式：`（xxx set1 set2）`，返回 set1 & !set2 的 atom（The `xxx` function that returns all the atoms in set1 that are not in set2），that is, `xx` is the (set) difference function.

####intersectall l-set
格式：`（intersectall l-set）`，求所有集合的子集。

####a-pair?
格式：`(a-pair?)`，判断是否为只有两个 S-expressions 的 list.

定义一些常用 function：
	
	(first p) = (car p)
	(second p) = (car (cdr p)
	(build s1 s2) = (cons s1 (cons s2 (quote ())))
	\\同理
	(third l) = (car (cdr (cdr l)))

####rel
判断集合是否为对集（set of pairs）的集合，rel stands for relation.

####fun?
格式：`（fun? rel）`，判断 `(firsts rel)` 是否是集合（set）。
定义：`(fun? rel) ` = `(set? (first rel))`

####revrel
将 rel 子集中的对偶调换（revpair 是调换对偶集合中两个 S-expression 的位置）。
逻辑框图如下：
<p align=center><img src="images/QQ20151102-09.png"></p>

####fullfun?
`(fulfun? fun)` = `(set? (seconds fun))`</br>
fullfun? 又可以称为 one-to-one?</br>
(one-to-one? fun) = (fun? (revrel fun))

##8. Lambda the Ultimate

####rember-f
格式：`((rember-f test?) a l)`，执行操作 (rest? a l)，删除符合条件的第一个 atom。
比如, where a is tuna, and l is (shrimp salad and tuna salad),
`((rember-f eq?) a l)` is (shrimp salad and salad)，即执行操作 (eq? a l)，删除第一个符合条件的 tuna。
逻辑框图：
<p align=center><img src="images/QQ20151102-10.png"></p>

####insertL-f & insertR-f
同理 rember-f，对符合 test? 条件的执行 insertL or insertR.

####insert-g
Insert-g is a function that would insert either at the left or at the right.
格式：`((insert-g seq) new old l)`，seq 可以是 seqL or seqR.

####seqL, seqR
`(seqL new old l)` = `(cons new (cons old l))`</br>
`(seqR new old l)` = `(cons old (cons new l))`

####insertL, insertR
insertL = `(insert-g seqL)`</br>
insertR = `(insert-g seqR)`

####The Ninth Commandment
Abstract common patterns with a new function.

####atom-to-function
执行符号 +，× 或 ↑ 所表示的操作。逻辑框图如下：
<p align=center><img src="images/QQ20151102-11.png"></p>

用 atom-to-function 重写 value（不判断具体的运算符号，直接用 atom-to-function 替代），框图如下：
<p align=center><img src="images/QQ20151102-12.png"></p>

####nultiremberT
格式：`（multiremberT test? lat）`，删除 lat 中所有符合 test？的 atom.

####a-friend
格式：`（a-friend x y）`，判断 y 是否为空集，忽略 x.</br>
`(a-friend x y)` = `(null? y)`

####multirember&co
格式：`(multirember&co a lat col)`，逻辑框图如下：
<p align=center><img src="images/QQ20151102-13.png"></p>
multirember&co 中还定义了一个函数: </br>
`(lambda (newlat seen))` = `(col newlat (cons (car lat) seen))`

####new-friend
`(new-friend newlat seen)` = `(col newlat (cons (car lat) seen))`</br>
其实就是 multirember&co 中定义的新函数；col 可以用 a-friend 替代。

####latest-friend
`(latest-friend newlat seen)` = `(a-friend (cons (quote and) newlat) seen)`

####multiinsertLR
multiinsertLR inserts new to the left of oldL and to the right of oldR in lat if oldL and oldR are different.</br>
格式：`（multiinsertLR new oldL oldR lat）`，就是在 lat 中， oldL 的左边和 oldR 的右边插入 new，如果 oldL 和 oldR 不同。

####multiinsertLR&co
格式：`（multiinsertLR&co new oldL oldR lat col）`，与 multiinsertLR 同理，最后返回操作 (col newlat L R)，newlat 是完成 multiinsertLR 之后所得，L 和 R 分别是完成在左插入（insertL）和在右插入（insertR）的次数。

####The Tenth Commandment
Build functions to collect more than one value at a time.

####evens-only*
格式：`（evens-only* l）`，保留 l 中的所有的偶数。

####evens-only*&co

格式：`（evens-only*&co l col）`比 evens-only* 多一个待定函数 col；
col 的格式为 `(col (newl p s)`；

`(evens-only*&co l the-last-friend)`, 
where l is ((9 1 2 8) 3 10 ((9 9) 7 6) 2) and
(the-last-friend newl product sum) = (cons sum (cons product newl))
(evens-only* l) 的结果为 ((2 8) 10 (() 6) 2)，list 的 sum 为 38，product 为 1920.
所以操作 (the-last-friend newl product sum) = (38 1920 (28) 10 (() 6) 2).

##9. ... and Again, and Again, and Again, ...

####looking
格式：`（looking a lat）`，(looking a lat) = (keep-looking a (pick 1 lat) lat)))</br>
function pick 是挑出 list 中的第 n 个 atom.
类似于 looking 的 functions 被称为部分函数（partial function）

sorn 意思是符号或数字（Symbol OR Number）

####shift
格式：`（shift pair）`，the function shift takes a pair whose first component is a pair and builds a pair by shifting the second part of the first component into the second component.
我很蹩脚地翻译一下：shift 函数是把第一个元素是对偶的对偶集合拆开，然后把拆开后的第二部分和其他部分组成一个新的对偶集合。
比如：
(shift ((a b) c)) = (a (b c)), (shift ((a b) (c d)) = (a (b (c d))).

####length*
The function `length*` counts the number of atoms in align's arguments.

####weight*
`weight*` 的逻辑框图：
<p align=center><img src="images/QQ20151102-14.png"></p>

我人肉一步一步计算一下 `weight*`:</br>
(1) What is (weight* x), where x is ((a b) c).
Answer: 
(weight* x) </br>
= (weight* ((a b) c))</br>
= ((weight* (a b)) × 2) + (weight* c)</br>
= (((weight* a) × 2 + (weight* b)) × 2) + (weight* c)</br>
= ((1 × 2 + 1) × 2) + 1</br>
= 7</br>
(2) What is (weight* x), where x is (a (b c)).</br>
Answer:</br>
(weight* x)</br>
= (weight* (a (b c)))</br>
= (weight* a) × 2 + (weight* (b c))</br>
= 1 × 2 + ((weight* b) × 2 + (weight* c))</br>
= 2 + (1 × 2 + 1)</br>
= 5

####shuffle
The functions shuffle and revpair swap the components of pairs when the first component is a  pair.

####will-stop?
`(define will-stop? (lambda (f) ...))`，就是判断函数 f 是否有限，根据函数 f 在赋值为 () 时是否为停止。</br>
Function will-stop? 可以被精确描述但不能被定义，因为这取决于其参数函数的具体定义。

####Y
The applicative-order Y combinator（中文叫什么我没主意）
<p align=center><img src="images/QQ20151102-15.png"></p>

##10. What Is the Value of All of This?

####entry
中文应该是条目吧，entry 就是一对 list，第一个 list 是个集合（set），两个 lists 等长。

####lookup-in-entry
格式：`（lookup-in-entry name entry entry-f）`，找出与 name 所在 list 相对应另一个 list 中的相同位置的 atom。

####type
Lisp 中重要的 type：

- __*const__：比如数字，布尔值（#t or #f）
- __primitive__：原始定义，比如 (primitive car), (primitive cdr)
- __*quote__：就是 quote，比如 (type (quote nothing)) = *quote
- __*identifier__：标识符，nothing
- __*lambda__：比如 (lambda (x y) (cons x y))
- __*application__：应用函数
- __*cond__：condition.

最后附张图，图一乐：
<p align=center><img src="images/QQ20151102-16.png"></p>
