#!/bin/sh
rm $1.novo 2> /dev/null
cat $1 |
while read Linha
do
	NovaLinha=
	for Palavra in $Linha
	do
		NovaPalavra=`echo $Palavra | cut -c1 | tr "[a-z]" "[A-Z]"``echo $Palavra | cut -c2- | tr "[A-Z]" "[a-z]"`
		NovaLinha="$NovaLinha $NovaPalavra"
	done
	echo $NovaLinha | cut -c1- >> $1.novo
done
