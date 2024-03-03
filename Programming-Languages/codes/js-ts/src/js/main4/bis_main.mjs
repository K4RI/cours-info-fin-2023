// import d'un autre module
// requiert ainsi l'extension .mjs
import { getX, setX } from "./bis_module.mjs";
console.log(getX()); // 5
setX(6);
console.log(getX()); // 6