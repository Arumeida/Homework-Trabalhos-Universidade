arq = open ("fonte.txt")
lex = arq.read()
lex = lex.split()
lex2 = ""
for i in lex:
	lex2 = lex2 + i
saida = open ("tokens.txt","w")
saida.write(lex2)