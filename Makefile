build :
	gcc main.c -o downtime

install :
	gcc main.c -o downtime
	mkdir -p ${HOME}/.local/bin
	mv ./downtime ${HOME}/.local/bin
