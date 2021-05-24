"use strict";
function showFullName(person) {
    return person.firstName + '_' + person.lastName;
}
var author = {
    id: 1,
    firstName: "zhang",
    lastName: "zhiwei"
};
console.log(showFullName(author));
var searchString = function (source, subString) {
    return source.search(subString) > -1;
};
