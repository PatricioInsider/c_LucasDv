Algoritmo directorio // Patricio Quishpe  Software B
	//EScribir un directorio telefonico
	definir nume, numagregados, nombre, correo como cadena
	
	
	// Declaracion de variables
	dimension nume(3,3)
	Dimension numagregados(4)
	dimension nombre(3,3)
	dimension correo(3,3)
	// Inicializacion de variables
	
	// Ingreso de datos
	l <- 1
	Escribir 'Directorio de la ciudad'
	Para i<- 1 Hasta 2 Con Paso 1 Hacer
		Para j<- 1 Hasta 2 Con Paso 1 Hacer
			
			Escribir 'Contacto: ', l
			Escribir 'Nombre' sin saltar
			leer nombre(i,j)
			Escribir 'Numero' sin saltar
			leer nume(i,j)
			x <- longitud(nume(i,j))
			mientras x <>10 hacer
				Escribir 'Error 404:'
				Escribir 'Ingresa el numero telefonico (solo 10 dijitos)'
				leer nume(i,j)
				x <- longitud(nume(i,j))
			Finmientras
			Escribir 'Correo' sin saltar
			leer correo(i,j)
			l <- l+1
		Fin Para
	Fin Para
	Escribir 'Menu de llamadas'
	Escribir 'Ingresa el numero telefonico'
	leer numerote
	x <- longitud(numerote)
	mientras x <>10 hacer
		Escribir 'Error 404:'
		Escribir 'Ingresa el numero telefonico (solo 10 dijitos)'
		leer numerote
		x <- longitud(numerote)
	Finmientras
	
	Escribir '(1) Llamar y (2)guardar contacto'
	leer opc
	mientras opc = 1 hacer
		Escribir 'Llamando...'
		Escribir 'no contesta'
		Escribir '(1) Llamar y (2)guardar contacto'
		leer opc
		si opc = 2 Entonces
			Para i<- 3 Hasta 3 Con Paso 1 Hacer
				Para j<- 3 Hasta 3 Con Paso 1 Hacer
					Escribir 'Nombre' sin saltar
					leer nombre(i,j)
					Escribir 'Numero' sin saltar
					leer nume(i,j)
					x <- longitud(nume(i,j))
					mientras x <>10 hacer
						Escribir 'Error 404:'
						Escribir 'Ingresa el numero telefonico (solo 10 dijitos)'
						leer nume(i,j)
						x <- longitud(nume(i,j))
					Finmientras
					Escribir 'Correo' sin saltar
					leer correo(i,j)
				Fin Para
			Fin Para
		FinSi

	Finmientras
	
	
	Escribir 'Directorio completo'
	Para i<- 1 Hasta 3 Con Paso 1 Hacer
		Para j<- 1 Hasta 3 Con Paso 1 Hacer
			espacio<-' '
			Escribir 'Nombre: ',nombre(i,j), espacio, 'Numero: ', nume(i,j), espacio, 'Correo: ', correo(i,j)
		Fin Para
	Fin Para
	
	
	// Proceso de datos
	
	

	//Salida de informacion
	
FinAlgoritmo
