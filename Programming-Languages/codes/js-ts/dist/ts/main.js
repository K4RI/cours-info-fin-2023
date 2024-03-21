"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const a = 12;
const b = 12;
console.log(a, b);
// const c: string = 12; // error TS2322: Type 'number' is not assignable to type 'string'.
let x = "hello";
// x = 12; // pareil
const s = "a";
const t = 5;
const u = "A";
// const v: Id = "C" // error TS2322: Type '"C"' is not assignable to type 'Id'.
const v = "B";
console.log(t, u, v);
// fonctions
const f = (id) => {
    if (id === "A") {
        return "Yes";
    }
    return "No";
};
const p = { x: 10, y: 20 };
const q = { x: 10, y: 20, z: 30 };
