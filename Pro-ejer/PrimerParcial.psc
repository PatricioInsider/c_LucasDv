Algoritmo PrimerParcial
	
	definir d,m,c,i,x Como Entero
	definir s,denegar,e,mes como cadena
	x=0
	Escribir "Ingrese el dia(numero)"
	leer d
	Escribir "Ingrese el mes(numero)"
	leer m
	Escribir "Primer dia del mes (lunes, martes, miércoles, etc)"
	leer s
	
	denegar = "Dia del mes fuera del rango "
	
	si m=1 o m=3 o m=5 o m=7 o m=8 o m=10 o m=12 Entonces
		dias =31
		si d<=dias Entonces
			x=d
		SiNo
			Escribir denegar
		FinSi 
	FinSi
	
	si m=4 o m=6 o m=9 o m=11 Entonces
		dias =30
		si d<=dias Entonces
			x=d
		SiNo
			Escribir denegar
		FinSi 
	FinSi
	
	si m=2 Entonces
		dias =28
		si d<=dias Entonces
			x=d
		SiNo
			Escribir denegar
		FinSi 
	FinSi
	
	
	si x=d Entonces
		Segun m Hacer
			1:
				mes="Enero"
			2:
				mes="Febrero"
			3:
				mes="Marzo"
			4:
				mes="Abril"
			5:
				mes="Mayo"
			6:
				mes="Junio"
			7:
				mes="Julio"
			8:
				mes="Agosto"
			9:
				mes="Septiembre"
			10:
				mes="Octubre"
			11:
				mes="Noviembre"
			12:
				mes="Diciembre"
			De Otro Modo:
				Escribir "Mes fuera de rango"
		Fin Segun
		
		si s = "lunes" Entonces
			c=0
		FinSi
		si s = "martes" Entonces
			c=1
		FinSi
		si s = "miercoles" Entonces
			c=2
		FinSi
		si s = "jueves" Entonces
			c=3
		FinSi
		si s = "viernes" Entonces
			c=4
		FinSi
		si s = "sabado" Entonces
			c=5
		FinSi
		si s = "domingo" Entonces
			c=6
		FinSi
		
		c=c+d
		Repetir
			si c <8 Entonces
				i=1
				Segun c Hacer
					1:
						e= "lunes"
					2:
						e="martes"
					3:
						e="miercoles"
					4:
						e="jueves"
					5:
						e="viernes"
					6:
						e="sabado"
					7:
						e="domingo"
					De Otro Modo:
						Escribir "Ingresa correctamente el dia"
				Fin Segun
			FinSi
			c=c-7
		Hasta Que i==1
		Escribir "El ",d," de ", mes, " es ", e
	FinSi
	
FinAlgoritmo
