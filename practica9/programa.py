x = 10
print (x)

cadena = "Hola mundo"
print(cadena)

x = y = z = 10
print (x, y, z)

type (x)

type (cadena)

x = "Hola, mundo"
cadena = 10
type (x)

type (cadena)

SEGUNDOS_POR_DIA = 60 * 60 * 24
PI = 3.14

cadena1 = 'Hola'
cadena2 = "Mundo"
print(cadena1)
print(cadena2)
concat_cadenas = cadena1 + cadena2
print(concat_cadenas)

num_cadena = concat_cadenas +' '+ str(3)
print(num_cadena)

num_cadena = "Cambiando el orden: {1} {2} {0} #".format(cadena1, cadena2, 3)
print(num_cadena)

print (1 + 5)
print (6 * 3)
print (10 - 4)
print (100 / 50)
print (10 % 2)
print ( ( (20 * 3) + (10 + 1)) / 10)
print ( 2**2 )

print (7 < 5)
print (7 > 5)
print ((11 * 3)+2 == 36 - 1)
print ((11 * 3)+2 >= 36)
print ("curso" != "CuRsO")

lista_diasDelMes = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
print (lista_diasDelMes)
print (lista_diasDelMes[0])
print (lista_diasDelMes[6])
print (lista_diasDelMes[11])

lista_numeros = [['cero', 0], ['uno', 1, 'UNO'], ['dos', 2], ['tres', 3], ['cuatro', 4], ['X', 5]]

print (lista_numeros)

print (lista_numeros[0])
print (lista_numeros[1])

print (lista_numeros[2][0])
print (lista_numeros[2][1])

print (lista_numeros[1][0])
print (lista_numeros[1][1])
print (lista_numeros[1][2])

lista_numeros[5][0] = "cinco"
print (lista_numeros[5])

tupla_diasDelMes=(31,28,31,30,31,31,30,31,30,31)

print (tupla_diasDelMes)
print (tupla_diasDelMes[0])
print (tupla_diasDelMes[3])
print (tupla_diasDelMes[1])

tupla__numeros=(('cero', 0), ('uno', 1, 'UNO'), ('dos', 2), ('tres', 3), ('cuatro', 4), ('X', 5))

print (tupla__numeros)

print (tupla__numeros[0])
print (tupla__numeros[1])

print (tupla__numeros[2][0])
print (tupla__numeros[2][1])

print (tupla__numeros[1][0])
print (tupla__numeros[1][1])
print (tupla__numeros[1][2])

print ("valor actual {}".format(lista_diasDelMes[0]))
lista_diasDelMes[0] = 50
print ("valor cambiado {}".format(lista_diasDelMes[0]))
tupla_diasDelMes[0] = 50

from collections import namedtuple

planeta = namedtuple('planeta', ['nombre', 'numero'])
planeta1 = planeta('Mercurio', 1)
print (planeta1)

planeta2 = planeta ('Venus', 2)
print (planeta2)

print (planeta1.nombre, planeta1.numero)
print (planeta2[0], planeta2[1])

print('Campos de la tupla: {}'.format(planeta1._fields))

elementos = {'hidrogeno':1, 'helio': 2, 'carbon': 6}

print (elementos)
print (elementos['hidrogeno'])

elementos = {'hidrogeno': 1, 'helio': 2, 'carbon': 6}

print (elementos)

print (elementos['hidrogeno'])

elementos ['litio']= 3
elementos ['nitrogeno'] = 8

print (elementos)

elementos2 = {}
elementos2['H'] = {'name': 'Hydrogen', 'number':1, 'weight': 1.00794}
elementos2['He'] = {'name': 'Helium', 'number':2, 'weight': 4.0026}

print (elementos2)

print (elementos2['H'])
print (elementos2['H']['name'])
print (elementos2['H']['number'])
elementos2['H']['weight'] = 4.30
print (elementos2['H']['weight'])

elementos2['H'].update({'gas noble':True})
print (elementos2['H'])

print (elementos2.items())

print (elementos2.keys())


def imprime_nombre (nombre):
  print("hola "+nombre)

imprime_nombre("JJ")

