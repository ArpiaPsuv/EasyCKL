#!/bin/sh

# �˽ű����ɹ����� EasyCKL ��Ӧ�ó���ʹ�õ�ͷ�ļ�
# Copyright daemon_process

# The name is kept EasyCKL.h for backwards compatibility
header_file=SDK/EasyCKL.h
header_file_swp=${header_file}.swp

mkdir -p SDK
rm -rf ${header_file} ${header_file_swp}

files='ec_portable.h CKLMain.h CustomizeJS.h CustomizeScheme.h EcPackApi.h FrameApi.h browser.h'
tags='SimpleHandler CefFrame CefV8Context CefV8ValueList CefRefPtr<CefV8Value> CefRequest BytesVector'

for file in $files
do
	cat ${file} >> ${header_file_swp}
done

for tag in $tags
do
	sed -i "s/${tag}/void/g" ${header_file_swp}
done

# ɾ���� #define ֮���Ԥ����ָ��
sed -i -e '/^#[^d]/d' ${header_file_swp}

# ɾ�� #define __XXXX_H_ 
sed -i -e '/^#define.*_H_$/d' ${header_file_swp}

sed -i -e '/^void _ECKL_CopyWString.*;$/d' ${header_file_swp}

# �ϲ�����
sed -i '/^$/N;/^\n$/D' ${header_file_swp}

cat SDK/header.h.end >> ${header_file_swp}

cat SDK/header.h.begin > ${header_file}
cat ${header_file_swp} >> ${header_file}
rm -rf ${header_file_swp}