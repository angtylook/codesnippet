let arr1: number[] = [10,20,30,40,50]

// 范型
let arr2: Array<number> = [100,200]

console.log(arr1)
console.log(arr2)

// tuple 元组

let arr3:[string, number, boolean] = ["hello", 12.34, true]
console.log(arr3)
console.log(arr3[0].toUpperCase())
console.log(arr3[1].toFixed(1))