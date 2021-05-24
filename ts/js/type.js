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
// enum
var Color;
(function (Color) {
    Color[Color["red"] = 1] = "red";
    Color[Color["green"] = 2] = "green";
    Color[Color["blue"] = 3] = "blue";
})(Color || (Color = {}));
var color = Color.red;
console.log(color, Color.green, Color.blue);
// 输出枚举名字
console.log(Color[color], Color[Color.green], Color[Color.blue]);
// any
var str = 100;
str = '年少不识王老五';
var anyArr = ["abc", 123, true, Color.red];
console.log(str);
console.log(anyArr);
console.log(anyArr[0].split(''));
// void 只能赋值void undefined
function showMessage() {
    console.log("重点，要考");
    // return null, undefined
    // return "abc"   // Type 'string' is not assignable to type 'void'
}
console.log(showMessage()); // undefined
