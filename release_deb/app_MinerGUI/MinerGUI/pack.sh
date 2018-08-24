#!/bin/sh  
exe="MinerGUI" #你需要发布的程序名称
des="../lib" #步骤1中的目录即本文件所在目录
deplist=$(ldd $exe | awk  '{if (match($3,"/")){ printf("%s "),$3 } }')  
cp $deplist $des
