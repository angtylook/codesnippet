"use strict";
(function () {
    // add 变量名
    // (x:string, y:string)=>number  函数类型
    // function(x:string, y:string):number // 函数
    var add = function (x, y) {
        return parseInt(x) + parseInt(y);
    };
    console.log(add("1", "2"));
    // 可选参数 lastName
    // 默认参数 firstName
    function getFullName(firstName, lastName) {
        if (firstName === void 0) { firstName = "独孤"; }
        if (lastName) {
            return firstName + " " + lastName;
        }
        else {
            return firstName;
        }
    }
    console.log(getFullName());
    console.log(getFullName("诸葛"));
    console.log(getFullName("诸葛", "孔光"));
    // 不定参数
    // 不定参数要放在最后
    function showMessage(str) {
        var args = [];
        for (var _i = 1; _i < arguments.length; _i++) {
            args[_i - 1] = arguments[_i];
        }
        console.log(str);
        console.log(args);
        console.log(args.join("-"));
    }
    showMessage("a", "b", "c", "d");
    // 重载函数实现
    function concat(x, y) {
        if (typeof x === "string" && typeof y === "string") {
            return x + y;
        }
        else if (typeof x === "number" && typeof y === "number") {
            return x + y;
        }
        return "";
    }
    console.log(concat("zzw", "hcl"));
    console.log(concat(56, 78));
})();
