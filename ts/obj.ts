function getObj(obj:object): object {
    console.log(obj)
    return {
        name: "东方不败",
        age: 25
    }
}

console.log(getObj({input:"void"}))
console.log(new String())
console.log(new Number())

// Union Types

function getString(str_or_num: string|number):string {
    return str_or_num.toString()
}

console.log(getString("123"))
console.log(getString(234))

// 类型断言、判断类型

function getLength(str: number|string): number {
    if((<string>str).length) {  // 类型断言，有点像强制类型转换
        return (str as string).length  // 另一种写法
    } else {
        return str.toString().length
    }
}

// 类型自动推导

let txt = 1234 // number 
// txt = 'text' // fail
let what // any
what = txt
what = "any type"





