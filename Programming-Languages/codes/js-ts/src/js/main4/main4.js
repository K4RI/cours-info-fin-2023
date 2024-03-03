// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Closures

function makeFunc() {
    const name = "Mozilla";
    function displayName() {
        console.log(name);
    }
    return displayName;
}
const myFunc = makeFunc();
myFunc();
// la closure = la fonction + son environnement lexical, ici displayName + name

function makeAdder(x) { // function factory
    return function (y) {
      return x + y;
    };
}
const add5 = makeAdder(5); // add5 contient x=5 dans sa closure
const add10 = makeAdder(10); // add10 contient x=10 dans sa closure
console.log(add5(2)); // 7
console.log(add10(2)); // 12


if (typeof document !== 'undefined') {
  // ne s'exécute que sur navigateur avec main4.html
  // placer <script src="main4.js"></script> à la fin du body, après les defs des boutons
  function makeSizer(size) {
    return function() {
      document.body.style.fontSize = size + 'px';
    };
  }

  var size12 = makeSizer(12);
  var size14 = makeSizer(14);
  var size16 = makeSizer(16);

  document.getElementById('size-12').onclick = size12;
  document.getElementById('size-14').onclick = size14;
  document.getElementById('size-16').onclick = size16;
  console.log("Boutons attribués")
}


const counter = (function () {
  let privateCounter = 0;
  function changeBy(val) {
    privateCounter += val;
  }
  return {
    increment() {
      changeBy(1);
    },
    decrement() {
      changeBy(-1);
    },
    value() {
      return privateCounter;
    },
  };
})();

console.log(counter.value()); // 0.

counter.increment(); // modifie l'attribue privateCounter avec increment()
counter.privateCounter = 55
counter.increment();
console.log(counter.value()); // 2.

counter.decrement();
console.log(counter.value()); // 1.


// chaîne : global scope
const e = 10;
function sum(a) {
  return function (b) {
    return function (c) {
      // outer functions scope
      return function (d) {
        // local scope
        return a + b + c + d + e;
      };
    };
  };
}
console.log(sum(1)(2)(3)(4)); // 20


function outer() {
  let getY;
  {
    const y = 6; // variable block-scoped
    getY = () => y;
  }
  console.log(typeof y); // undefined, elle n'est plus définie ici
  console.log(getY()); // 6
}
outer();
