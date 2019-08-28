# Ejercicio 2 - Manipulación de datos

- Imprimamos en consola el nombre completo de cada persona en la lista y su edad. No mostrar su edad si es `None`, por ejemplo:

```
alejandro nanez - 32
john doe
jane doe
```

# Documentación:

- https://reasonml.github.io/docs/en/if-else
- https://reasonml.github.io/docs/en/pattern-matching
- https://reasonml.github.io/docs/en/list-and-array
- https://github.com/arecvlohe/reasonml-cheat-sheet
- [ReasonML Standard Library](https://reasonml.github.io/api/index)
- [Reason String API](https://reasonml.github.io/api/String.html)
- [Bucklescript Standard Library](https://bucklescript.github.io/docs/en/stdlib-overview)
- [Belt.List.Keep](https://bucklescript.github.io/bucklescript/api/Belt.List.html#VALkeep)

# Bonus 💰
- Transforma el nombre y el apellido a mayúscula
- Crea dos estructuras nuevas, una que contenga las personas con edad y otra las personas que no tengan edad.

```sh
# En consola
ALEJANDRO NANEZ - 32
JOHN DOE
JANE DOE
```

```reason
let peopleWithAge = // filtrar personas con edad;
let peopleWithoutAge = // filtrar personas sin edad

Js.log(peopleWithAge);
Js.log(peopleWithoutAge);
```
