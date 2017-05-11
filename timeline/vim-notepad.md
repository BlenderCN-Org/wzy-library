##vim
参考资料</br>
[vim配置及插件安装管理](http://blog.csdn.net/namecyf/article/details/7787479)

查看 vim 信息：

	:version

保存

	\\保存文件，即使文件并没有被改动也会被重写一次
	:w
	\\保存文件，仅在文件有改动才会保存
	:up
	:update

保存退出

	\\强制重写然后退出（关闭）当前缓冲区，如果仅有一个缓冲区，会推出vim
	:wq
	\\保存并退出，仅在有改动时才保存
	:x
	\\保存所有该保存的缓冲区，然后退出vim
	:wqa
	:xa
