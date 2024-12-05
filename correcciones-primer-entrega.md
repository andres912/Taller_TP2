# Correcciones

En terminos generales el tp está bastante bien. Se agregaron algunos issues, pero también quería marcar estos detalles:

`evaluaGrafo()` devuelve un string, es mejor si devuelve un enum y después imprimís la respuesta acorde a ese enum.
`Grafo::imprimir()` ¿Es una función de debug?

Pasarle cppcheck para encontrar copias innecesarias y otros detalles menores que no marqué.

Arreglar la race condition es crítico para aprobar el tp

Nota: 3 (reentrega)
