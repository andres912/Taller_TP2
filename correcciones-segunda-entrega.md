# Correcciones

Se agregaron la mayoría de las correcciones propuestas (falto eliminar copia del thread).
Se eliminó el uso del lock, que estaba bien.

Nota final: 8

Respecto al informe, el hecho de que no puedas copiar un mutex es porque son objetos atómicos y no tiene sentido copiarlos ¿Qué psa si copias un mutex en uso? ¿La copia de tu objeto copiado es atómica?
Por este motivo un mutex no es copiable, tenelo en cuenta para futuras estructuras.
