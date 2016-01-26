Proceso BFI
	archivo <- ""
	longitud_archivo <- 0
	indice <- 1
	car <- ''
	Dimension buffer[32]
	iterador <- 1
	ignorar <- falso
	final <- ""
	
	Leer archivo
	
	longitud_archivo <- Longitud(archivo)
	
	Mientras indice <= longitud_archivo Hacer
		car <- SubCadena(archivo, indice, indice)
		Segun car Hacer
			"+":
				buffer[iterador] = buffer[iterador] + 1
			"-":
				buffer[iterador] = buffer[iterador] - 1
			">":
				iterador = iterador + 1
			"<":
				iterador = iterador - 1
			",":
				Leer buffer[iterador]
			".":
				final <- final + ConvertirATexto(buffer[iterador]) + ";"
		Fin Segun
		
		indice <- indice + 1
	Fin Mientras
	
	Escribir "Resultado: "
	Escribir final
FinProceso
