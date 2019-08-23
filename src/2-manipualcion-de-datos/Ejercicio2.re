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
