"use strict";
(function () {
    function getArr(value, count) {
        var arr = [];
        for (var i = 0; i < count; i++) {
            arr.push(value);
        }
        return arr;
    }
    console.log(getArr(1, 3));
    function getArr1(value, count) {
        var arr = [];
        for (var i = 0; i < count; i++) {
            arr.push(value);
        }
        return arr;
    }
    console.log(getArr1("aa", 3));
    // 泛型函数
    function getArrGen(value, count) {
        var arr = [];
        for (var i = 0; i < count; i++) {
            arr.push(value);
        }
        return arr;
    }
    console.log(getArrGen(101, 8));
    console.log(getArrGen("hcl", 8));
    function getPair(k, v) {
        return [k, v];
    }
    var pair = getPair("count", 100);
    console.log(pair);
    // 泛型类
})();
