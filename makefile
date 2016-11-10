compile: signals.c
	gcc signals.c -o signals

clean:
	rm *~ *# signals info.txt

run: signals
	./signals
