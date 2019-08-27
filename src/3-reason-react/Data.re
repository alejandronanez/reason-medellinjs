type person = {
  nombre: string,
  apellido: string,
  edad: option(int),
};

type people = list(person);

let personOne = {
  nombre: "tu nombre",
  apellido: "tu apellido",
  edad: Some(32),
};

let personTwo = {nombre: "John", apellido: "Doe", edad: None};
let personThree = {nombre: "Jane", apellido: "Doe", edad: None};

let people = [personOne, personTwo, personThree];

let peopleWithAge =
  people->Belt.List.keep(person => Belt.Option.isSome(person.edad));

let peopleWithoutAge =
  people->Belt.List.keep(person => Belt.Option.isNone(person.edad));
