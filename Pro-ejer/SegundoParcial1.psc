Algoritmo SegundoParcial1
	definir n,sum Como Entero
	sum =0
	
	Escribir "Ingresa el tamaño de los vectores: " Sin Saltar
	leer n
	Dimension v1[n],v2[n]
	
	Escribir "Ingresa todos los datos array 1 : ____________"
	Para i <-1 Hasta n Con Paso 1 Hacer
		Escribir "Ingresa el dato: (",i,") = " 
		leer v1[i]
	Fin Para
	
	Escribir "Ingresa todos los datos array 2 : ____________"
	Para i <-1 Hasta n Con Paso 1 Hacer
		Escribir "Ingresa el dato: (",i,") = " 
		leer v2[i]
	Fin Para
	
	Para i <-1 Hasta n Con Paso 1 Hacer
		Para j <-1 Hasta n Con Paso 1 Hacer
			si v1[i]=v2[j] Entonces
				sum = sum+1
			FinSi
		Fin Para
	Fin Para
	
	Escribir "Comparando los vectores.. "
	
	Escribir "N V1 v2"
	Para i <-1 Hasta n Con Paso 1 Hacer
		escribir i," ",v1[i]," ",v2[i]
	Fin Para
	
	si sum =n Entonces
		Escribir "son aproximadamente iguales"
	SiNo
		Escribir "desiguales"
	FinSi
	
FinAlgoritmo
