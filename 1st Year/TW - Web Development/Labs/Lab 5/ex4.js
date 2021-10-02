Array.prototype.myMap = function (callbackFunction) {
    const array = this;
    let newArray = [];
    for (var i = 0; i < array.length; i++) 
    { 
        newArray[i] = multiplicator(array[i]); 
    }
    return newArray;
}

function multiplicator(element) {
    return 2 * element;
}

console.log([1, 2, 3].map(multiplicator)); // [2,4,6]
console.log([1, 2, 3].myMap(multiplicator)); // [2,4,6]