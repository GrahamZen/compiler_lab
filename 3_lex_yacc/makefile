all: gramtree.out

gramtree.out:gramtree.y lexer.l gramtree.h
	bison -d  gramtree.y
	flex lexer.l
	gcc -o $@ gramtree.tab.c lex.yy.c gramtree.c 

lexer: lex.yy.c
	gcc -o $@ $<

lex.yy.c: lexer.l
	flex $<

clean:
	rm gramtree.tab.c lex.yy.c gramtree.tab.h *.out
