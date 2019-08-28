# Ejercicio 3 - Reason React
- Rendericemos todas las personas creadas en los ejercicios anteriores (encontrarán la solución del ejercicio anterior en el archivo `Data.re`).
- Deberían escribir la solución en el archivo `App.re`

## Cómo correr el proyecto?
- `npm install`
- `npm run server`

## Bonus
- Mostrar un mensaje diferente si la persona tiene edad o no.

## Módulos / Nombres de archivo
En Reason, todos los módulos son globales no necesitamos exportar/importar lo que necesitemos explicitamente como en Javascript.

**Javascript**
```javascript
// Data.js
export const comunidades = [{id: 1, id: "2", id: 3}];

// Comunidades.js
import React from 'react';
import { comunidades } from './comunidades';

const Comunidades = () => <div>...</div>;

export default Comunidades;

// OtroComponente.js
import React from 'react';
import Comunidades from './Comunidades';

const OtroComponent = () => <Comunidades />;

export default OtroComponente;
```

**Reason**
```reason
// Data.re
let comunidades = [{id: 1, id: "2", id: 3}];

// Comunidades.re
[@react.component]
let make = () => <div>{Data.comunidades}</div>;

// OtroComponente.re
[@react.component]
let make = () => <Comunidades />
```


## ReasonReact
Reason React es muy parecido a React, de hecho, si has trabajado con React va a ser *casi "lo mismo"*.

A diferencia de Javascript, ReasonReact no acepta "cualquier valor" como `children`. Solamente acepta un `React.element`. Esto quiere decir que esto funcionaría en Javascript pero no en Reason:

**Javascript**
```javascript
// Javascript
const nombre = "medellinJs";
const edad = 5;

const ElComponente = () => <div>{nombre} - {edad}</div>;
```

Para hacer que este código funcione en Reason, debemos hacer:

**Reason**
```reason
/** ElComponente.re */
let nombre = "medellinJs";
let edad = 5;

[@react.component]
let make = () => <div>{React.string(nombre)} {React.string(string_of_int(edad))}</div>
```

Esto también sucede con arrays y listas, ReasonReact no puede renderizar una lista o un array directamente, necesitamos utilizar `React.array`

**Javascript**
```javascript
// Javascript
const comunidades = [
  {id: 1},
  {id: "2"},
  {id: 3},
];

const ElComponente = () => (
  <ul>
    {comunidades.map(comunidad => (
      <li key={comunidad.id}>{comunidad.id}</li>
    ))}
  </ul>
);
```

**Reason**
```reason
/**
 * Data.re
 */
type comunidad = {
  id: string,
};

let comunidades = [
  {id: "1"},
  {id: "2"},
  {id: "3"},
];

/**
 * Comunidades.re
*/
[@react.component]
let make = (~comunidades) => {
  <ul>
    {Belt.List.map(comunidades, comunidad =>
       <li key={comunidad.id}>
         {React.string(comunidad.id)}
       </li>
     )
     ->Belt.List.toArray // Transforma la lista en un array
     ->React.array} // Vuelve el array en un array de React.element
  </ul>;
};

/** Con fast pipe operator */
let getCommunities = (comunidad: Data.numero) =>
  <li key={comunidad.id}> comunidad.id->React.string </li>;

[@react.component]
let make = (~comunidades) => {
  <ul>
    {comunidades
     ->Belt.List.map(getCommunities)
     ->Belt.List.toArray
     ->React.array}
  </ul>;
};
```
