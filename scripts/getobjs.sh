#!bash

#�˽ű���������ҵ�ǰĿ¼�µ�����obj�ļ����������ÿո����������׼���

# Copyright daemon_process

files=`ls`

for file in $files
do
	if [ "${file##*.}" = "obj" ] ; then
		echo -n "$file "
	fi
done