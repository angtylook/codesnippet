// 类

interface IPerson1 {
    firstName: string
    lastName: string
}

class Person {
    firstName: string
    lastName: string
    fullName: string

    constructor (firstName:string, lastName:string = "default") {
        this.firstName = firstName
        this.lastName = lastName
        this.fullName = this.firstName + " " + this.lastName
    }
}

function showAllName(person: IPerson1) {
    return person.firstName + " " + person.lastName
}

const person = new Person("zhang", "zhiwei")
console.log(showAllName(person))

// 类实现接口

interface IFly {
    fly(): void
    engine: number
}

interface ISwim {
    swim(): number
}

class Bird implements IFly, ISwim {
    fly():void {
        console.log("bird can fly ", this.engine)
    }
    engine:number

    constructor(eng:number) {
        this.engine = eng
    }

    swim(): number {
        console.log("fish can swim", this.engine)
        return this.engine
    }
}

const bird = new Bird(1000)
bird.fly()
bird.swim()

// 接口组合(继承)
interface IFlySwim extends IFly, ISwim {
    flyAndSwim(): void
}

// 类继承
class SuperBird extends Bird implements IFlySwim {
    flyAndSwim(): void {
        console.log("not implements")
        super.fly()
        super.swim()  // call parent's method
    }

    startEngine() {
        console.log(`start engine ${this.engine}`)
    }

    constructor(power:number) {
        super(power)  // parent's constructor
    }
}

const superBird = new SuperBird(10000)
superBird.startEngine()

// 多态

class Animal {
    name:string
    constructor(name:string) {
        this.name = name
    }

    run(distance:number = 0) {
        console.log(`run ${distance}`, this.name)
    }
}

class Dog extends Animal {
    constructor(name: string) {
        super(name)
    }

    run(distance:number = 5) {
        console.log(`run ${distance}`, this.name)
    }
}

class Pig extends Animal {
    constructor(name: string) {
        super(name)
    }

    run(distance:number = 10) {
        console.log(`run ${distance}`, this.name)
    }
}

const ani: Animal = new Animal("animal")
ani.run()

const dog: Dog = new Dog("dog")
dog.run()

const pig: Pig = new Pig("pig")
pig.run()


const dog1:Animal = new Dog("dog1")
dog1.run()

const pig1:Animal = new Pig("pig1")
pig1.run()

function AnimalRun(ani: Animal) {
    ani.run()
}

let animals : Animal[] = [dog1, pig1]
for (let i:number  = 0; i < 2; i++) {
    AnimalRun(animals[i])
}

// 信息隐藏

// 默认 public 修饰，任意位置可以防问
// private 类内访问
// protected 类及子类访问
class Information {
    name: string
    readonly info: string = "default"  // readonly可以有默认值
    private readonly createTime?: number
    count: number
    public constructor(name:string, info:string) {
        this.name = name
        this.info = info  // readonly可以在构造函数中修改
        this.createTime = 0x20210327
        this.count = 0
    }
    public send() {
        // this.info = this.info + "not allowed"  // 无法修改readonly属性
        console.log("send")
    }

    get fullName() {
        this.count++
        console.log(this.count)
        return this.name
    }

    set fullName(name:string) {
        this.count++
        this.name = name
    }
}

let info = new Information("script", "void function()")
console.log(info.fullName)
info.fullName = "typescript"
console.log(info.fullName)

class Boy {
    // name参数叫参数属性，这时Boy拥有一个叫name的公共的属性成员
    static count: number = 0
    constructor(readonly name:string = "boy", private readonly gender = 'male') {
        this.name = name
        this.gender = gender
        Boy.count++
        // this.count++ // 错误
    }

    static getCount(): number {
        return this.count  // 可以
    }

    getCountInst():number {
        return Boy.count  // 错误
        // return this.count  // 错误
    }
}

let boy : Boy = new Boy("girl")
console.log(boy.name)
// boy.name = "girl" // not allowed
// console.log(boy.gender)  // private inaccessable
console.log(Boy.count)
Boy.getCount()
// console.log("boy get count")

// 抽象类

(()=>{
    // 抽象类不能被实例化
    abstract class Animal {
        // 抽象方法不能有实现
        abstract eat():void
        // 可以有实例方法
        run():void {
            console.log("not implements")
        }
    }

    class Dog extends Animal {
        eat():void {
            console.log("dog eat")
        }
    }

})()


