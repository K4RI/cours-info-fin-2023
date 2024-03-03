// https://www.cs.middlebury.edu/~candrews/classes/cs312-f20/lectures/lecture01-javascript

console.log(5 == "5")
console.log(5 === "5")

function varTest() {
    var x = 1;
    if (true) {
        var x = 2;
        console.log(x);
    }
    console.log(x); // What will print here?
}
varTest() // 2, 2

function letTest() {
    let x = 1;
    if (true) {
        let x = 2;
        console.log(x);
    }
    console.log(x); // What will print here?
}
letTest() // 2, 1. Le let ne concerne que le bloc if true.

const f = function moreDescriptiveNameForF() {};



const wrapValue = (n) => {
    let local = n;
    return () => local;
};

let wrap1 = wrapValue(1);
let wrap2 = wrapValue(2);
console.log(wrap1()); // What will print here? : 1
console.log(wrap2()); // What will print here? : 2

// 
var funcs = [];
for (var i = 0; i < 3; i++) {
    // Create 3 functions and
    funcs[i] = () => {
        // store them in the funcs array,
        console.log("My value: " + i); // each should log its value.
    };
}
for (var j = 0; j < 3; j++) {
funcs[j](); //  Run each function to print values
}
// écrit 3.
// car à chaque fois il revient à la ligne "console.log(i)"
// le var i est dans la closure, il vaut toujours 3
// tandis qu'avec un let i, le i est du block est vaut 1, 2, puis 3.


let rectangle = {
    x: 20,
    y: 20,
    width: 10,
    height: 25,
    aspectRatio: () => {
        this.width / this.height;
    },
};
console.log(rectangle.x)
console.log(rectangle['y'])
rectangle.color = 'red';
console.log(rectangle)

// constructeur de classe
class Hello {
    constructor(name) {
        this.name = name;
    }   

    hello() {
        return "Hello " + this.name + "!";
    }

    static sayHelloAll() {
        return "Hello everyone!";
    }
    }

    class HelloWorld extends Hello {
    constructor() {
        super("World");
    }

    echo() {
        console.log(super.hello());
    }
}

const hw = new HelloWorld();
hw.echo(); // Hello World!
console.log(hw.hello()); // Hello World!
console.log(Hello.sayHelloAll()); // statique, appelable sans instance. Hello everyone!

console.log(typeof HelloWorld) // function
console.log(typeof hw) // object


const counter = function CounterClosure() {
    let count = 0;
    return () => count++;
};
let cn = counter();
console.log(cn())
console.log(cn())
