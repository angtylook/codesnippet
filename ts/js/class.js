"use strict";
// 类
var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        if (typeof b !== "function" && b !== null)
            throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
var Person = /** @class */ (function () {
    function Person(firstName, lastName) {
        if (lastName === void 0) { lastName = "default"; }
        this.firstName = firstName;
        this.lastName = lastName;
        this.fullName = this.firstName + " " + this.lastName;
    }
    return Person;
}());
function showAllName(person) {
    return person.firstName + " " + person.lastName;
}
var person = new Person("zhang", "zhiwei");
console.log(showAllName(person));
var Bird = /** @class */ (function () {
    function Bird(eng) {
        this.engine = eng;
    }
    Bird.prototype.fly = function () {
        console.log("bird can fly ", this.engine);
    };
    Bird.prototype.swim = function () {
        console.log("fish can swim", this.engine);
        return this.engine;
    };
    return Bird;
}());
var bird = new Bird(1000);
bird.fly();
bird.swim();
// 类继承
var SuperBird = /** @class */ (function (_super) {
    __extends(SuperBird, _super);
    function SuperBird(power) {
        return _super.call(this, power) || this; // parent's constructor
    }
    SuperBird.prototype.flyAndSwim = function () {
        console.log("not implements");
        _super.prototype.fly.call(this);
        _super.prototype.swim.call(this); // call parent's method
    };
    SuperBird.prototype.startEngine = function () {
        console.log("start engine " + this.engine);
    };
    return SuperBird;
}(Bird));
var superBird = new SuperBird(10000);
superBird.startEngine();
// 多态
var Animal = /** @class */ (function () {
    function Animal(name) {
        this.name = name;
    }
    Animal.prototype.run = function (distance) {
        if (distance === void 0) { distance = 0; }
        console.log("run " + distance, this.name);
    };
    return Animal;
}());
var Dog = /** @class */ (function (_super) {
    __extends(Dog, _super);
    function Dog(name) {
        return _super.call(this, name) || this;
    }
    Dog.prototype.run = function (distance) {
        if (distance === void 0) { distance = 5; }
        console.log("run " + distance, this.name);
    };
    return Dog;
}(Animal));
var Pig = /** @class */ (function (_super) {
    __extends(Pig, _super);
    function Pig(name) {
        return _super.call(this, name) || this;
    }
    Pig.prototype.run = function (distance) {
        if (distance === void 0) { distance = 10; }
        console.log("run " + distance, this.name);
    };
    return Pig;
}(Animal));
var ani = new Animal("animal");
ani.run();
var dog = new Dog("dog");
dog.run();
var pig = new Pig("pig");
pig.run();
var dog1 = new Dog("dog1");
dog1.run();
var pig1 = new Pig("pig1");
pig1.run();
function AnimalRun(ani) {
    ani.run();
}
var animals = [dog1, pig1];
for (var i = 0; i < 2; i++) {
    AnimalRun(animals[i]);
}
// 信息隐藏
// 默认 public 修饰，任意位置可以防问
// private 类内访问
// protected 类及子类访问
var Information = /** @class */ (function () {
    function Information(name, info) {
        this.info = "default"; // readonly可以有默认值
        this.name = name;
        this.info = info; // readonly可以在构造函数中修改
        this.createTime = 0x20210327;
        this.count = 0;
    }
    Information.prototype.send = function () {
        // this.info = this.info + "not allowed"  // 无法修改readonly属性
        console.log("send");
    };
    Object.defineProperty(Information.prototype, "fullName", {
        get: function () {
            this.count++;
            console.log(this.count);
            return this.name;
        },
        set: function (name) {
            this.count++;
            this.name = name;
        },
        enumerable: false,
        configurable: true
    });
    return Information;
}());
var info = new Information("script", "void function()");
console.log(info.fullName);
info.fullName = "typescript";
console.log(info.fullName);
var Boy = /** @class */ (function () {
    function Boy(name, gender) {
        if (name === void 0) { name = "boy"; }
        if (gender === void 0) { gender = 'male'; }
        this.name = name;
        this.gender = gender;
        this.name = name;
        this.gender = gender;
        Boy.count++;
        // this.count++ // 错误
    }
    Boy.getCount = function () {
        return this.count; // 可以
    };
    Boy.prototype.getCountInst = function () {
        return Boy.count; // 错误
        // return this.count  // 错误
    };
    // name参数叫参数属性，这时Boy拥有一个叫name的公共的属性成员
    Boy.count = 0;
    return Boy;
}());
var boy = new Boy("girl");
console.log(boy.name);
// boy.name = "girl" // not allowed
// console.log(boy.gender)  // private inaccessable
console.log(Boy.count);
Boy.getCount()(function () {
    // 抽象类不能被实例化
    var Animal = /** @class */ (function () {
        function Animal() {
        }
        // 可以有实例方法
        Animal.prototype.run = function () {
            console.log("not implements");
        };
        return Animal;
    }());
    var Dog = /** @class */ (function (_super) {
        __extends(Dog, _super);
        function Dog() {
            return _super !== null && _super.apply(this, arguments) || this;
        }
        Dog.prototype.eat = function () {
            console.log("dog eat");
        };
        return Dog;
    }(Animal));
})();
