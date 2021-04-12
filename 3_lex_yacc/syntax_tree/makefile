all: syn_tree.out test

test: test.cpp
	./syn_tree.out < test.cpp

syn_tree.out:syn_tree.y lex.yy.c
	bison -d  syn_tree.y
	gcc -o $@ syn_tree.tab.c lex.yy.c syn_tree.c 

lexer: lex.yy.c
	gcc -o $@ $<

lex.yy.c: lexer.l
	flex $<

clean:
	rm syn_tree.tab.c lex.yy.c syn_tree.tab.h *.out
