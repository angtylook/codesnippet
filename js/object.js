console.log(Object.keys(Date))
console.log('length' in Date)

var o1 = {P1: 123};
var o2 = Object.create(o1, {
    p2: { value: "abc", enumerable: true}
});

for(p in o2) {
    console.info(p);
}
console.log(Object.keys(o2), o2.p2)

function inheritedPropertyNames(obj) {
    var props = {};
    while (obj) {
        Object.getOwnPropertyNames(obj).forEach(function (p) {
            props[p] = true;
        });
        obj = Object.getPrototypeOf(obj);
    }
    return Object.getOwnPropertyNames(props);
}

console.log(inheritedPropertyNames(Date))
