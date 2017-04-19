##《编程之美》笔记

####1.1 让CPU占有率曲线听你指挥
能帮助你了解当前线程/进程/系统效能的 API 大致有以下这些：

1. `Sleep()` - 这个方法能让当前线程 “停” 下来。
2. `WaitForSingleObject()` - 自己停下来，等待某个事件发生。
3. `GetTickCount()` - 有人把 Tick 翻译成 “嘀嗒”，很形象。
4. `QueryPerformanceFrequency()`, `QueryPerformanceCounter` - 让你访问到精度更高的 CPU 数据。
5. `timeGetSystemTime()` - 是另一个得到高精度时间的方法。
6. PerformanceCounter - 效能计数器。
7. `GetProcessorInfo()`, `SetThreadAffinityMask()` - 遇到多核的问题怎么办？这两个方法能够能你更好地控制 CPU.
8. `GetCPUTickCount()` - 拿到 CPU 核心运行周期数。

####对应leetcode

|# |Chapter        |# LC| Title |
|:-----:|:-------------- |:-----:|:------|
|1.10| NIM 排石头的游戏 |292| Nim Game |
|2.1| 求二进制数中1的个数 |191| Number of 1 Bits |
|2.2| 不要被阶乘吓到|172| Factorial Trailing Zeroes |
|2.3| 寻找发帖“水王”|169| Majority Element |
|2.4| 1的数目|233| Number of Digit One|
|2.5| 寻找最大的K个数 |215| Kth Largest Element in an Array |
|||||
|||||
|||||
|||||
|||||
|||||
|||||