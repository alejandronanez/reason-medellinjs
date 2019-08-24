type person = {
  nombre: string,
  apellido: string,
  edad: option(int),
};

let personOne = {
  nombre: "tu nombre",
  apellido: "tu apellido",
  edad: Some(32),
};

let personTwo = {nombre: "John", apellido: "Doe", edad: None};
let personThree = {nombre: "Jane", apellido: "Doe", edad: None};

let people = [personOne, personTwo, personThree];

/**
 * Solución #1 ✅
 */
Belt.List.forEach(
  people,
  person => {
    let nombreCompleto = person.nombre ++ " " ++ person.apellido;
    let edad =
      switch (person.edad) {
      | Some(edad) => "(" ++ string_of_int(edad) ++ ")"
      | None => ""
      };

    Js.log(nombreCompleto ++ edad ++ "\n");
  },
);

/**
 * Solución #2 ✅✅
 */
let getFullName = person =>
  switch (person.edad) {
  | Some(edad) =>
    person.nombre
    ++ " "
    ++ person.apellido
    ++ "("
    ++ string_of_int(edad)
    ++ ")"
  | None => person.nombre ++ " " ++ person.apellido
  };

Belt.List.forEach(people, person => Js.log(getFullName(person) ++ "\n"));

/**
 * Solución 3 + Bonus ✅✅✅
 */;
people
->Belt.List.map(getFullName)
->Belt.List.map(String.uppercase)
->Belt.List.forEach(Js.log);

let peopleWithAge =
  Belt.List.keep(people, person => Belt.Option.isSome(person.edad));
let peopleWithoutAge =
  Belt.List.keep(people, person => Belt.Option.isNone(person.edad));

Js.log2("Con edad: ", peopleWithAge);
Js.log2("Sin edad: ", peopleWithoutAge);

/**
 * JS: 🤷‍
 *    people
 *      .map(getFullName)
 *      .map(fullName => fullName.toUpperCase())
 *      .forEach(console.log)
 */;
