CCFLAGS = generate.c generators/metroid.c -o generate.exe

build:
	$(CC) $(CCFLAGS)
clean:
	rm *.exe
