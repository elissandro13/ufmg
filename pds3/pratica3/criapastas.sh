#! /bin/bash

CMD="/bin/"
for i in {6..19}
do
	PATH="./C${i}"
	${CMD}touch "${PATH}/c${i}relatorio.txt" && ${CMD}cat modelo.txt > "${PATH}/c${i}relatorio.txt"
done
