"use strict";
// 类型注解
function sayHI(name) {
    return "hello " + name;
}
console.log(sayHI("who"));
var flag = true;
var a1 = 10;
var a2 = 12.34;
var a3 = 3;
var a4 = 83;
var a5 = 0x123;
var str1 = 'hello';
console.log(str1 + "," + a5);
var und = undefined;
var nul = null;
console.log("undefined", und);
console.log("null", nul);
// undefined和null可以赋值给其它类型，和判断
if (a1 === undefined) {
    console.log("a1 ==== undefined");
}
if (str1 === null) {
    console.log("str1 === null");
}
