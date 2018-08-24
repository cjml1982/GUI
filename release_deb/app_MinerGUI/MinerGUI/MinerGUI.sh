#!/bin/sh  
appname=`basename $0 | sed s,\.sh$,,`  
#echo `basename $0`
dirname=`dirname $0`  
#echo `dirname $0`
tmp="${dirname#?}"  
#echo "${dirname#?}"
if [ "${dirname%$tmp}" != "/" ]; then  
dirname=$PWD/$dirname  
fi  
LD_LIBRARY_PATH=/usr/share/app_MinerGUI/lib
#echo $LD_LIBRARY_PATH  
export LD_LIBRARY_PATH  
$dirname/$appname "$@"
