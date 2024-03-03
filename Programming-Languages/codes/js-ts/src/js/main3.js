// https://designftw.mit.edu/lectures/javascript/index.html#object-literals

let today = new Date();
console.log(today.toLocaleString("en-GB", {
	day: "numeric",
	month: "long",
	year: "numeric",
	dayPeriod: "long"
}));
console.log(today)


// PROPRIÉTÉS
let user = {
	name: "Lea Verou",
	age: 34
};
console.log(user.hobbies); // undefined

let userr = {
	name: "Lea Verou",
	age: 34
};
userr.age = undefined;
console.log(userr); // { name: 'Lea Verou', age: undefined }

let hobbies = ["Coding", "Cooking"];
hobbies.user = "Lea Verou";
console.log(hobbies.length, hobbies.user);
// l'array est un objet, on lui a rajouté un "attribut"
// sans changer sa longueur

let hobbiess = ["Coding", "Cooking"];
hobbiess["1"] = "Dining"; // a changé l'attribut hobbiess[1]
console.log(hobbiess[1], hobbiess["1"]);

// SCOPING
if (true) {
	let x = 1;
}
// console.log(x); // not defined


let person = {
	name: "David",
	hello: () => console.log(this),
		// affiche "{}", alors que console.log(person) affiche tout
};
person.hello();

// exemples de fonctions d'ordre supérieur
nombres = [1, 2, 3, 4, 5]
console.log(nombres.map(x => x**2)) // la liste des images
console.log(nombres.filter(x => x%2)) // filtre les éléments selon un prédicat
console.log(nombres.reduce((acc, cur) => acc + cur)) // somme
console.log(nombres.reduce((acc, cur) => acc + String(cur))) // concaténation
nombres.forEach(element => {
	console.log("L'élément vaut", element) // applique à tous les éléments
});
console.assert(nombres.filter(x => x%2).every(x => x%2))


// this
let greet = function() {
	console.log(`Hi, I’m ${this.name}`);
};
let instructors = [
	{name: "Lea", greet: greet},
	{name: "David", greet: greet}
];
for (let instructor of instructors) {
	instructor.greet();
}

let logContext = function() {
	console.log(this == globalThis); // true
}
logContext();
console.log(globalThis.globalThis == globalThis); // true
console.log(globalThis); // toutes les variables globales enft // dans un navigateur ce sera Window


function logContext2() {
	console.log(this);
}
let logContext3 = logContext2.bind({foo: 1});
console.log(logContext3)

// classes
/*
class ClickCounter extends HTMLElement {
	#clicks = 0;

	constructor() {
		super();
		this.#render();
		this.addEventListener('click', this.#clicked)
	}
	#render () {
		this.innerHTML = `Clicked ${this.#clicks}x`;
	}
	#clicked () {
		this.#clicks++;
		this.#render();
	}
}
customElements.define('click-counter', ClickCounter);
*/



class Person {
	constructor (name, birthday) {
		this.name = name;
		this.born = new Date(birthday);
	}
	getAge () {
		const ms = 365 * 24 * 60 * 60 * 1000;
		return (new Date() - this.born) / ms;
	}
}
let david = new Person(
	"David Karger",
	"1967-05-01T01:00"
);
console.log(david.getAge());

// accessors
let lea = {
	birthday: new Date("1986-06-13T13:00"),
	get age () {
		const ms = 365 * 24 * 60 * 60 * 1000;
		return (new Date() - this.birthday) / ms;
	}
}
lea.age = 30;
console.log(lea.age);
// là ça change rien
lea.birthday = new Date("1992-04-01T13:00");
console.log(lea.age);
// là ça change, comme age est calculé à partir de birthday

let learg = {
	birthday: new Date("1986-06-13T13:00"),
	set age (a) {
		const ms = 365 * 24 * 60 * 60 * 1000;
		this.birthday = new Date((Date.now() - ms * a));
	},
}
learg.birthday = new Date("1990-04-01T13:00");
learg.age=3; // ici set age modifie l'attribut birthday
console.log(learg.birthday); // 3 ans avant maintenant