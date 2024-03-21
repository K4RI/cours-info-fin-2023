"use strict";
// https://softchris.github.io/pages/javascript-composition.html#but-i-use-typescript-what-then
Object.defineProperty(exports, "__esModule", { value: true });
function Warrior(Base) {
    return class extends Base {
        constructor() {
            super(...arguments);
            this.say = 'Attaaack';
        }
        attack() { console.log("attacking..."); }
    };
} // Base (de type TBase) est le paramètre de la fonction constructor
class Player {
    constructor(name) {
        this.name = name;
    }
}
const WarriorPlayerType = Warrior(Player); // ok on utilise le type
const warrior = new WarriorPlayerType("Conan"); // et on peut l'instancier c dingue ?!
console.log(warrior.say); // 'Attaaack'
warrior.attack(); // 'attacking...'
function Wings(Base) {
    return class extends Base {
        fly() { console.log("flying..."); }
    };
}
const WingsWarriorPlayerType = Wings(WarriorPlayerType); // ok c'est ça la composition !
const flyingWarrior = new WingsWarriorPlayerType("Flying Conan"); // yooooooo
flyingWarrior.fly();
