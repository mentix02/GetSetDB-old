
CC = g++
pip = pip3

make:
	mkdir -p /tmp/gsdbdata/
	${CC} -Wall -I include/ -c src/*
	mv *.o build/
	${CC} -o bin/getsetdb build/*

	@echo "build completed"
	@echo "run 'bin/getsetdb' to start a shell"

clean:
	rm build/*
