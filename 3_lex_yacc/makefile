all: result clean

result:gramtree.y lexer.l gramtree.h
	bison -d  gramtree.y
	flex lexer.l
	gcc gramtree.tab.c lex.yy.c gramtree.c 

clean:
	rm gramtree.tab.c lex.yy.c a.out gramtree.tab.h
