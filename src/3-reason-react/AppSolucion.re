[@react.component]
let make = () => {
  <div>
    <p> Data.personOne.nombre->React.string </p>
    <p> Data.personOne.apellido->React.string </p>
    <p>
      {switch (Data.personOne.edad) {
       | Some(edad) => edad->string_of_int->React.string
       | None => "No tiene edad"->React.string
       }}
    </p>
  </div>;
};
