Algoritmo Ejercicio_05
	//Quishpe Patricio
	definir a,b,c,per,area como real
	Escribir "Ingresa los siguientes datos del triangulo"
	Escribir "Lado a: "
	leer a
	Escribir "Lado b: "
	leer b
	Escribir "Lado c: "
	leer c
	
	per = (a+b+c)/2
	area =  raiz((per*(per - a)*(per - b)*(per - c)))
	
	Escribir "Perimetro del triangulo: ", per
	Escribir "Area del triangulo: ", area
	
	
FinAlgoritmo
