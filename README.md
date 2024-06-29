## 🍔 Restaurante Mostasa C++ - Sistema de Gestión de Archivos

## 📌 Descripción del Proyecto
Este proyecto es el trabajo final de la materia Laboratorio II del año 2024, desarrollado por el grupo 36. El sistema está diseñado para gestionar los productos, reservas y clientes de un restaurante utilizando archivos y programado en C++.

El programa proporciona un sistema completo para la gestión del restaurante, incluyendo el ABML (Alta, Baja, Modificación, Listado) de productos, reservas y clientes, y una funcionalidad de copia de seguridad de cada uno de estos archivos. Las principales características incluyen listar el stock de productos, buscar clientes por nombre, buscar reservas por fecha, entre otras, accesibles a través de un menú principal.

## 👥 Integrantes del Grupo
* **Bernal Agustín Abraham**
* **López Abril Agustina**

### 📂 Tipo de Proyecto
* Sistema de gestión de archivos

### Nombre del Proyecto: Restaurante Mostasa C++

### Tema: Sistema que gestiona un restaurante.

#### 📄 Archivos Utilizados
- **Productos.dat**: ID, Nombre, Cantidad, Descripción, Disponible, Precio, Categoría.

- **Reservas.dat**: Numero, Fecha, NumeroMesa, IDCliente, IdProductoReservado, NumeroPersonas, Estado.

- **Clientes.dat**: ID, Nombre Completo, DNI, Teléfono, Email, Estado.


# 🚀 **Funcionalidades del Sistema**
### Menú Principal
### Menú Productos
    1. 📦 Listar stock de productos
    2. ➕ Cargar producto
    3. 🔍 Buscar producto por ID
    4. ❌ Baja lógica de productos
    5. ✏️ Modificación de productos
    6. 📊 Listar stock por precios o ID del menor al mayor
### Menú Clientes
    1. 🔍 Buscar cliente por nombre
    2. ➕ Cargar clientes
    3. 📋 Listar clientes
    4. ❌ Baja lógica de clientes
    5. ✏️ Modificación de clientes
    6. 🔍 Listar y buscar clientes
### Menú Reservas
    1. 📋 Listar reservas
    2. ➕ Cargar reserva
    3. 📅 Buscar reserva por fecha
    4. ❌ Baja lógica de reservas
    5. ✏️ Modificación de reservas
    6. 🪑 Listar mesas disponibles (no reservadas)
### Menú Configuración 🛠️
    1. ⚙️ Configuración general del sistema
    2. 🛠 Información Adicional sobre el Trabajo Realizado

# Clases Desarrolladas
+ ### Producto

Atributos: ID, Nombre, Cantidad, Descripción, Disponible, Precio, Categoría.
Métodos: sets, gets, constructor.

+ ### ProductoArchivo

Atributos: string Filename y FILE *P (Para el constructor y uso al abrir y cerrar archivos).
Métodos: Constructores, guardar en el archivo, modificar registro, contar cantidad de registros, buscar por posición en el archivo.
+ ### ProductoManager

Métodos: Listar stock, cargar producto, buscar producto por ID, baja lógica, modificación, listar stock por precios o ID del menor al mayor.
Reserva

Atributos: Numero, Fecha, NumeroMesa, IDCliente, IdProductoReservado, NumeroPersonas, Estado.
Métodos: sets, gets, constructor.
+ ### ReservaArchivo

+ ### ReservaManager

Métodos: Listar reservas, cargar reserva, buscar reserva por fecha, baja lógica, modificación, listar mesas disponibles (no reservadas).
Cliente

Atributos: ID, Nombre Completo, DNI, Teléfono, Email, Estado.
Métodos: sets, gets, constructor.
+ ### ClienteArchivo


+ ### ClienteManager

Métodos: Buscar cliente por nombre, cargar clientes, listar clientes, baja lógica, modificación, listar y buscar clientes.

+ ### MainManager

Se encargará del menú principal que conduce al resto de submenús.

## 🖥 Requisitos del Sistema
+ Compilador C++ compatible (g++, clang, etc.)
+ Sistema operativo compatible con la ejecución de archivos binarios generados por el compilador (Windows, Linux, macOS).
