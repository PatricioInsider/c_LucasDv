Algoritmo sin_titulo
	//Patricio Quishpe
	Escribir "Escribir un programa que lea N números, los guarde en un vector y a continuación los imprima en orden inverso al de su entrada."
	Escribir "Ingrese la magnitud de su vector: " Sin Saltar
	leer n
	
	Dimension v1(n)
	dimension v2(n)
	x=n
	Escribir "Ingresa todos los datos array 1 : ____________"
	para i <- 1 hasta x Con Paso 1 Hacer
		Escribir "Ingresa el dato: (",i, ") = " Sin Saltar
		leer v1(i)
	FinPara
	Escribir "_____________ "
	
	j = n
	para i <- 1 hasta n Con Paso 1 Hacer
		v2(i)= v1(j)
		j = j-1
	FinPara
	
	Escribir"Impresion inversa"
	para i <- 1 hasta n Con Paso 1 Hacer
		Escribir v2(i), ", " Sin Saltar
	FinPara
	Escribir ""
	Escribir "_____________ "
	
	
FinAlgoritmo
	

