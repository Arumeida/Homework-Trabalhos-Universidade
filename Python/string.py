#-*- coding: utf-8 -*-
a = "Arumeida"
b = "Mila"
string = "Eu amo demais essa mulher, puta que pariu, que mulherão da porra"

concatenar = a + " ama " + b
tam = len (concatenar)
print (concatenar)
print (tam)
print (a[2])
print (concatenar[0:3])
print (concatenar[8:])
print (concatenar.lower())
print (concatenar.upper())
lista = string.split(" ")
print (lista)
busca = string.find ("mulher")
print (busca)
busca2 = string.find ("tristeza")
print (busca2)
string = string.replace("essa mulher", "a Milagros")
print (string)