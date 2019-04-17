# -*- coding: utf-8 -*-
arq = open ("texto.txt","r")
w = open ("file2.txt", "a")
a = "arumeida boladão escrevendo em arquivo com python\n"
w.write(a)
w.close()
print (arq)
linhas = arq.readlines()
texto_completo = arq.read()
print (texto_completo)

print (linhas)