// to number
console.log(Number(324))
console.log(Number('324'))
console.log(Number('324abc'))
console.log(Number(''))
console.log(Number(true))
console.log(Number(false))
console.log(Number(undefined))
console.log(Number(null))
console.log(Number({a: 1}))
console.log(Number([1, 2, 3]))
console.log(Number([5]))
console.log(Number({
  valueOf: function() {
    return 2;
  },
  toString: function() {
    return 3;
  }
}))

// to string
console.log(String({a: 1}))
console.log(String([1, 2, 3]))

    var obj = {
  valueOf: function() {
    console.log('valueof');
    return {};
  },
  toString: function() {
    console.log('toString');
    return {};
  }
};
// String(obj)

// to boolean
console.log(Boolean(undefined))
console.log(Boolean(null))
console.log(Boolean(0))
console.log(Boolean(NaN))
console.log(Boolean(''))
console.log(Boolean({}))
console.log(Boolean([]))
console.log(Boolean(new Boolean(false)))
