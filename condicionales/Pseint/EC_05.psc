Algoritmo Figuras
	//Quishpe Patricio 1 sem B
	
	Definir  b,a,r,dmay,dmen Como real
	definir res Como Real

	Escribir "Figura Gewometrica que deseas sacar el area"
	Escribir "1_ Cuadrado"
	Escribir "2_ Circulo"
	Escribir "3_ Triangulo"
	Escribir "4_ Rectangulo"
	Escribir "5_ Rombo"
	leer opc
	Segun opc Hacer
		1:
			Escribir "1_ Cuadrado"
			Escribir "Lado: " Sin Saltar
			leer l
			res = l*4
			Escribir "Area de la figura seleccionada: ", res
		2:
			Escribir "2_ Circulo"
			Escribir "Radio"
			leer r
			res = 3.1416 * (r*r )
			Escribir "Area de la figura seleccionada: ", res
		3:
			Escribir "3_ Triangulo"
			Escribir "Base: " Sin Saltar
			leer b
			Escribir "Altura: " Sin Saltar
			leer a
			
			res = (b*a)/2
			Escribir "Area de la figura seleccionada: ", res
			
			
		4:
			Escribir "4_ Rectangulo"
			Escribir "Base: " Sin Saltar
			leer b
			Escribir "Altura: " Sin Saltar
			leer a
			res = b*a
			Escribir "Area de la figura seleccionada: ", res
			
		5: 
			Escribir "5_ Rombo"
			Escribir "Diametro mayor: " Sin Saltar
			leer dmay
			Escribir "Diametro menor: " Sin Saltar
			leer dmen
			res= (dmay *dmen)/2
			Escribir "Area de la figura seleccionada: ", res
			
		De Otro Modo:
			Escribir "No se ha elegido un literal"
	Fin Segun
FinAlgoritmo
