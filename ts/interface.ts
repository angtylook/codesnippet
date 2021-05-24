// 接口
interface IPerson {
    readonly id:number  // 只读属性
    firstName: string
    lastName: string
    age?: number  // 可选属性
}

function showFullName(person: IPerson) {
    return person.firstName + '_' + person.lastName
}

const author = {
    id: 1,
    firstName: "zhang",
    lastName: "zhiwei"
}

console.log(showFullName(author))

// 函数类型

interface ISearchFunc {
    (source:string, subString:string):boolean
}

const searchString: ISearchFunc = function(source:string, subString: string):boolean {
    return source.search(subString) > -1
}
