## Python

### Terminal

查看 python 版本

	python -V
	python --version

查看 python 安装位置

	python -c"import sys;print sys.executable
	python -c"import os;print os.sys.executable
	python -c"import os;path=os.sys.exectuable;folder=path[0:path.rfind(os.sep)];print folder

查看 numpy 版本

	python -c"import numpy;print numpy.version.version
	python -c"import numpy;print numpy.__version__

查看 numpy 安装路径

	python -c"import numpy;print numpy.__file__

查看当前工作目录

	import os
	os.getcwd()

切换当前工作目录

	//切换当前工作目录
	import os
	os.chcwd("/home")
	//加入包含 .py 文件的目录到系统文件里
	import sys
	sys.path.append(".../")

### CSV

读取 CSV 文件

	import csv
	csvfile = file('filename.csv','rb')
	reader = csv.reader(csvfile)
	for row in reader:
    	print row
	csv.close()
