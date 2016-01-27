Proceso BFI
	archivo <- ""
	longitud_archivo <- 0
	indice <- 1
	car <- ''
	Dimension buffer[32]
	iterador <- 1
	final <- ""
	
	Leer archivo
	
	longitud_archivo <- Longitud(archivo)
	
	//Llamada a Comprobar_llaves
	
	Mientras indice <= longitud_archivo Hacer
		car <- SubCadena(archivo, indice, indice)
		Segun car Hacer
			'+':
				buffer[iterador] = buffer[iterador] + 1
			'-':
				buffer[iterador] = buffer[iterador] - 1
			'>':
				iterador = iterador + 1
			'<':
				iterador = iterador - 1
			',':
				Leer buffer[iterador]
			'.':
				final <- final + ConvertirATexto(buffer[iterador]) + ";"
			'[':
				Si buffer[iterador] == 0 Entonces
					//indice <- matching_closing_key[indice]
					//Saltar_mientras
				Fin Si
			']':
				Si buffer[iterador] != 0 Entonces
					//indice <- matching_opening_key[indice]
					//Saltar_mientras
				Fin Si
		Fin Segun
		
		indice <- indice + 1
	Fin Mientras
	
	Escribir "Resultado: "
	Escribir final
FinProceso
