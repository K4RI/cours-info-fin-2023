const a = 12;
const b: number = 12;
console.log(a, b)
// const c: string = 12; // error TS2322: Type 'number' is not assignable to type 'string'.

let x = "hello"
// x = 12; // pareil

const s: "a" = "a"
// const t: "a" = "b" // error TS2322: Type '"b"' is not assignable to type '"a"'.

type Id = number | "A" | "B";
const t: Id = 5
const u: Id = "A"
// const v: Id = "C" // error TS2322: Type '"C"' is not assignable to type 'Id'.
const v: Id = "B"
console.log(t, u, v)

// fonctions
const f = (id: Id): "Yes" | "No" => {
    if (id === "A"){
        return "Yes";
    }
    return "No";
}

// typage d'un objet
type Pos = { x: number; y: number };
const p: Pos = { x: 10, y: 20 };

// conjonction de types
type Vect3D = Pos & { z: number };
const q: Vect3D = { x: 10, y: 20, z: 30 };