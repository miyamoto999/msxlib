#!/bin/bash
echo "/*********************************************************" > $2
echo " $2 mk_dskcallversion.sh によって自動生成されるファイルなので" >> $2
echo " 書き換えないでください。" >> $2
echo  >> $2
echo "  Do not rewrite $2 as this file is" >> $2
echo " automatically generated by mk_dskcallversion.sh." >> $2
echo >> $2
echo " *********************************************************/" >> $2
echo  >> $2

sed -e 's/dos1_/dsk1_/g' -e 's/dos2_/dsk2_/g' -e 's/_dos1/_dsk1/g' -e 's/_dos2/_dsk2/g' $1 >> $2