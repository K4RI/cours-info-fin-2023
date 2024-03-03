// https://www.typescriptlang.org/docs/handbook/typescript-in-5-minutes-oop.html
// Erased Structural Types
interface Pointlike {
    x: number;
    y: number;
}
interface Named {
    name: string;
} // deux interfaces avec chacun leurs attributs
function logPoint(point: Pointlike) {
    console.log("x = " + point.x + ", y = " + point.y);
}
function logName(x: Named) {
    console.log("Hello, " + x.name);
} // une fonction de chaque interface
const obj = {
    x: 0,
    y: 0,
    name: "Origin",
}; // un objet ayant les attributs des deux interfaces
logPoint(obj);
logName(obj);
// même si l'on a pas déclaré explicitement obj comme implémentant Pointlike et Named, il le peut par construction.

class Empty {} 
function fn(arg: Empty) {
    console.log("Empty !")
}
fn({ k: 10 }); // de la même manière, l'objet ici en argument compte comme un Empty...


// https://www.typescriptlang.org/docs/handbook/typescript-in-5-minutes.html
let helloWorld:string = "Hello World";
console.log(helloWorld)

interface User {
    name: string;
    id: number;
}
/*const user: User = {
    username: "Hayes", // !!! username n'existe pas dans le type User
    id: 0,
};*/

// unions
type MyBool = true | false;
type WindowStates = "open" | "closed" | "minimized";
type LockStates = "locked" | "unlocked";
type PositiveOddNumbersUnderTen = 1 | 3 | 5 | 7 | 9;

function getLength(obj: string | string[]) {
    return obj.length;
} // ici la fonction peut prendre un str ou un array en argument, chacun ayant une .length

function wrapInArray(obj: string | string[]) {
    if (typeof obj === "string") {
        return [obj];
    }
    return obj;
}

// type avec des génériques
interface Backpack<Type> {
    add: (obj: Type) => void;
    get: () => Type;
}
  // This line is a shortcut to tell TypeScript there is a
// constant called `backpack`, and to not worry about where it came from.
declare const backpack: Backpack<string>; 
// object is a string, because we declared it above as the variable part of Backpack.
const object = backpack.get(); 
// Since the backpack variable is a string, you can't pass a number to the add function.
// backpack.add(23);
