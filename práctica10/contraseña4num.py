import time
import itertools
import string

def buscador(con, max_length):
    """
    Intenta adivinar la contraseña 'adc' por fuerza bruta usando dígitos.
    max_length: Longitud máxima de las combinaciones a probar.
    """
    
    caracteres = string.digits
    encontrado = False
    
    t0 = time.time()
    
    for length in range(1, max_length + 1):
        print(f"-> Probando contraseñas de longitud {length}...")
        
        for combinacion_tuple in itertools.product(caracteres, repeat=length):
            prueba = "".join(combinacion_tuple)
            
            if prueba == con:
                t1 = time.time()
                tiempo_ejecucion = round(t1 - t0, 6)
                print("-" * 30)
                print(f"Contraseña encontrada, tu contraseña es *{prueba}*")
                print(f"Tiempos de ejecución: {tiempo_ejecucion} segundos.")
                print("-" * 30)
                encontrado = True
                return tiempo_ejecucion
                
        if encontrado:
            break
            
    if not encontrado:
        t1 = time.time()
        tiempo_ejecucion = round(t1 - t0, 6)
        print(f"No se encontró la contraseña '{adc}' después de probar hasta {max_length} caracteres.")
        return tiempo_ejecucion

print("## Pruebas de Fuerza Bruta")
print("---")

con_4 = '7483'
print(f"### 1. Intentando crackear la contraseña '{con_4}' (max_length=4)")
buscador(con_4, 4)
