all: result

result:gramtree.y gramtree.l gramtree.h
	bison -d  gramtree.y
	flex gramtree.l
	gcc gramtree.tab.c lex.yy.c gramtree.c 

clean:
	rm gramtree.tab.c lex.yy.c a.out gramtree.tab.h