def cuadrado(x):
  return x**2

x = 5
print("El cuadrado de{} es {}".format(x, cuadrado(x)))

def varios (x):
  return x**2, x**3, x**4

val1, val2, val3 = varios(2)
 print("{} {} {}".format(val1, val2, val3))

def cuadrado_default (x=3):
  return x**2

cuadrado_default()
val4, _, val5 = varios(2)
print("{} {}".format(val4, val5))

vg = 'Global'
def funcion_v1():
  print(vg)
  funcion_v1()
print(vg)

def funcion_v2():
  vg = 'Local'
  print(vg)

funcion_v2()
print(vg)

def funcion_v3():
  print(vg)
  vg = "LOcal"
  print(vg)
  funcion_v3()

def funcion_v4():
  global vg
  print(vg)
  vg = "Local"
  print(vg)
  funcion_v4()
print(vg)

def obtenerMayor (param1, param2):
  if param1 < param2:
    print ('{} es mayor que {}'.format(param2, param1))
obtenerMayor(5, 7)
obtenerMayor(7, 5)

x = y = z = 3
if x == y == z:
  print(True)
  def obtenerMayorv2 (param1, param2):
  if param1 < param2:
    return param2
  else:
    return param1

def obtenerMayorv2 (param1, param2):
  if param1 < param2:
    return param2
  else:
    return param1

print ("El mayor es {}".format( obtenerMayorv2(4, 20) ))

print ("El mayor es {}".format( obtenerMayorv2(11, 6) ))

def obtenerMayor_idiom (param1, param2):
  valor = param2 if (param1 < param2) else param1
  return valor

print ("El mayor es {}".format( obtenerMayor_idiom(11, 6) ))

def numeros(num):
  if num == 1:
    print ("tu numero es 1")
  elif num==2:
    print ("el numero es 2")
  elif num==3:
    print ("el numero es 3")
  elif num==4:
    print ("el numero es 4")
  else:
    print("no hay opcion")

numeros(2)
numeros(5)

def obtenerMasGrande (a, b, c):
  if a > b:
    if a > c:
      return a
    else:
      return c
  else:
    if b > c:
      return b
    else:
      return c

print ("El mas grande es {}".format(obtenerMasGrande(7, 13, 1) ))

def cuenta(limite):
  i = limite
  while True:
    print (i)
    i = i -1
    if i == 0:
      break

cuenta (10)

def factorial (n):
  i = 2
  tmp = 1
  while i <n+1:
    tmp = tmp * i
    i = i + 1
  return tmp
  print (factorial(4))
  print (factorial(6))

for x in [1, 2, 3, 4, 5]:
  print(x)

for x in range(5):
  print (x)

for x in range (-5, 2):
  print(x)

for num in ["uno", "dos", "tres", "cuatro"]:
  print(num)

elementos = {'hidrogeno': 1, 'helio': 2, 'carbon': 6}

for llave, valor in elementos.items():
  print(llave, " = ", valor)

for llave in elementos.keys():
  print(llave)

for valor in elementos.values():
  print(valor)

for idx, x in enumerate (elementos):
  print("El índice es: {} y el elemento: {}".format(idx, x))

def cuenta_idiom(limite):
  for i in range (limite, 0, -1):
    print (i)
  else:
    print("Cuenta finalizada")

cuenta_idiom(5)

def cuenta_idiomv2(limite):
  for i in range (limite, 0, -1):
    print (i)
    if i == 3:
      break
    else:
      print("Cuenta finalizada")

cuenta_idiomv2 (5)

import math

x = math.cos (math.pi)

print (x)

from math import cos, pi

x = cos(pi)

print (x)

print (dir(math))

help(math.log)

import math as ma

x = ma.cos(ma.pi)

print(x)

%pylab inline

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

x = linspace(0, 5, 20)

fig, ax = plt.subplots (facecolor='w', edgecolor='k')
ax.plot(x, sin(x), marker="o", color="r", linestyle='None')

ax.grid(True)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.grid(True)
ax.legend(["y = x**2"])

plt.title('Puntos')
plt.show()

fig.savefig("gráfica.png")

 
