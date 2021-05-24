// 类型注解
function sayHI(name:string) {
    return "hello " + name
}

console.log(sayHI("who"))

let flag:boolean = true;

let a1: number = 10
let a2: number = 12.34
let a3: number = 0b11
let a4: number = 0o123
let a5: number = 0x123

let str1: string = 'hello'

console.log(`${str1},${a5}`)

let und: undefined = undefined
let nul: null = null

console.log("undefined", und)
console.log("null", nul)

// undefined和null可以赋值给其它类型，和判断

if(a1 === undefined) {
    console.log("a1 ==== undefined")
}

if(str1 === null) {
    console.log("str1 === null")
}

// enum

enum Color {
    red = 1, // default 0
    green,
    blue
}

let color : Color = Color.red;
console.log(color, Color.green, Color.blue)

// 输出枚举名字
console.log(Color[color], Color[Color.green], Color[Color.blue])

// any

let str:any = 100
str = '年少不识王老五'

let anyArr: any[] = ["abc", 123, true, Color.red]

console.log(str)
console.log(anyArr)
console.log(anyArr[0].split(''))

// void 只能赋值void undefined

function showMessage(): void {
    console.log("重点，要考")
    // return null, undefined
    // return "abc"   // Type 'string' is not assignable to type 'void'
}

console.log(showMessage()) // undefined



