function print1(s) {
    console.log(s);
}

var print2 = function(s) {
    console.log(s);
};

var print3 = function x() {
    console.log(typeof x);
}

print3()

var add = new Function('x', 'y', 'return x + y');
console.log(add(1,2))

function f() {
    console.log(1)
}
f()  // 2
// redefine
function f() {
    console.log(2)
}
f()  // 2

function f1(a, b) { return a + b;}
console.log(f1.name, f1.length, f1.toString())
var f2 = function (a) {};
console.log(f2.name, f2.length)
var f3 = function myName(a,b,c) {};
console.log(f3.name, f3.length)

