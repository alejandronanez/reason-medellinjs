// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';


var personOne = /* record */[
  /* nombre */"tu nombre",
  /* apellido */"tu apellido",
  /* edad */32
];

var personTwo = /* record */[
  /* nombre */"John",
  /* apellido */"Doe",
  /* edad */undefined
];

var personThree = /* record */[
  /* nombre */"Jane",
  /* apellido */"Doe",
  /* edad */undefined
];

var people_001 = /* :: */[
  personTwo,
  /* :: */[
    personThree,
    /* [] */0
  ]
];

var people = /* :: */[
  personOne,
  people_001
];

exports.personOne = personOne;
exports.personTwo = personTwo;
exports.personThree = personThree;
exports.people = people;
/* No side effect */