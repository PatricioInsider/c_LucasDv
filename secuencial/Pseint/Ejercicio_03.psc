Algoritmo Ejercicio_09
	
	definir billetes,b100,b20,b10,b5, b1,resb100,resb20,resb10,resb5 como entero
	Escribir "Cantidad de dolares en billetes:  "
	leer billetes
	
	
	b100 = trunc(billetes/100)
	resb100 = billetes mod 100
	b20 = trunc(resb100/20)
	resb20 = resb100 mod 20
	b10 = trunc(resb20/10)
	resb10 = resb20 mod 10
	b5 = trunc(resb10/5)
	resb5 = resb10 mod 5
	
	
	Escribir "Dados los resultados"
	Escribir "Billetes de 100:  ", b100
	Escribir "Billetes de 20: ", b20
	Escribir "Billetes de 10: ", b10
	Escribir "Billetes de 5: ", b5
	Escribir "Billetes de 1: ", resb5
	
FinAlgoritmo
