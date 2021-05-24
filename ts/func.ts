(()=>{
    // add 变量名
    // (x:string, y:string)=>number  函数类型
    // function(x:string, y:string):number // 函数
    const add: (x:string, y:string)=>number = function(x:string, y:string):number {
        return parseInt(x) + parseInt(y)
    }

    console.log(add("1","2"))

    // 可选参数 lastName
    // 默认参数 firstName
    function getFullName(firstName:string = "独孤", lastName?:string) : string {
        if(lastName) {
            return firstName + " " + lastName
        } else {
            return firstName
        }
    }

    console.log(getFullName())
    console.log(getFullName("诸葛"))
    console.log(getFullName("诸葛", "孔光"))

    // 不定参数
    // 不定参数要放在最后
    function showMessage(str:string, ...args: string[]) {
        console.log(str)
        console.log(args)
        console.log(args.join("-"))
    }

    showMessage("a", "b", "c", "d")

    // 函数重载
    // 重载函数声明
    function concat(x:number, y:number): number
    function concat(x:string, y:string): string
    // 重载函数实现
    function concat(x: string| number, y: string|number): string|number {
        if(typeof x === "string" && typeof y === "string") {
            return x+y
        } else if(typeof x === "number" && typeof y === "number") {
            return x+y
        }
        return ""
    }
    console.log(concat("zzw", "hcl"))
    console.log(concat(56, 78))

    // console.log(concat("zzw", 78))  // will error
    // console.log(concat(56, "hcl"))  // will error

    // 函数声明
    // 方式1
    type Longhand = {
        (a:number): number,
    }
    // 方式2
    type ShortHand = (a:number) =>number

    type LongHandAllowsOverloadDeclarations = {
        (a:number): number,
        (a:string): string,
    }

})()


