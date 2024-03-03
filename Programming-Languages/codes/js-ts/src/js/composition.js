// EXEMPLE 1 : https://javascript.plainenglish.io/inheritance-is-a-vs-composition-has-a-in-javascript-98fb96dfa0e6

// Héritage de classes :
class Person  {
    eat() {
        console.log('I am eating');
    }
    breathe(){
        console.log('I am breathing');
    }    
    swim(){
        console.log('I am swimming');
    } 
}
class Magician  extends Person{
    trick() {
        console.log('I am doing a trick');
    }
}
let liv = new Magician();
let harry = new Magician();

// Composition : on combine les abstractions (=fonctions) vers de plus grandes
const eat = function () {
    return {
        eat: () => { console.log('I am eating'); }
    }
}
const breathe = function () {
    return {
        breathe: () => { console.log('I am breathing'); }
    }
}
const swim = function () {
    return {
        swim: () => { console.log('I am swimming'); }
    }
}
const trick = function () {
    return {
        trick: () => { console.log('I am doing a trick'); }
    }
}
const superMagician = ()=> { // peut faire de la magie mais pas nager
 return Object.assign(
     {},
     eat(),
     breathe(),
     trick()
   );
}
const noviceMagician = () => { // peut nager mais pas faire de la magie
 return Object.assign(
     {},
     eat(),
     breathe(),
     swim()
   );
}
// exemple : gérer les permissions de lecture-écriture-suppression de fichiers



// EXEMPLE 2 : https://softchris.github.io/pages/javascript-composition.html#object-composition-without-classes

// ici on définit les behaviors
const steer = {
    steer() {
        console.log(`steering ${this.name}`)
    }
}
const run = {
    run() {
        console.log(`${this.name} is running`)
    }
}
const fly = {
    fly() {
        console.log(`${this.name} is flying`)
    }
}

// on compose
const steerAndRun = { ...steer, ...run };
const flyingAndRunning = { ...run, ...fly };

// et toutes les behviors peuvent être placées dans un objet
function createVehicle(name, behaviors) {
    return {
        name,
        ...behaviors
    }
}
  
const car = createVehicle('Car', steerAndRun)
car.steer();
car.run();

const crappyDelorean = createVehicle('Crappy Delorean', flyingAndRunning)
crappyDelorean.run();
crappyDelorean.fly();