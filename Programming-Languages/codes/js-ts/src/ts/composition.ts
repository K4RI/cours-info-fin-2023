// https://softchris.github.io/pages/javascript-composition.html#but-i-use-typescript-what-then

type Constructor<T = {}> = new (...args: any[]) => T

function Warrior<TBase extends Constructor>(Base: TBase) {
    return class extends Base {
        say: string = 'Attaaack';
        attack() { console.log("attacking...") }
    }
} // Base (de type TBase) est le paramètre de la fonction constructor

class Player {
    constructor( private name: string ) {}
}

const WarriorPlayerType = Warrior(Player); // ok on utilise le type
const warrior = new WarriorPlayerType("Conan"); // et on peut l'instancier c dingue ?!
console.log(warrior.say); // 'Attaaack'
warrior.attack(); // 'attacking...'

function Wings<TBase extends Constructor>(Base: TBase) {
    return class extends Base {
        fly() { console.log("flying...") }
    }
}

const WingsWarriorPlayerType = Wings(WarriorPlayerType); // ok c'est ça la composition !
const flyingWarrior = new WingsWarriorPlayerType("Flying Conan"); // yooooooo
flyingWarrior.fly();