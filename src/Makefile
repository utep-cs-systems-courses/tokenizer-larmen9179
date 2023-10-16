tokenize: main.o tokenizer.o history.o 
	cc -o tokenize main.o tokenizer.o history.o

main.o: main.c tokenizer.h history.h

tokenizer.o: tokenizer.c tokenizer.h

history.o: history.c history.h tokenizer.h

clean:
	rm -f *.o *.c~ tokenize
