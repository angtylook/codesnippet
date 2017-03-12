// array and it's length
var arr = [1, 2, 3.14, 'Hello', null, true]
console.log(arr.length)
// index access
for(i = 0; i < arr.length; ++i) {
  console.log(arr[i])
}
// search of
console.log(arr.indexOf('Hello'))

// slice/subarray
arr.slice(0,3)   // from 0 to 3
arr.slice(3)     // from 3 to end
arr.slice()      // copy all elements
//operate on back
var new_length = arr.push('a','b')
var back_b = arr.pop()
//operate on begin
new_length = arr.unshift('a', 'b')
var begin_a = arr.shift()
// order
arr.sort()
arr.reverse()


