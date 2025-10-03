# Función para leer el archivo y procesar las operaciones
def procesar_operaciones(archivo):
    values = set()

    with open(archivo, "r") as file:
        for line in file:
            # Limpiar la línea y separarla en acción y valor
            line = line.strip()
            if not line:  # Si la línea está vacía, continuar
                continue
            accion, dato = line.split()
            dato = int(dato)  # Convertir el dato a entero
            
            # Ejecutar la acción
            if accion == "add":
                values.add(dato)
            elif accion == "del":
                values.discard(dato)

    # Mostrar los valores restantes ordenados
    return sorted(values)

# Llamada a la función con el archivo que contiene las operaciones

archivo = input("Ingrese el nombre del archivo de operaciones: ")  # Asegúrate de tener este archivo en tu directorio
resultados = procesar_operaciones(archivo)

# Imprimir los valores que quedan en la lista
print(resultados)
print(len(resultados))